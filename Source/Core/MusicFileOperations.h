#include "stdafx.h"
#include "fftw3.h"
#include "CoreMath.h"
#include "MP3toData.h"
#include "Constants.h"

#ifndef EMC_MusicFileOperations_H_
#define EMC_MusicFileOperations_H_ 

class MusicFileOperations
{
public:
	typedef std::shared_ptr<std::vector<char>> MP3FileData;
	static MP3FileData GetDataFromMP3();
	
private:
	// FFT PreProcessing
	static void Normalize(SharedDataSet& data);
	static long CaptureFileData(SharedAudioData& waveform_data);
};

#endif
