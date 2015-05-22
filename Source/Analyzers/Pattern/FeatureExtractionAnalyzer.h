#include "../../Core/stdafx.h"
#include "../../Core/CoreMath.h"
#include "../../Core/NoteNames.h"
#include "PatternAnalyzer.h"

#ifndef EMC_FeatureExtractionAnalyzer_H_
#define EMC_FeatureExtractionAnalyzer_H_

class FeatureExtractionAnalyzer : public PatternAnalyzer
{
public:
	FeatureExtractionAnalyzer(int lower_bound, int upper_bound, int resolution);

private:
	NoteName ToNote(double frequency);
};

#endif
