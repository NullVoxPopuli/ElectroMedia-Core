#include "../../Core/stdafx.h"
#include "../../Core/CoreMath.h"
#include "../../Core/NoteNames.h"
#include "PatternAnalyzer.h"

#ifndef EMC_MeterAnalyzer_H_
#define EMC_MeterAnalyzer_H_

class MeterAnalyzer : public PatternAnalyzer
{
public:
	MeterAnalyzer(int lower_bound, int upper_bound, int resolution);
};

#endif
