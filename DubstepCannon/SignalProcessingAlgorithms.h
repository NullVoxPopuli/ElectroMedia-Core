#include "stdafx.h"

class SignalProcessingAlgorithm
{
public:
    // Constructors and Destructors
    SignalProcessingAlgorithm();
    ~SignalProcessingAlgorithm();

    // Define lower and upper bounds (as indices) for this processor
    void setBounds(const int lower, const int upper);

    // Heart and soul of the Signal Processing Algorithm. 
    virtual std::string convertToBits(const double* dataToConvert, int noiseFloor);

protected:

    // The following are part of convertToBits, which should only be modified in extreme
    // cases. The program flow is as follows
    // 1. preProcessForConversion -- does any necessary preProcessing to the data
    // 2. evaluateNoiseFloor -- scrapes out any values below noise floor
    // 3. evaluateBits -- determines which bits are high or low and generates a bool[].
    //	  - NOTE: The program flow ends here and returns the bool[] if the ARFWriter 
    //		is not in TEXT mode.
    // 4. ___EndianConvert -- Called according to endianness as indicated in the config
    //		file, this converts a bool[] into a string
    virtual double* preProcessForConversion(const double* dataToConvert);
    virtual double* applyNoiseFloor(const double* preProcesedData, int noiseFloor);
    virtual bool* evaluateBits(const double* processedData, const int bitLength);
    virtual std::string bigEndianConvert(const bool* processedBits);
    virtual std::string littleEndianConvert(const bool* processedBits);

    // These are used within the convertToBits methods
    int lowerBound_, upperBound_, bits_;

private:
    std::string checkBit(bool bitToCheck);
};

//=====================
// SUBCLASSES BELOW...
//=====================

// INTENSITY
// ---
// Watches Intensity of a specific frequency range; returns 1 bit
class SPAIntensity : public SignalProcessingAlgorithm
{
public:
    std::string convertToBits(const double* dataToConvert, int noiseFloor);
};

// WATCH FREQUENCY
// ---
// Watches only an exact frequency; returns the value in binary
class SPAWatchFrequency : public SignalProcessingAlgorithm
{
public:
    std::string convertToBits(const double* dataToConvert, int noiseFloor);
    void setWatchFrequency(double watchFrequency);

private:
    // The index of the frequency that this SPA should watch
    int watchBound_;
};

// PERCUSSION
// ---
// Watches for percussion and does specific things for them. I want this to be configurable.
// For instance, on HATS make all bits go to a value of 1, or etc.
class SPAPercussion : public SignalProcessingAlgorithm
{
public:
    std::string convertToBits(const double* dataToConvert, int noiseFloor);

private:
    // If setHighOnHat is true, the entire range goes high when the hat sounds
    bool setHighOnHat;
};

// HILL EFFECT
// ---
// Turns all bits lower than the maximum amplitude within a range to 1
// Useful for climbing frequency effects as in "Contact" by Daft Punk
class SPAHillEffect : public SignalProcessingAlgorithm
{
protected:
    bool* evaluateBits(const double* processedData, const int bitLength);
};