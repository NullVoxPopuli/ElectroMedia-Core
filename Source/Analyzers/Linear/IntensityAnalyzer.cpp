#include "../Core/stdafx.h"
#include "IntensityAnalyzer.h"

IntensityAnalyzer::IntensityAnalyzer(int lower_bound, int upper_bound, int resolution)
	: LinearAnalyzer(lower_bound, upper_bound, resolution)
{

}

// todo: replace with LinearAnalysis()
std::string IntensityAnalyzer::ConvertToBits(const double data_to_convert[], int noise_floor)
{
	return "IIIIIIII";
}