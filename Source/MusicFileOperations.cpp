#include "stdafx.h"
#include "MusicFileOperations.h"

void MusicFileOperations::ConvertMP3ToARF(ConfigurationHandler& configHandler)
{
	// ==== The following can be replaced by passing in an ArduinoReadableFileWriter, which has the directory and nameWithoutExtension
	// ==== ------------------------------------------------------------------------------------------------------------------------------
    // filename stuff
	auto fullArgument = configHandler.GetFilename();
    auto extensionLocation = fullArgument.find(".");

    // Protection for noninclusion of extension
    if (extensionLocation > fullArgument.size())
    {
        extensionLocation = fullArgument.size();
    }

    // Specific filename strings
    auto nameWithoutExtension = std::string(fullArgument.begin(), extensionLocation + fullArgument.begin());
	auto arfilename = (configHandler.GetDirectory() + nameWithoutExtension + AR_FILE_EXTENSION);
	std::unique_ptr<ArduinoReadableFileWriter> arfile(new ArduinoReadableFileWriter((char*)arfilename.c_str()));
	
	configHandler.InitializeAnalyzer(*arfile);
	arfile->SetMode(EMC_Output_Mode::Text);
	// ==== ------------------------------------------------------------------------------------------------------------------------------

    // Process the MP3 File
    auto returnCode = decodeMusic(configHandler.GetDirectory(), nameWithoutExtension);
    if (returnCode != 1)
    {
        std::cerr << "Exiting program with code " << returnCode;
        return;
    }

    // Process the raw data file and put the data into fulldata
    auto dataFromFile = std::make_shared<vector<char>>();
    long filesize = CaptureFileData(nameWithoutExtension, dataFromFile);
    auto sweeps = -1;

    // preProcessData is an empty integer array that is used to receive data via memcpy.
    // It is rewritten in every loop, whereas dataFromFile is constant.
    DataSet preProcessData = DataSet();
    vector<char>::const_iterator first;
    vector<char>::const_iterator last;

    // FFT variables
    auto workingDoubleArray_ = (double*)fftw_malloc(sizeof(double) * WINDOW_SIZE);
    auto complexResults = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * WINDOW_SIZE);
    auto new_plan = fftw_plan_dft_r2c_1d(WINDOW_SIZE, workingDoubleArray_, complexResults, FFTW_MEASURE);

    CoreMath::Debug("Converting \"" + nameWithoutExtension + "\" to Arduino Readable File");
    while (((++sweeps)*WINDOW_SHIFT_AMOUNT + WINDOW_SIZE) < dataFromFile->size())
    {
        // Copy out the data from the AudioFileData source into a DataSet
        first = dataFromFile->begin() + sweeps*WINDOW_SHIFT_AMOUNT;
        last = dataFromFile->begin() + sweeps*WINDOW_SHIFT_AMOUNT + WINDOW_SIZE;
        vector<double> windowedSubvector(first, last);
        preProcessData = std::make_shared<vector<double>>(windowedSubvector);

        // Call FFT
        auto dataFromFFT = PrepareAndExecuteFFT(preProcessData, new_plan, workingDoubleArray_, complexResults);
        arfile->Write(dataFromFFT);
    }
    CoreMath::Debug("Process complete.");
    
    // Cleanup
    fftw_destroy_plan(new_plan);
    fftw_free(workingDoubleArray_);
    fftw_free(complexResults);
    fftw_cleanup();
    arfile->Close();
}

void MusicFileOperations::ReadArFile(ConfigurationHandler& configHandler)
{
    auto fullArgument = configHandler.GetFilename();
    auto extensionLocation = fullArgument.find(".");

    // Protection for noninclusion of extension
    if (extensionLocation > fullArgument.size())
    {
        extensionLocation = fullArgument.size();
    }

    auto nameWithoutExtension = std::string(fullArgument.begin(), fullArgument.begin() + extensionLocation);
    auto arFileName = configHandler.GetDirectory() + nameWithoutExtension + AR_FILE_EXTENSION;

    std::ifstream visualizationFile(arFileName);
    if (visualizationFile.is_open())
    {
        std::string line;
        auto start = std::chrono::high_resolution_clock::now();
        while (std::getline(visualizationFile, line))
        {
            std::cerr << line << "\n";
            std::this_thread::sleep_until(start + std::chrono::microseconds(45000));
            start = std::chrono::high_resolution_clock::now();
            //while (std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count() < 46447);
        }
    }
}

