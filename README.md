# mind-sw
Mind software binaries

# Idea
Separate into `MindSWCore` which includes libraries and packages not developed by us, but on which our developement might rely, such as with the dcm2volume binary, which is included in `MindSWMain`.

To build, MindSWCore is built first and installed, then MindSWMain.  In order to add packages all one needs to do is add the subdirectory physically and in the CMakeLists file.

# Setup
Call source setup.sh

# Extras
1. Download InsightToolkit-5.1.0 from https://itk.org/download/
2. Untar
3. cd InsightToolkit-5.1.0
3. mkdir build && cd build
4. cmake ..
5. make install
6. cd DicomToVolume-1.0
7. mkdir build && cd build
8. cmake ..
9. make install

