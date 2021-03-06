# Gamma
### Generic Synthesis C++ Library


1. About
========================================
Gamma is a cross-platform, C++ library for doing generic synthesis and 
filtering of signals. It contains helpful mathematical functions, 
types, such as vectors and complex numbers, an assortment of sequence 
generators, and many other objects for signal processing tasks. 
It is oriented towards real-time sound and graphics synthesis, but is 
equally useful for non-real-time tasks.



2. Compilation Instructions
========================================
The source code can either be built into a library or directly compiled from source into an application. In the following, the base directory is where this README file is located.



2.1 Building a Library
----------------------------------------

### Make (Linux, OS X)

In most cases, simply running

	make

will build the library with automatically detected platform settings. See Makefile.config for other build options.

There are several other rules within Makefile. These are:

	make			- builds static library
	make install		- installs library into DESTDIR
	make clean		- removes binaries from build folder
	make examples/y/x.cpp	- builds and runs example source file y/x.cpp
	make test		- performs unit tests

The rule that builds examples will automatically run the executable by default. To turn this off, pass AUTORUN=0 to make. The examples rule follows standard Unix conventions so that, for instance, all the examples can be built and run by typing the command 

	make examples/*/*.cpp

Binaries are located in the directory ./build/. On OSX, the Gamma library will be linked to the pre-compiled dependent libraries in external/lib_osx. On Linux, use apt-get to install the necessary dependent libraries (see 2.3 below).


### Xcode (OS X)

1. Open project/xcode/gamma.xcodeproj
2. Build the target 'libgamma{.a, .dylib}'. The library will be in project build folder.



2.2 Compiling Direct From Source
----------------------------------------
Gamma can easily be compiled directly from source into an existing project.

Make sure to pass in the following flags to the compiler:

	-D__STDC_CONSTANT_MACROS
	-finline-functions (or -O3)
	-fpeel-loops



2.3 Dependencies
----------------------------------------
Gamma depends on PortAudio v19 and libsndfile for performing audio and sound file i/o, respectively. They are required only if using certain Gamma classes. PortAudio is required ONLY if you are using AudioIO (AudioIO.h). libsndfile is required ONLY for SoundFile i/o and playback (SoundFile.h, Player.h).

