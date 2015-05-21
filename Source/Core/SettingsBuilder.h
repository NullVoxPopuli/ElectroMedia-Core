#include "stdafx.h"	
#include "ArduinoReadableFileWriter.h"
#include "EMCModes.h"
#include "ConfigurationFileFields.h"
#include "../Analyzers/Base/AnalyzerFactory.h"
#include "../Dependencies/json/json.h"

#ifndef EMC_SettingsBuilder_H_
#define EMC_SettingsBuilder_H_

class SettingsBuilder
{
	#define ConfigString(a) decoded_json[a].asString()
	#define ConfigInt(a) decoded_json[a].asInt()
	#define ConfigDouble(a) decoded_json[a].asDouble()
	#define Equals(b) compare(b) == 0

	std::string configuration_directory_, configuration_filename_;

public:
	typedef vector< std::shared_ptr<BaseAnalyzer*> > AnalyzerCollection;

    // Constructors / Destructors
	SettingsBuilder(std::string configuration_file_directory, std::string configuration_file_name);
    ~SettingsBuilder();

	void Load();
	AnalyzerCollection* CreateAnalyzers();
};

#endif