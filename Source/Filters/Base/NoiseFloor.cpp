#include "NoiseFloor.h"
#include <cmath>

double NoiseFloor::CalculateNoiseFloor(UniqueDataSet& data)
{
	auto boltzman_constant = (long double) 1.38 * pow(10,-23);
	auto data_power = 0; // Calculate from data
	auto bandwidth = 0;	 // Calculate from data

	return boltzman_constant * data_power * bandwidth;
}

// Possibly factor out 
void NoiseFloor::ApplyFilter(UniqueDataSet& data)
{
	auto noise_floor = CalculateNoiseFloor(data);

	// Easy lambda for application of the noise floor
	auto apply_noise_floor = [noise_floor](double& frequency)
	{
		frequency = (frequency < noise_floor) ? 0 : frequency;
	};

	// Apply the noise floor
	std::for_each(data->begin(), data->end(), apply_noise_floor);
}
