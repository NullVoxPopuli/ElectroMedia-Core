#include "../Core/stdafx.h"
#include "LinearAnalyzer.h"

LinearAnalyzer::LinearAnalyzer(int lower_bound, int upper_bound, int resolution)
	: BaseAnalyzer(lower_bound, upper_bound, resolution)
{ 
}

void LinearAnalyzer::Analyze(AudioFileData audio_data)
{
	// Settings
	auto window_size = Settings.window_size_;
	auto window_shift = Settings.window_shift_amount_;

	SpectralDataCollection pre_process_data = SpectralDataCollection();
	vector<char>::const_iterator first, last;
	auto sweeps = (unsigned int)0;

	// For FFTW 
	auto working_double_array = (double*)fftw_malloc(sizeof(double) * window_size);
	auto complex_results = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * window_size);
	auto new_plan = fftw_plan_dft_r2c_1d(window_size, working_double_array, complex_results, FFTW_MEASURE);

	// Loop through everything
	while (((sweeps++)*window_shift + window_size) < audio_data->size())
	{
		first = audio_data->begin() + sweeps * window_shift;
		last = audio_data->begin() + sweeps * window_shift + window_size;

		vector<double> windowed_subvector(first, last);
		pre_process_data = std::make_shared<vector<double>>(windowed_subvector);

		auto spectral_data = MusicFileOperations::PrepareAndExecuteFFT(pre_process_data, new_plan, working_double_array, complex_results);
		LinearAnalysis(spectral_data);
	}

	fftw_destroy_plan(new_plan);
	fftw_free(working_double_array);
	fftw_free(complex_results);
	fftw_cleanup();
}

void LinearAnalyzer::LinearAnalysis(SpectralDataCollection spectral_data)
{
	// Flesh out later!
}