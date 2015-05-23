#include "Processor.h"

void Processor::ProcessSignal(UniqueDataSet& spectral_data)
{
	// Lambda: Filters the data set consecutively. Results are non-unique.
	auto apply_filter = [&spectral_data](Filter filter)
	{
		filter.ApplyFilter(spectral_data);
	};

	std::for_each(filter_queue_.front(), filter_queue_.back(), apply_filter);

	// Lambda: Applies the analysis to the data after the filters are done. Results are unique.
	auto analyze_each = [&spectral_data](BaseAnalyzer analyzer)
	{
		// Need to figure out how to properly copy the data set over so we don't overwrite anything
		//UniqueDataSet filtered_data;
		//std::copy(spectral_data, filtered_data, spectral_data->size());

		analyzer.Analyze(spectral_data);
	};
	std::for_each(analyzer_queue_.front(), analyzer_queue_.back(), analyze_each);
}

void Processor::Push(BaseAnalyzer* analyzer)
{
	analyzer_queue_.push(analyzer);
}

void Processor::Push(Filter* filter)
{
	filter_queue_.push(filter);
}