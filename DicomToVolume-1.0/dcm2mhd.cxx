/*=========================================================================
   Program:   Dcm2Mhd
   FileName:  dcm2mhd.cxx
   Author:	  Lichun Zhang from Soochow University
   Date:      2017/05/28
   describe:  Demonstrates how to read a series of dicom images and convert to mhd file
   Copyright: 2016-Now MIPAV Lab. All rights reserved.
=========================================================================*/
//
// some standard vtk headers
#include <vtkSmartPointer.h>

#include <vtkMetaImageWriter.h>
#include <itkImage.h>
#include <itkGDCMImageIO.h>
#include <itkImageSeriesReader.h>
#include <itkImageSeriesWriter.h>
#include <string>
#include <itkGDCMSeriesFileNames.h>
#include <itkNumericSeriesFileNames.h>
#include <itkImageToVTKImageFilter.h>
using std::string;

bool Dcm2Mhd(const char* input, const char* output = nullptr) {
	const unsigned int InputDimension = 3;
	typedef unsigned short
		PixelType;
	typedef itk::Image< PixelType, InputDimension >
		InputImageType;
	typedef itk::ImageSeriesReader< InputImageType >
		ReaderType;

	////////////////////////////////////////////////
	// Read the input series
	string folder = input;

	itk::GDCMSeriesFileNames::Pointer inputNames = itk::GDCMSeriesFileNames::New();
	inputNames->SetInputDirectory( folder );
	std::cout << "Reading input directory: " << folder << std::endl;
	const ReaderType::FileNamesContainer & filenames = inputNames->GetInputFileNames();

	itk::GDCMImageIO::Pointer gdcmIO = itk::GDCMImageIO::New();
	ReaderType::Pointer reader = ReaderType::New();
	reader->SetImageIO( gdcmIO );
	reader->SetFileNames( filenames );
	std::cout << "SetFilenames successfully\n";
	for (auto f : filenames) { std::cout << f << std::endl; }

	try {
		reader->Update();
	}
	catch (itk::ExceptionObject &excp) {
		std::cerr << "Exception thrown while reading the series" << std::endl;
		std::cerr << excp << std::endl;
		return false;
	}

	typedef itk::Image<unsigned short, 3> VisualizingImageType;
	typedef itk::ImageToVTKImageFilter<VisualizingImageType> itkVtkConverter;
	itkVtkConverter::Pointer conv=itkVtkConverter::New();
	conv->SetInput(reader->GetOutput());
	string out_mhd, out_raw;
  out_mhd = string(output)+".mhd";
	out_raw = string(output)+".raw";

	vtkMetaImageWriter * writer = vtkMetaImageWriter::New();

	writer->SetInputData(conv->GetOutput());
	writer->SetFileName(out_mhd.c_str());
	writer->SetRAWFileName(out_raw.c_str());
	std::cout << "Writing now...\n";
	writer->Write();
	std::cout << "Done\n";
	return true;
}



int main(int argc, char* argv[]) {
	// Verify input arguments
	if ( argc != 2 ) {
		std::cout << "Usage: " << argv[0]	<< " FolderName" << std::endl;
		return EXIT_FAILURE;
	}
	// Execute
	if (Dcm2Mhd(argv[1], "convert_test")) return EXIT_SUCCESS;
	else return EXIT_FAILURE;
}
