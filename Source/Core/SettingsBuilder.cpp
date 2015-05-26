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
	if (ConfigString("EMC Operation").Equals("write"))
	{
		Settings.emc_mode_ = EMC_Mode::Decode;
	}

	Settings.application_root_ = configuration_directory_;

	Settings.song_filename_ = ConfigString("Filename");
	Settings.noise_floor_percentage_ = ConfigInt("Noise Foor Amplitude");
	Settings.window_size_ = ConfigInt("Window Size");
	Settings.window_shift_amount_ = ConfigInt("Window Shift Displacement");
	Settings.maximum_frequency_accounted_ = ConfigDouble("Maximum Frequency");

	// Decode Endianness
	if (ConfigString("Endianness").Equals("little"))
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
		auto new_analyzer = std::make_shared<BaseAnalyzer*>(AnalyzerFactory::Create((*it++)["type"].asString()));
		analyzers->push_back(new_analyzer);
	}

	return analyzers;
}
