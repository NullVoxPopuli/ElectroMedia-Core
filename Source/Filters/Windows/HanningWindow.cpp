#include "HanningWindow.h"

void HanningWindow::ApplyFilter(UniqueDataSet& data)
{
	auto index = (unsigned int)0;
	auto apply_hanning = [&index](double& data_point)
	{
		data_point *= CoreMath::GetHanningMultiplier(index++);
	};

	std::for_each(data->begin(), data->end(), apply_hanning);

	//Normalize(data); // A new filter?
}