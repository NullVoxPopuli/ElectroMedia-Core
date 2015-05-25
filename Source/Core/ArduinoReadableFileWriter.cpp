#include "stdafx.h"
#include "ArduinoReadableFileWriter.h"

// ArduinoReadableFileWriter Constructor
// ---
// Initialize our Arduino-Readable-file stream
ArduinoReadableFileWriter::ArduinoReadableFileWriter()
	: arf_stream_(Settings.song_filename_)
{
}

// ArduinoReadableFileWriter Destructor
// ---
// If we have stuff to dealloc, do it here
ArduinoReadableFileWriter::~ArduinoReadableFileWriter()
{
    // For safety, check to see if the user closed the stream. If not, close it
	if (arf_stream_.is_open())
	{
		Close();
	}
}

// bool = isTextWritable()
// ---
// Checks to see that the arf_stream_ is open and that mode_ == MODE_TEXT.
bool ArduinoReadableFileWriter::IsTextWritable()
{
    if(!arf_stream_.is_open())
    {
        CoreMath::Debug("arf_stream_ is not initialized -- cannot write strings to an unopen file!");
        return false;
    }

    if(Settings.output_mode_ != EMC_Output_Mode::Text)
    {
        CoreMath::Debug("arf_stream_ cannot write a string while not in Text Mode!");
        return false;
    }

    return true;
}

// write(std::string)
// ---
// Writes a single line of text to the output file if and only if the mode is set to
// MODE_TEXT. This function is ignored when writing a *.arf
void ArduinoReadableFileWriter::Write(std::string string_to_write)
{
    if(IsTextWritable())
    {
		ArduinoReadableFileWriter::arf_stream_ << string_to_write.c_str() << "\n";
    }
}

// write(int)
// ---
// Writes a single line of text to the output file if and only if the mode is set to
// MODE_TEXT. This function is ignored when writing a *.arf
void ArduinoReadableFileWriter::Write(int int_to_write)
{
    if(IsTextWritable())
    {
		ArduinoReadableFileWriter::arf_stream_ << int_to_write << "\n";
    }
}

// write(double*)
// ---
// Deciphers the data and transforms it into byte format; writes bytes to the output file
// [WIP]
void ArduinoReadableFileWriter::Write(SharedDataSet& data_to_write)
{
    if(!arf_stream_.is_open())
    {
        CoreMath::Debug("arf_stream_ is not initialized -- cannot write data to an unopen file!");
        return;
    }

    switch(Settings.output_mode_)
    {
        // Text mode is meant to be human-readable and is used for debug purposes
	case(EMC_Output_Mode::Text):
		//WriteDoubleInTextMode(data_to_write); TODO
        break;
	
        // Regular Arduino Mode uses 16 output pins
	case(EMC_Output_Mode::ArduinoReadableFile):
        break;
	
	case(EMC_Output_Mode::Binary):
		break;
	
    default:
        CoreMath::Debug("ArduinoReadableFileWriter writer cannot write as it is in an undefined mode!");
    }
}

// close()
// ---
// Close the output file. Not a destructor!
void ArduinoReadableFileWriter::Close()
{
    ArduinoReadableFileWriter::arf_stream_.close();
}