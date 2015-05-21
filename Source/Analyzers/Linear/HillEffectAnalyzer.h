#include "../Core/stdafx.h"
#include "LinearAnalyzer.h"

#ifndef EMC_HillEffectAnalyzer_H_
#define EMC_HillEffectAnalyzer_H_

class HillEffectAnalyzer : public LinearAnalyzer
{
public: 
	HillEffectAnalyzer(int lower_bound, int upper_bound, int resolution);

protected:
	dynamic_bitset<> EvaluateBits(UniqueDataSet& processed_data, const int bit_length);
};

#endif