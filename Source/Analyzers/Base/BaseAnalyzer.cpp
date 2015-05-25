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

void BaseAnalyzer::Analyze(SharedAudioData audio_data)
{
}

void BaseAnalyzer::Analyze(UniqueDataSet& audio_data)
{
}