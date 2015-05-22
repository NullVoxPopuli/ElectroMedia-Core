#include "..\Core\stdafx.h"
#include "Filter.h"

class NoiseFloor : public Filter
{
	double CalculateNoiseFloor();// UniqueDataSe& data);

public:
	void ApplyFilter(UniqueDataSet data) override;
};