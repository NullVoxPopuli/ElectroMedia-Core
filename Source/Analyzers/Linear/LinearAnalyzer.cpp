#include "../Core/stdafx.h"
#include "LinearAnalyzer.h"

LinearAnalyzer::LinearAnalyzer(int lower_bound, int upper_bound, int resolution)
	: BaseAnalyzer(lower_bound, upper_bound, resolution)
{
}

void LinearAnalyzer::Analyze(SharedAudioData audio_data)
{
	SharedDataSet pre_process_data = SharedDataSet();
	vector<char>::const_iterator window_origin = audio_data->begin();

	// Loop through everything
	while (window_origin + Settings.window_size_ < audio_data->end())
	{
		vector<double> windowed_subvector(window_origin, window_origin + Settings.window_size_);
		pre_process_data = std::make_shared<vector<double>>(windowed_subvector);
		window_origin += Settings.window_shift_amount_;

		LinearAnalysis(pre_process_data);
	}
}

void LinearAnalyzer::LinearAnalysis(SharedDataSet pre_process_data)
{
}