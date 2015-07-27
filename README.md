# raytracer

After clone do:
    
    git submodule init
    git submodule update

... to init all the submodules.

# Compiling

The build system is based on [CMake](http://www.cmake.org/).

    cmake -P KRAL/build.cmake

This will show you all the available compile targets. To compile first you need
to generate the project and then compile it:

    cmake -DN=1 -DG=1 -P KRAL/build.cmake
    cmake -DN=1 -DC=1 -P KRAL/build.cmake

The first command generated the first target (N=1) and the second line starts
the compilation process.

