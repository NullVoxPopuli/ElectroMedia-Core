#include "stdafx.h"
#include "MusicFileOperations.h"

MusicFileOperations::MP3FileData MusicFileOperations::GetDataFromMP3()
{
	auto returnCode = DecodeMusic();

	if (returnCode != FFmpegReturnValue::Success)
	{
		std::cerr << "Exiting program with code " << returnCode;
		throw;
	}

	// Process the raw data file and put the data into fulldata
	auto data_from_file = std::make_shared<vector<char>>();
	
	MusicFileOperations::CaptureFileData(data_from_file);

	return data_from_file;
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
long MusicFileOperations::CaptureFileData(SharedAudioData& waveform_data)
{
    // Read the file indicated by Filename argument
	std::ifstream data_file_stream((Settings.song_filename_ + Constants::kEmcFileExtension).c_str(), std::ios::binary);

    long counted_points = 0;
	while (data_file_stream)
    {
        // Get the next line from the FFTW file
        char c;
		data_file_stream.get(c);

        // If it exists, push it into the dataOut array
		if (data_file_stream)
        {
			waveform_data->push_back(c);
			++counted_points;
        }
    }

    // Close the file and then return the filesize
	data_file_stream.close();
	return counted_points;
}

// fftw_complex* =  startFFT (double*, int)
// ---
// Interface with the FFTW FOSS library. Indirectly performs the Fast Fourier
// Transform to the data set of length (int)
SharedDataSet MusicFileOperations::ExecuteFastFourierTransform(SharedDataSet& data, fftw_plan& fft_plan, double* working_array, fftw_complex* complex_results)
{
    // Allocate memory for the fftw_complex array and working double*
    // Generate a plan for FFTW to execute
	memcpy(working_array, &data->at(0), data->size() * sizeof(double));
    
	// Execute the plan
    fftw_execute(fft_plan);

    vector<double> results_vector;
	auto data_out = std::make_shared<vector<double>>(results_vector);

	auto push_real_results = [data_out](fftw_complex complex_result)
	{
		auto frequency = double(sqrt(pow(complex_result[0], 2) + pow(complex_result[1], 2)));
		data_out->push_back(frequency);
	};

	// TODO: Possibly change complex_results to a vector? Need to look into FFTW stuff
	std::for_each(complex_results, complex_results + 180, push_real_results); // 180 here is a hardcoded length

	return data_out;
}

// normalize(double*, int)
// ---
// Takes an array of (int) doubles as the data set, iterates through to find the max
// value, and then normalizes the original data set based on that maximum.
//
// Performance: O(n)
void MusicFileOperations::Normalize(SharedDataSet& data)
{
    auto max_value = *std::max_element(data->begin(), data->end());

	std::for_each(data->begin(), data->end(), [max_value](double& x){ x /= max_value; });
}

// double* = prepareAndExecuteFFT(const int*)
// ---
// Execute the FFT, convert the results from the complex frequency domain to the
// frequency-vs-time spectral domain and then save the results into a debug file.
SharedDataSet MusicFileOperations::PrepareAndExecuteFFT(SharedDataSet& data, fftw_plan& fft_plan, double* working_array, fftw_complex* complex_results)
{
	auto maxFrequency = CoreMath::ConvertFrequencyToInt(Settings.maximum_frequency_accounted_);

    // Execute the FFT
    //ApplyHanningWindow(data);
	return ExecuteFastFourierTransform(data, fft_plan, working_array, complex_results);
}