void MusicFileOperations::CopyVectorToPointerArray(DataSet& vectorIn, double* arrayOut)
{
    auto elements = 0;
    auto dataSetIterator = vectorIn->begin();

	while (dataSetIterator != vectorIn->end() && elements++ < vectorIn->size())
    {
		arrayOut[elements] = *dataSetIterator;
		++dataSetIterator;
    }
}

// long = obtainDataFromFile(char*, int*)
// ---
// Reads a file generated by FFMPEG into memory. The data array (in integers)
// is returned via dataOut and the length of the file is returned as a long
//
// This is, unfortunately, separated from obtainDataFromFile because we need
// a way to accurately determine the filesize in order to initialize a data
// array of the correct size. I will look into a way of combining these,
// but right now this is the only way to do it
//
// Performance: O(n)
long MusicFileOperations::CaptureFileData(std::string songName, AudioFileData& waveformDataPoints)
{
    // Read the file indicated by Filename argument
	std::ifstream dataFileIn_((songName + EMC_FILE_EXTENSION).c_str(), std::ios::binary);

    long counted_ = 0;
    while (dataFileIn_)
    {
        // Get the next line from the FFTW file
        char c;
        dataFileIn_.get(c);

        // If it exists, push it into the dataOut array
        if (dataFileIn_)
        {
            waveformDataPoints->push_back(double(c));
            counted_++;
        }
    }

    // Close the file and then return the filesize
    dataFileIn_.close();
    return counted_;
}

// fftw_complex* =  startFFT (double*, int)
// ---
// Interface with the FFTW FOSS library. Indirectly performs the Fast Fourier
// Transform to the data set of length (int)
DataSet MusicFileOperations::ExecuteFastFourierTransform(DataSet& data, fftw_plan& fft_plan, double* workingDoubleArray_, fftw_complex* complexResults)
{
    // Allocate memory for the fftw_complex array and working double*
    // Generate a plan for FFTW to execute
    memcpy(workingDoubleArray_, &data->at(0), data->size() * sizeof(double));
    // Execute the plan
    fftw_execute(fft_plan);

   // std::ofstream fftResultsFile("Results.csv");
    vector<double> resultsVector;
    resultsVector.reserve(180);
    auto dataOut = std::make_shared<vector<double>>(resultsVector);

    auto frequency = 0.0;
    for(int i=0; i < 180; i++)
    {
        frequency = double(sqrt(complexResults[i][0] * complexResults[i][0] + complexResults[i][1] * complexResults[i][1]));
        dataOut->push_back( frequency );
      //  fftResultsFile << (BOUNDARY_CONVERSION_SCALAR*i - BOUNDARY_CONVERSION_OFFSET) << "," << frequency << endl;
    }


  //  fftResultsFile.close();
    return dataOut;
}

// normalize(double*, int)
// ---
// Takes an array of (int) doubles as the data set, iterates through to find the max
// value, and then normalizes the original data set based on that maximum.
//
// Performance: O(n)
void MusicFileOperations::Normalize(DataSet& data)
{
    auto maxValue = *std::max_element(data->begin(), data->end());

    std::for_each(data->begin(), data->end(), [maxValue](double& x){ x /= maxValue; });
}

// double = hanningMultiplier(int, int)
// ---
// Returns an offset cosine wave of (int) width at a specific index
double MusicFileOperations::GetHanningMultiplier(int indexOfHanningFunction)
{
    return 0.5 * (1 - cos(2*PI * indexOfHanningFunction / (WINDOW_SIZE-1)) );
}

// applyHanningWindow(int*, double*, int)
// ---
// Takes an array of (int) points in the time domain (int) and applies a Hanning Window
// of specified width. The result is returned through the double* dataOut argument.
// Immediately normalizes the data after the hanning window is applied.
//
// Performance: O(n)
void MusicFileOperations::ApplyHanningWindow(DataSet& data)
{
    auto index = int(0);
    for (DataSetIterator it = data->begin(); it != data->end(); ++it)
    {
        *it = double(*it * GetHanningMultiplier(index++));
    }

    Normalize(data);
}

// double* = prepareAndExecuteFFT(const int*)
// ---
// Execute the FFT, convert the results from the complex frequency domain to the
// frequency-vs-time spectral domain and then save the results into a debug file.
DataSet MusicFileOperations::PrepareAndExecuteFFT(DataSet& data, fftw_plan& fft_plan, double* workingDoubleArray_, fftw_complex* complexResults)
{
	auto maxFrequency = CoreMath::ConvertFrequencyToInt(MAXIMUM_FREQUENCY_ACCOUNTED);

    // Execute the FFT
    ApplyHanningWindow(data);
    return ExecuteFastFourierTransform(data,fft_plan,workingDoubleArray_,complexResults);
}