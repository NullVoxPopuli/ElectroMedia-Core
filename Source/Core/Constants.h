#include "stdafx.h"

#ifndef EMC_Constants_H_
#define EMC_Constants_H_

// CONSTANT FLAGS
const bool DEBUG_ENABLED = true;

// ARDUINO SPECIFICS
const int ARDUINO_UNO_IO_PINS = 16;
const int ARDUINO_MEGA_IO_PINS = 54;

namespace Constants
{
	const std::string kConfigurationFileName = "config.json";
	const std::string kEmcFileExtension = ".emc";
	const std::string kArFileExtension = ".arf";

	const int	 kSongEndingPaddingSize = 8;
	const double kBoundaryConversionScalar = 10.91;
	const double kBoundaryConversionOffset = 7.33;
};

#endif