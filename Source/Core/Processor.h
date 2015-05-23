#include "stdafx.h"
#include <queue>
#include <algorithm>
#include "..\Analyzers\Base\BaseAnalyzer.h"
#include "..\Filters\Base\Filter.h"

class Processor
{
	std::queue<BaseAnalyzer*> analyzer_queue_;
	std::queue<Filter*> filter_queue_;

public:
	Processor() { }
	void ProcessSignal(UniqueDataSet& spectral_data);

	void Push(Filter* filter);
	void Push(BaseAnalyzer* analyzer);
};