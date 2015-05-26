// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

// not supported in gcc
// #pragma once

// alternative to pragma once
// - complie time is the same as compilers which
//   support #pragma once
// this is to prevent recursive inclusion of
// this header
#ifndef EMC_Stdafx_H_
#define EMC_Stdafx_H_

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <memory>
#include <algorithm>
#include <thread>
#include "EmcSettings.h"

// NAMESPACES
using std::vector;

// TYPE DEFINITIONS
typedef std::shared_ptr<vector<char>>	SharedAudioData;
typedef std::unique_ptr<vector<double>> UniqueDataSet;
typedef std::shared_ptr<vector<double>> SharedDataSet;
typedef vector<double>::iterator		DataSetIterator;

#endif /* ! EMC_Stdafx_H_ */
