#ElectroMedia Core (EMC)
[![Join the chat at https://gitter.im/etkirsch/ElectroMedia-Core](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/etkirsch/ElectroMedia-Core?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

## Pre-Alpha Release 1
Pre-Alpha Release 1 is the first in a series of releases that will lead to Alpha Release 1 in August. This release is primarily concerned with incorporating GoogleTest, improving performance, and adding more functionality to the Analyzer suite

## Capabilities of EMC
ElectroMedia is a software package which is capable of taking audio files (MP3 only at the moment, more to come) and running any number of analyses in C++. Out of the box, it will be able to determine chord sequences, sound intensity, note patterns (such as the signature "wub-wub" audio modulation which characterizes Dubstep) and much more.

## Contributing
* Fork EMC-Core to a repository of your own
* Download [Boost Version 1.58.0](http://www.boost.org/) or later and unzip to your /Program Files (x86)/ directory
* Download [the dependencies suite for EMC-Core](http://www.neuravion.io/file.axd?file=/EMC/EMC%20Requirements.zip "EMC-Core Dependencies") and unzip to the folder containing your executable

## Changelog
* **v0.2.0.2** -- More changes to directory structure with some improvements to the Solution Explorer view.
* **v0.2.0.1** -- Changed directory structure to make a bit more sense.
* **v0.2.0.0** -- **Pre-Alpha Release 1**. Completed transition to the new EmcCore structure. FFT analysis is still part of the MusicFileOperations static class, but the Analyzers are in charge of their own behavior now. Goals now are to flesh out the Analyzer behavior to make the system more robust. Part of this Pre-Alpha Release is to also incorporate the GoogleTest framework. I will also be working heavily on performance enhancements (stack vs. heap memory for song data and the like, algorithm performance, et cetera).
* **v0.1.9.7** -- Fleshed out more with the analyzers. Going to postpone the Analyzer threading until Pre Alpha 2 (v0.3.0.0). All that remains at the moment for Pre Alpha 1 (v0.2.0.0) is to make ConvertMp3ToArf to return a vector of spectral data and have the Analyzers do their thing in Analyzer::Analyze.
* **v0.1.9.6** -- Changed the way that EMC handles Settings with config.json. Now, EMC has a global singleton "Settings" which is loaded into memory by the "SettingsBuilder" (formerly ConfigurationHandler). Further, major improvements have been added to the structure of EMC in preparation for the addition of the Analyzer package.
* **v0.1.9.5** -- Major improvements to nomenclature. Changed many variable names and header guards to fit Google's C++ Style Guide. Also fixed up header inclusions and removed vestigial FrequencyMaximum class.
* **v0.1.9.4** -- Added enumerated Return values for FFmpeg function, added some QoL improvements to ConfigurationHandler and CoreMath for dealing with file extensions and the like. Started tearing apart the ConvertMP3ToARF stuff. Moved ReadARF to EmcCore.
* **v0.1.9.3** -- Removed FrequencyRangeProfile completely in response to Issue #7 on Github.
* **v0.1.9.2** -- Added validation to AnalyzerFactory in response to Issue #6 "AnalyzerFactory should be fleshed out more (e.g. Validation)"