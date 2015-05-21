#include "../Core/stdafx.h"
#include "../Core/CoreMath.h"
#include "../Core/NoteNames.h"
#include "PatternAnalyzer.h"

#ifndef EMC_TimeSignatureAnalyzer_H_
#define EMC_TimeSignatureAnalyzer_H_

class TimeSignatureAnalyzer : public PatternAnalyzer
{
public:
	TimeSignatureAnalyzer(int lower_bound, int upper_bound, int resolution);
};

#endif