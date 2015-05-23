#include "../Core/stdafx.h"
#include <sstream>
#include <algorithm>
#include "../Core/CoreMath.h"
#include "../Core/MusicFileOperations.h"
#include "../Core/ConfigurationFileFields.h"

#ifndef EMC_BaseAnalyzer_H_
#define EMC_BaseAnalyzer_H_

class BaseAnalyzer
{
	int lower_bound_, upper_bound_, bit_resolution_;

public:
    // Constructors and Destructors
	BaseAnalyzer();
	BaseAnalyzer(int lower_bound, int upper_bound);
	BaseAnalyzer(int lower_bound, int upper_bound, int resolution);
	BaseAnalyzer(double lower_frequency, double upper_frequency);
	BaseAnalyzer(double lower_frequency, double upper_frequency, int resolution);

	virtual void Analyze(AudioFileData audio_data);
	virtual void Analyze(UniqueDataSet& spectral_data);
};

#endif