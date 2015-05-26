#include "../../Core/stdafx.h"
#include "../Linear/HillEffectAnalyzer.h"
#include "../Pattern/FeatureExtractionAnalyzer.h"
#include "../Linear/IntensityAnalyzer.h"
#include "BaseAnalyzer.h"

#ifndef EMC_AnalyzerFactory_H_
#define EMC_AnalyzerFactory_H_

class AnalyzerFactory
{
public:
	static BaseAnalyzer* Create(std::string type);
	static BaseAnalyzer* Create(std::string type, int lowerBound, int upperBound);
	static BaseAnalyzer* Create(std::string type, int lowerBound, int upperBound, int resolution);
	static BaseAnalyzer* Create(std::string type, double lowerFrequency, double upperFrequency);
	static BaseAnalyzer* Create(std::string type, double lowerFrequency, double upperFrequency, int resolution);

private:
	static void Validate(int& lowerBound, int& upperBound, int& resolution);
};

#endif
