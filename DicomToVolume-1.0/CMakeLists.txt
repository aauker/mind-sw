cmake_minimum_required(VERSION 2.8)

PROJECT(DCM2MHD)

FIND_PACKAGE(ITK REQUIRED)
INCLUDE(${ITK_USE_FILE})

add_executable(dcm2volume dcm2volume.cxx)

IF(ITK_LIBRARIES)
    TARGET_LINK_LIBRARIES(dcm2volume ${ITK_LIBRARIES})
ENDIF()
