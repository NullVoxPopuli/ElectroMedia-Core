#include "stdafx.h"
#include "SettingsBuilder.h"

SettingsBuilder::SettingsBuilder(std::string configuration_file_directory, std::string configuration_file_name)
	: configuration_directory_(configuration_file_directory),
	  configuration_filename_(configuration_file_name)
{
}

// Load in the JSON Configuration file at the specified path
void SettingsBuilder::Load()
{	
	std::ifstream in(configuration_directory_ + configuration_filename_);
	Json::Reader reader;
	Json::Value decoded_json;
	reader.parse(in, decoded_json);

	// Decode "mode"
	if (ConfigString("mode").Equals("write"))
	{
		Settings.emc_mode_ = EMC_Mode::Decode;
	}

	Settings.application_root_ = configuration_directory_;

	Settings.song_filename_ = ConfigString("filename");
	Settings.noise_floor_percentage_ = ConfigInt("noise_floor_amplitude");
	Settings.window_size_ = ConfigInt("window_size");
	Settings.window_shift_amount_ = ConfigInt("window_shift_size");
	Settings.maximum_frequency_accounted_ = ConfigDouble("max_frequency");

	// Decode Endianness
	if (ConfigString("endianness").Equals("little"))
	{
		Settings.endianness_of_output_ = Endianness::LittleEndian;
	}
}

SettingsBuilder::AnalyzerCollection* SettingsBuilder::CreateAnalyzers()
{
	std::ifstream in(configuration_directory_ + configuration_filename_);
	Json::Reader reader;
	Json::Value decoded_json;
	reader.parse(in, decoded_json);

	auto analyzers = new SettingsBuilder::AnalyzerCollection;

	auto it = decoded_json["Analyzers"].begin();
	
	// Each loop corresponds to a subnode in the "algorithms" node
	while (it != decoded_json["Analyzers"].end())
	{
		auto new_analyzer = std::make_shared<BaseAnalyzer*>(AnalyzerFactory::Create((*it)["type"].asString()));
		analyzers->push_back(new_analyzer);
	}
	
	return analyzers;
}