#include "stdafx.h"
#include "Constants.h"
#include "CoreMath.h"
#include "EMCModes.h"

#ifndef ARFWriterDefinition
#define ARFWriterDefinition

class ArduinoReadableFileWriter
{
public:
    // Constructors / Destructors
    ArduinoReadableFileWriter(char nameOfARF[]);
    ~ArduinoReadableFileWriter();
	
    // Sets the mode of the ARFWriter (Text or Byte) according to the enum writeMode
    void SetMode(EMC_Output_Mode newMode);

    // Overloaded write options; only double* variant is used to write legitimate ARFs
    void Write(std::string stringToWrite);
    void Write(int intToWrite);
    void Write(DataSet& dataToWrite);
    void Close();

private:
    // Internal function for dealing with whether or not to write as BYTE or std::string
    bool IsTextWritable();
    void WriteDoubleInTextMode(DataSet& dataToWrite);
    int CalculateDynamicNoiseFloor(DataSet& data);

    // Private variables
    std::ofstream arfStream;
	EMC_Output_Mode mode_;
	int numberOfOutputs_, dynamicNoiseFloor;
};

#endif