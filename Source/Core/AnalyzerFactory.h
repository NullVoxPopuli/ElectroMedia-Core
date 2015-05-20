#include "stdafx.h"
#include "Analyzer.h"
#include "..\Analyzers\HillEffectAnalyzer.h"
#include "..\Analyzers\FeatureExtractionAnalyzer.h"
#include "..\Analyzers\IntensityAnalyzer.h"

#ifndef EMC_AnalyzerFactory_H_
#define EMC_AnalyzerFactory_H_

class AnalyzerFactory
{
public:
	static Analyzer* Create(std::string type);
	static Analyzer* Create(std::string type, int lowerBound, int upperBound);
	static Analyzer* Create(std::string type, int lowerBound, int upperBound, int resolution);
	static Analyzer* Create(std::string type, double lowerFrequency, double upperFrequency);
	static Analyzer* Create(std::string type, double lowerFrequency, double upperFrequency, int resolution);

private: 
	static void Validate(int& lowerBound, int& upperBound, int& resolution);
};

#endif