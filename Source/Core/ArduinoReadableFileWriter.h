#include "stdafx.h"
#include "Constants.h"
#include "CoreMath.h"
#include "EMCModes.h"

#ifndef EMC_ArduinoReadableFileWriter_H_
#define EMC_ArduinoReadableFileWriter_H_

class ArduinoReadableFileWriter
{
public:
    // Constructors / Destructors
	ArduinoReadableFileWriter();
    ~ArduinoReadableFileWriter();

    // Overloaded write options; only double* variant is used to write legitimate ARFs
    void Write(std::string stringToWrite);
    void Write(int intToWrite);
	void Write(SharedDataSet& dataToWrite);
    void Close();

private:
    // Internal function for dealing with whether or not to write as BYTE or std::string
    bool IsTextWritable();

    // Private variables
    std::ofstream arf_stream_;
};

#endif