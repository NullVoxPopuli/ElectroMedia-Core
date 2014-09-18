// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "CommonOperations.h"

// CONSTANT FLAGS
const bool DEBUG_ENABLED = true;

// CONSTANTS
const int WINDOW_SIZE = 8192;
const int WINDOW_SHIFT_AMOUNT = 2048;
const int SONG_ENDING_PAD = 8;
const int NOISE_FLOOR = 50;
const int NOISE_FLOOR_PCT = 30;
const int NUMBER_OF_PINS_DEDICATED_TO_LCD = 8;
const int MAXIMUM_NUMBER_OF_FREQUENCY_RANGES = 4;

const double TEMPORAL_SHIFT_WIDTH = 0.0938;
const double BOUNDARY_CONVERSION_SCALAR = 10.91;
const double BOUNDARY_CONVERSION_OFFSET = 7.33;
const double PI = 3.1415926;
const double MAXIMUM_FREQUENCY_ACCOUNTED = 2000;

const std::string DECODED_FILE_NAME = "test.txt";

// ARDUINO SPECIFICS
const int ARDUINO_UNO_IO_PINS = 16;
const int ARDUINO_MEGA_IO_PINS = 54;

// Enumerated Lists
const enum adjustmentType { ADJUSTMENT_TYPE_CHANGE_UPPER, ADJUSTMENT_TYPE_CHANGE_LOWER, ADJUSTMENT_TYPE_CENTER };

// NAMESPACES
using std::cout;
using std::endl;