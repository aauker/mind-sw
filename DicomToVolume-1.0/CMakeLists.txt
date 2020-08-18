cmake_minimum_required(VERSION 2.8)

PROJECT(DicomToVolume)

add_executable(dcm2volume dcm2volume.cxx)

target_link_libraries(dcm2volume ITK)
