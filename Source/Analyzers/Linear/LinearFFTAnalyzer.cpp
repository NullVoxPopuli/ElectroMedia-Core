#include "LinearFFTAnalyzer.h"

LinearFFTAnalyzer::LinearFFTAnalyzer(int lower_bound, int upper_bound, int resolution)
	: LinearAnalyzer(lower_bound, upper_bound, resolution)
{
	working_array_ = (double*)fftw_malloc(sizeof(double) * Settings.window_size_);
	complex_results_ = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * Settings.window_size_);
	fft_plan_ = fftw_plan_dft_r2c_1d(Settings.window_size_, working_array_, complex_results_, FFTW_MEASURE);
}

LinearFFTAnalyzer::~LinearFFTAnalyzer()
{
	fftw_destroy_plan(fft_plan_);
	fftw_free(working_array_);
	fftw_free(complex_results_);
	fftw_cleanup();
}

void LinearFFTAnalyzer::LinearAnalysis(SharedDataSet pre_process_data)
{
	// Normalize the pre_process_data
	auto spectral_data = ExecuteFastFourierTransform(pre_process_data, fft_plan_, working_array_, complex_results_);
}

SharedDataSet LinearFFTAnalyzer::ExecuteFastFourierTransform(SharedDataSet& data, fftw_plan& fft_plan, double* working_array, fftw_complex* complex_results)
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