#include "stdafx.h"
#include "CoreMath.h"
#include "EmcCore.h"
#include <stdlib.h>


// Signed 16-bit PCM Little-Endian
// Command line

int main(int argc, char *argv[])
{
	// Get the Base Path of the EMC executable
	// char base_path[255] = realpath(base_path, argv[0]);
	auto configuration_file_path = CoreMath::GetPath(argv[0]);

	// Start up EMC and run it
	auto emc = new EmcCore(configuration_file_path);
	emc->Run();

	return 1;
}
