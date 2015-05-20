#include "../Core/stdafx.h"
#include "../Core/Analyzer.h"
#include "../Core/CoreMath.h"
#include "../Core/NoteNames.h"

#ifndef EMC_FeatureExtractionAnalyzer_H_
#define EMC_FeatureExtractionAnalyzer_H_

class FeatureExtractionAnalyzer : public Analyzer
{
public:
	FeatureExtractionAnalyzer(int lower_bound, int upper_bound, int resolution);
	std::string ConvertToBits(UniqueDataSet& processed_data, int noise_floor);

private:
	NoteName ToNote(double frequency);
};

#endif