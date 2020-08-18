cmake_minimum_required(VERSION 2.8)
 
PROJECT(DCM2MHD)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
 
FIND_PACKAGE(ITK REQUIRED)
INCLUDE(${ITK_USE_FILE})

add_executable(dcm2mhd    dcm2mhd.cxx)
add_executable(dcm2volume dcm2volume.cxx)
 
if(VTK_LIBRARIES)
  target_link_libraries(dcm2mhd ${VTK_LIBRARIES})
else()
  target_link_libraries(dcm2mhd vtkHybrid vtkWidgets)
endif()

IF(ITK_LIBRARIES)
TARGET_LINK_LIBRARIES(dcm2mhd ${ITK_LIBRARIES})
TARGET_LINK_LIBRARIES(dcm2volume ${ITK_LIBRARIES})
ENDIF()
