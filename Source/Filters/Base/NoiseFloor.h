#include "..\Core\stdafx.h"
#include "Filter.h"

class NoiseFloor : public Filter
{
	double CalculateNoiseFloor(UniqueDataSet& data);

public:
	void ApplyFilter(UniqueDataSet& data) override;
};