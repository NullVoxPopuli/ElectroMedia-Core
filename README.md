#ElectroMedia Core (EMC)
[![Join the chat at https://gitter.im/etkirsch/ElectroMedia-Core](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/etkirsch/ElectroMedia-Core?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

## Pre-Alpha Release 1
Pre-Alpha Release 1 is the first in a series of releases that will lead to Alpha Release 1 in August. This release is primarily concerned with incorporating GoogleTest, improving performance, and adding more functionality to the Analyzer suite

## Capabilities of EMC
ElectroMedia is a software package which is capable of taking audio files (MP3 only at the moment, more to come) and running any number of analyses in C++. Out of the box, it will be able to determine chord sequences, sound intensity, note patterns (such as the signature "wub-wub" audio modulation which characterizes Dubstep) and much more.

## Compiling

### Windows
Download [the dependencies suite for EMC-Core](http://www.neuravion.io/file.axd?file=/EMC/EMC%20Windows%20Dependencies.zip "EMC-Core Dependencies") and unzip to the application root (which contains /Source, .gitignore, etc.). Open up the solution, then build.

### Linux
First, acquire dependencies necessary for the project to build:

    $(package_manager_install_command ) libavcodec-dev libavformat-dev libswscale-dev libjsoncpp-dev

After running Make, G++ will output an executable, "EMC"

## Contributing
* Fork ElectroMedia-Core to a repository of your own
* Submit Pull Requests when you're ready for us to review your 
* Send me (@etkirsch) a message on here if you have any questions and I'll do my best to help you out

## Changelog

#####Update 0.2.2
 * Added Linux build support using Gcc. Please see Compiling section above.
 * Fixed Repository so that it doesn't include binaries or any code from other projects.
 * Fixed VC++ issues conflicting with G++ makefiles and new directory structure.

#####Update 0.2.1
* Added Filters, Processors, and Analyzers. Filters are applied in sequence to the data set specific to a Processor; the filtered data is then sent to each Analyzer independently.
* Removed Boost, as functionality is now deprecated. It will be reimplemented at a later point.
* Finished redoing as much of the iterator handling with lambdas and STL Algorithms.
* Changed some typdefs which were not consistent with the nomenclature.
* Moved all FFTW functionality into its own Analyzer (LinearFFTAnalyzer). This works in sequence the same way as ArduinoReadableFileWriter did a long time ago.
