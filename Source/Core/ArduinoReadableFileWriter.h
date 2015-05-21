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
	
    // Sets the mode of the ARFWriter (Text or Byte) according to the enum writeMode
    void SetMode(EMC_Output_Mode newMode);

    // Overloaded write options; only double* variant is used to write legitimate ARFs
    void Write(std::string stringToWrite);
    void Write(int intToWrite);
	void Write(SpectralDataCollection& dataToWrite);
    void Close();

private:
    // Internal function for dealing with whether or not to write as BYTE or std::string
    bool IsTextWritable();
	void WriteDoubleInTextMode(SpectralDataCollection& dataToWrite);
	int CalculateDynamicNoiseFloor(SpectralDataCollection& data);

    // Private variables
    std::ofstream arf_stream_;
};

#endif