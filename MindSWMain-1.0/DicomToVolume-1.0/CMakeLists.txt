cmake_minimum_required(VERSION 2.8)

PROJECT(DicomToVolume)

FIND_PACKAGE(ITK REQUIRED)
INCLUDE(${ITK_USE_FILE})

add_executable(dcm2volume dcm2volume.cxx)

TARGET_LINK_LIBRARIES(dcm2volume ${ITK_LIBRARIES})


install(TARGETS dcm2volume DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
