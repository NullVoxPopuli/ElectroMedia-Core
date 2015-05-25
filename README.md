#ElectroMedia Core (EMC)
[![Join the chat at https://gitter.im/etkirsch/ElectroMedia-Core](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/etkirsch/ElectroMedia-Core?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

## Pre-Alpha Release 1
Pre-Alpha Release 1 is the first in a series of releases that will lead to Alpha Release 1 in August. This release is primarily concerned with incorporating GoogleTest, improving performance, and adding more functionality to the Analyzer suite

## Capabilities of EMC
ElectroMedia is a software package which is capable of taking audio files (MP3 only at the moment, more to come) and running any number of analyses in C++. Out of the box, it will be able to determine chord sequences, sound intensity, note patterns (such as the signature "wub-wub" audio modulation which characterizes Dubstep) and much more.

## Contributing
* Fork EMC-Core to a repository of your own
* Download [the dependencies suite for EMC-Core](http://www.neuravion.io/file.axd?file=/EMC/EMC%20Requirements.zip "EMC-Core Dependencies") and unzip to the folder containing your executable

## Changelog
#####Update 0.2.1
* Added Filters, Processors, and Analyzers. Filters are applied in sequence to the data set specific to a Processor; the filtered data is then sent to each Analyzer independently.
* Removed Boost, as functionality is now deprecated. It will be reimplemented at a later point.
* Finished redoing as much of the iterator handling with lambdas and STL Algorithms.
* Changed some typdefs which were not consistent with the nomenclature. 
* Moved all FFTW functionality into its own Analyzer (LinearFFTAnalyzer). This works in sequence the same way as ArduinoReadableFileWriter did a long time ago.
