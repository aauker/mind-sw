cmake_minimum_required(VERSION 3.2.2)
project(mindsw)

include_directories(InsightToolkit-5.1.0//Modules/Core/Common/include)
include_directories(InsightToolkit-5.1.0//Modules/IO/ImageBase/include)

add_subdirectory(InsightToolkit-5.1.0/)
add_subdirectory(DicomToVolume-1.0/)


