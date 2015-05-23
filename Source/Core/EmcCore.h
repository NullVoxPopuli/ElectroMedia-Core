#include "stdafx.h"
#include "SettingsBuilder.h"
#include "CoreMath.h"
#include "MusicFileOperations.h"
#include <algorithm>
#include <thread>

#ifndef EMC_EmcCore_H_
#define EMC_EmcCore_H_

class EmcCore
{
	// TODO: Replace with Processors. Slated for 0.2.2.0
	SettingsBuilder::AnalyzerCollection* analyzer_collection_;

public:
	EmcCore(std::string configuration_file_path);
	~EmcCore();

	void Run();
	void StartAnalyses();
	void AddAnalyzer(BaseAnalyzer* analyzer);

protected:
	void Decode();
	void Read();
};

#endif