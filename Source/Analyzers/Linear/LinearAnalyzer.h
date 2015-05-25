#include "../Core/stdafx.h"
#include "../Analyzers/Base/BaseAnalyzer.h"

#ifndef	EMC_LinearAnalyzer_H_
#define EMC_LinearAnalyzer_H_

class LinearAnalyzer : public BaseAnalyzer
{
public:
	LinearAnalyzer(int lower_bound, int upper_bound, int resolution);

	void Analyze(SharedAudioData audio_data) override;
	virtual void LinearAnalysis(SharedDataSet spectral_data);
};

#endif