# our compiler
CC=g++
# options for the compiler
CFLAGS= -Wall -std=gnu++11
# link libraries
LDFlags= -LDependencies/json -ljsoncpp -lavcodec -lavformat -lswscale -lavutil

# Boost, etc
# - Boost is not installed to /usr/include by default
DEPENDENCIES=-I boost_1_49_0/boost


# output program name
EXECUTABLE=EMC

#########
# Folders
#########
CORE_FOLDER=Source/Core
ANALYZERS_FOLDER=Source/Analyzers
# Aliases
CF=$(CORE_FOLDER)/
AF=$(ANALYZERS_FOLDER)/
AFB=$(AF)Base/
AFL=$(AF)Linear/
AFP=$(AF)Pattern/

# where our main function is
MAIN=$(CORE_FOLDER)/EntryPoint.cpp

###########
# Analyzers
###########
BASE_ANALYZERS=\
	$(AFB)AnalyzerFactory.cpp \
	$(AFB)AnalyzerFactory.h \
	$(AFB)BaseAnalyzer.cpp \
	$(AFB)BaseAnalyzer.h

LINEAR_ANALYZERS=\
	$(AFL)HillEffectAnalyzer.cpp \
	$(AFL)HillEffectAnalyzer.h \
	$(AFL)IntensityAnalyzer.cpp \
	$(AFL)IntensityAnalyzer.h \
	$(AFL)LinearAnalyzer.cpp \
	$(AFL)LinearAnalyzer.h

PATTERN_ANALYZERS=\
	$(CF)stdafx.h \
	$(AFP)FeatureExtractionAnalyzer.cpp \
	$(AFP)FeatureExtractionAnalyzer.h \
	$(AFP)MeterAnalyzer.cpp \
	$(AFP)MeterAnalyzer.h \
	$(AFP)PatternAnalyzer.cpp \
	$(AFP)PatternAnalyzer.h \
	$(AFP)TimeSignatureAnalyzer.cpp \
	$(AFP)TimeSignatureAnalyzer.h

######
# Core
######
CORE=\
	$(CF)ArduinoReadableFileWriter.cpp \
	$(CF)ConfigurationFileFields.h \
	$(CF)CoreMath.cpp \
	$(CF)CoreMath.h \
	$(CF)EmcCore.cpp \
	$(CF)EmcCore.h \
	$(CF)EMCModes.h \
	$(CF)EmcSettings.h \
	$(MAIN) \
	$(CF)FFmpegReturnValues.h \
	$(CF)fftw3.h \
	$(CF)MP3toData.cpp \
	$(CF)MP3toData.h \
	$(CF)MusicFileOperations.cpp \
	$(CF)MusicFileOperations.h \
	$(CF)NoteNames.h \
	$(CF)resource.h \
	$(CF)SettingsBuilder.cpp \
	$(CF)SettingsBuilder.h \
	$(CF)stdafx.cpp \
	$(CF)stdafx.h


###########
# Aggregate
###########
# Compiled, but not quite object files
CORE_OBJECTS=core.o

BASE_ANALYZER_OBJECTS=\
	BaseAnalyzer.o \
	AnalyzerFactory.o

LINEAR_ANALYZER_OBJECTS=\
	HillEffectAnalyzer.o \
	IntensityAnalyzer.o \
	LinearAnalyzer.o

PATTERN_ANALYZER_OBJECTS=\
	FeatureExtractionAnalyzer.o \
	MeterAnalyzer.o \
	PatternAnalyzer.o \
	TimeSignatureAnalyzer.o


All_TARGETS=\
	Core \
	Analyzer_Pattern \
	Analyzer_Linear \
	Analyzer_Base

ALL_OBJECTS=\
	$(CORE_OBJECTS) \
	$(BASE_ANALYZER_OBJECTS) \
	$(LINEAR_ANALYZER_OBJECTS) \
	$(PATTERN_ANALYZER_OBJECTS)


#######################
# COMPILE!
# https://xkcd.com/303/
#######################

# alias
all: $(ALL_TARGETS)
	$(CC) \
	$(CORE) \
	$(BASE_ANALYZERS) \
	$(LINEAR_ANALYZERS) \
	$(PATTERN_ANALYZERS) \
	$(DEPENDENCIES) \
	$(LDFlags) \
	$(CFLAGS) \
	-o $(EXECUTABLE)

# Clean Up!
clean:
	rm -f *.o
	echo Clean done
