#include "../Core/stdafx.h"
#include "../Analyzers/Linear/LinearAnalyzer.h"

#ifndef	EMC_LinearFFTAnalyzer_H_
#define EMC_LinearFFTAnalyzer_H_

class LinearFFTAnalyzer : public LinearAnalyzer
{
	fftw_plan_s* fft_plan_;
	double* working_array_;
	fftw_complex* complex_results_;

public:
	LinearFFTAnalyzer(int lower_bound, int upper_bound, int resolution);
	~LinearFFTAnalyzer();

	void LinearAnalysis(SharedDataSet spectral_data) override;

protected:
	SharedDataSet ExecuteFastFourierTransform(SharedDataSet& data, fftw_plan& fft_plan, double* working_array,
		fftw_complex* complex_fft_results);
};

#endif