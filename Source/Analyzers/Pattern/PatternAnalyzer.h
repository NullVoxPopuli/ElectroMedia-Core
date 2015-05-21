#include "../Core/stdafx.h"
#include "../Analyzers/Base/BaseAnalyzer.h"

#ifndef	EMC_PatternAnalyzer_H_
#define EMC_PatternAnalyzer_H_

class PatternAnalyzer : public BaseAnalyzer
{
public:
	PatternAnalyzer(int lower_bound, int upper_bound, int resolution);
	void Analyze(AudioFileData audio_data) override;
};

#endif