#include "NoiseFloor.h"

double NoiseFloor::CalculateNoiseFloor()//UniqueDataSet& data)
{

	return 0;
}

// Possibly factor out 
void NoiseFloor::ApplyFilter(UniqueDataSet data)
{
	auto noise_floor = CalculateNoiseFloor();// data&);

	// Easy lambda for application of the noise floor
	auto apply_noise_floor = [noise_floor](double& frequency)
	{
		frequency = (frequency < noise_floor) ? 0 : frequency;
	};

	// Apply the noise floor
	std::for_each(data->begin(), data->end(), apply_noise_floor);
}
