#include "../../Core/stdafx.h"
#include "LinearAnalyzer.h"

#ifndef EMC_IntensityAnalyzer_H_
#define EMC_IntensityAnalyzer_H_

class IntensityAnalyzer : public LinearAnalyzer
{
public:
	IntensityAnalyzer(int lower_bound, int upper_bound, int resolution);
	std::string ConvertToBits(const double data_to_convert[], int noise_floor);
};

#endif
