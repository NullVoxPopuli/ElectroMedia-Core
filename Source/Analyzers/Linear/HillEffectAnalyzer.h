#include "../../Core/stdafx.h"
#include "LinearAnalyzer.h"

#ifndef EMC_HillEffectAnalyzer_H_
#define EMC_HillEffectAnalyzer_H_

class HillEffectAnalyzer : public LinearAnalyzer
{
public:
	HillEffectAnalyzer(int lower_bound, int upper_bound, int resolution);
};

#endif
