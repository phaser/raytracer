add_target (__DEFAULT
    KRAL_PATH       "${CMAKE_CURRENT_LIST_DIR}/KRAL/" 
    PACKAGE_DIRS    "${CMAKE_CURRENT_LIST_DIR}/KRAL_libs"  
    PROJECTS_ROOT   "${CMAKE_CURRENT_LIST_DIR}/projects"
    PLATFORM        osx
    PROJECT_DIR     ${CMAKE_CURRENT_LIST_DIR}/raytracer
    BUILD_DIR       raytracer
    PROJECT_TYPE    "Unix Makefiles"
    BUILD_TYPE      debug
)

add_target (raytracer-osx
    INHERIT         __DEFAULT
    PLATFORM        osx
    PROJECT_TYPE    Xcode
    CUSTOM_ARGS
        "-Wdev"
        " -DRUNTIME_DIR=debug"
        " -DIOS_SDK_PATH=\"/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs\""
        " -DTARGETSDK=MacOSX10.9.sdk"
        " -DCMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD=c++11"
        " -DCMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY=libc++" 
        " -DTESTS=True"
    COMPILER_ARGS_DEBUG
        "-g -O0 -Wall -DPLATFORM_OSX -std=c++11 -stdlib=libc++" 
    COMPILER_ARGS_RELEASE
        "-O4 -Wall -DPLATFORM_OSX -std=c++11 -stdlib=libc++"
)
