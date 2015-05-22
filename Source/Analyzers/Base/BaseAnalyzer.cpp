#include "../Core/stdafx.h"
#include "../Core/Constants.h"
#include "BaseAnalyzer.h"

// BaseAnalyzer Constructor
// ---
// ...
BaseAnalyzer::BaseAnalyzer()
	: BaseAnalyzer(0,0,1)
{ }

BaseAnalyzer::BaseAnalyzer(int lower_bound, int upper_bound)
	: BaseAnalyzer(lower_bound, upper_bound, 1)
{ }

BaseAnalyzer::BaseAnalyzer(int lower_bound, int upper_bound, int resolution)
	: lower_bound_(lower_bound),
	  upper_bound_(upper_bound),
	  bit_resolution_(resolution)
{ }

BaseAnalyzer::BaseAnalyzer(double lower_frequency, double upper_frequency)
	: BaseAnalyzer(lower_frequency, upper_frequency, 1)
{
}

BaseAnalyzer::BaseAnalyzer(double lower_frequency, double upper_frequency, int resolution)
	: bit_resolution_(resolution)
{
	lower_bound_ = CoreMath::ConvertFrequencyToInt(lower_frequency);
	upper_bound_ = CoreMath::ConvertFrequencyToInt(upper_frequency);
}

BaseAnalyzer::~BaseAnalyzer() { }

void BaseAnalyzer::Analyze(AudioFileData audio_data)
{
}

void BaseAnalyzer::ApplyNoiseFloor(UniqueDataSet& preprocessed_data, int noise_floor)
{
	// Easy lambda for application of the noise floor
	auto apply_noise_floor = [noise_floor](double& frequency)
	{
		frequency = (frequency < noise_floor) ? 0 : frequency;
	};

	// Apply the noise floor
	std::for_each(preprocessed_data->begin(), preprocessed_data->end(), apply_noise_floor);
}