#include "stdafx.h"
#include "fftw3.h"
#include "CoreMath.h"
#include "MP3toData.h"
#include "Constants.h"
#include <chrono>

#ifndef EMC_MusicFileOperations_H_
#define EMC_MusicFileOperations_H_ 

class MusicFileOperations
{
public:
	typedef std::shared_ptr<std::vector<char>> MP3FileData;
	static MP3FileData GetDataFromMP3();
	static SpectralDataCollection PrepareAndExecuteFFT(SpectralDataCollection& data, fftw_plan& fft_plan, double* working_array,
		fftw_complex* complex_fft_results);
	
private:
	// FFT PreProcessing
	static void CopyVectorToPointerArray(SpectralDataCollection& vector_in, double* array_out);
	static double GetHanningMultiplier(int index_at);
	static void Normalize(SpectralDataCollection& data);
	static void ApplyHanningWindow(SpectralDataCollection& data);

	// Fast Fourier Transform
	static SpectralDataCollection ExecuteFastFourierTransform(SpectralDataCollection& data, fftw_plan& fft_plan, double* working_array,
		fftw_complex* complex_fft_results);

	static long CaptureFileData(AudioFileData& waveform_data);
};

#endif
