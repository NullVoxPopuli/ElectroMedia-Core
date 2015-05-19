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
	if (JsonString("mode").Equals("write"))
	{
		Settings.emc_mode_ = EMC_Mode::Decode;
	}

	Settings.song_filename_ = JsonString("filename");
	Settings.noise_floor_percentage_ = JsonInt("noise_floor_amplitude");
	Settings.window_size_ = JsonInt("window_size");
	Settings.window_shift_amount_ = JsonInt("window_shift_size");
	Settings.maximum_frequency_accounted_ = JsonDouble("max_frequency");

	// Decode Endianness
	if (JsonString("endianness").Equals("little"))
	{
		Settings.endianness_of_output_ = Endianness::LittleEndian;
	}
}

vector< std::shared_ptr<Analyzer*> >* SettingsBuilder::GetAnalyzers()
{
	vector < std::shared_ptr<Analyzer*> > analyzers;

	//auto it = decoded_json_["Analyzers"].begin();
	//
	//// Each loop corresponds to a subnode in the "algorithms" node
	//while (it != decoded_json_["Analyzers"].end())
	//{
	////	analyzers.push_back(std::make_shared<Analyzer*>( _analyzerFactory.Create((*it)["type"].asString()) ));
	//	std::string something;
	//}
	//
	return &analyzers;
}