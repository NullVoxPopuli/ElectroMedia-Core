// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <memory>
#include <algorithm>
#include "EmcSettings.h"
#include "boost\function\function0.hpp"

// NAMESPACES
using std::vector;

// TYPE DEFINITIONS
typedef std::shared_ptr<vector<char>>	SharedAudioData;
typedef std::unique_ptr<vector<double>> UniqueDataSet;
typedef std::shared_ptr<vector<double>> SharedDataSet;
typedef vector<double>::iterator		DataSetIterator;