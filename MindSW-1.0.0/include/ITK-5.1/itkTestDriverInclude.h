/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
/*=========================================================================
 *
 *  Portions of this file are subject to the VTK Toolkit Version 3 copyright.
 *
 *  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
 *
 *  For complete copyright, license and disclaimer of warranty information
 *  please refer to the NOTICE file at the top of the ITK source tree.
 *
 *=========================================================================*/
#ifndef itkTestDriverInclude_h
#define itkTestDriverInclude_h
//
// This file is used by the TestDriver executables generated by CMake's
// create_test_sourcelist. It defines a function, ProcessArguments
// that processes the command line for the test driver prior to
// invoking the test. It also defines the RegressionTestImage function
// that is called after a test has been run by the driver.
// command line options prior to invoking the test.
//

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "itksys/Process.h"
#include "itksys/SystemTools.hxx"
#include "vnl/vnl_sample.h"

#include "itkFloatingPointExceptions.h"
#include "itkImageIOBase.h"
#include "itkIntTypes.h"
#include "itkWin32Header.h"

#define ITK_TEST_DIMENSION_MAX 6

extern int
RegressionTestImage(const char *         testImageFilename,
                    const char *         baselineImageFilename,
                    int                  reportErrors,
                    double               intensityTolerance,
                    ::itk::SizeValueType numberOfPixelsTolerance = 0,
                    unsigned int         radiusTolerance = 0,
                    bool                 verifyInputInformation = true,
                    double               coordinateTolerance = 1.0e-6,
                    double               directionTolerance = 1.0e-6);

extern int
HashTestImage(const char * testImageFilename, const std::string md5hash);


extern std::map<std::string, int>
RegressionTestBaselines(char *);

using ComparePairType = std::pair<char *, char *>;

// A structure to hold regression test parameters
using RegressionTestParameters = struct _RegressionTestParameters
{
  std::vector<ComparePairType> compareList;
  double                       intensityTolerance;
  unsigned int                 numberOfPixelsTolerance;
  unsigned int                 radiusTolerance;
  bool                         verifyInputInformation;
  double                       coordinateTolerance;
  double                       directionTolerance;
};

extern RegressionTestParameters &
GetRegressionTestParameters();


using HashPairType = std::pair<const char *, std::vector<std::string>>;

extern std::vector<HashPairType> &
GetHashTestList();

using ArgumentStringType = char **;


// Types to hold parameters that should be processed later
using ArgumentsList = std::vector<char *>;

struct ProcessedOutputType
{
  bool externalProcessMustBeCalled;

  ArgumentsList args;
  ArgumentsList add_before_libpath;
  ArgumentsList add_before_env;
  ArgumentsList add_before_env_with_sep;
};

// A structure to hold redirect output parameters
using RedirectOutputParameters = struct _RedirectOutputParameters
{
  bool        redirect;
  std::string fileName;
};

extern RedirectOutputParameters &
GetRedirectOutputParameters();

extern void
usage();

extern int
ProcessArguments(int * ac, ArgumentStringType * av, ProcessedOutputType * processedOutput = nullptr);


/// Get the PixelType and ComponentType from fileName
extern void
GetImageType(const char * fileName, itk::IOPixelEnum & pixelType, itk::IOComponentEnum & componentType);

extern int
RegressionTestImage(const char *         testImageFilename,
                    const char *         baselineImageFilename,
                    int                  reportErrors,
                    double               intensityTolerance,
                    ::itk::SizeValueType numberOfPixelsTolerance,
                    unsigned int         radiusTolerance,
                    bool                 verifyInputInformation,
                    double               coordinateTolerance,
                    double               directionTolerance);


extern int
HashTestImage(const char * testImageFilename, const std::vector<std::string> & baselineMD5Vector);

//
// Generate all of the possible baselines
// The possible baselines are generated fromn the baselineFilename using the
// following algorithm:
// 1) strip the suffix
// 2) append a digit .x
// 3) append the original suffix.
// It the file exists, increment x and continue
//
extern std::map<std::string, int>
RegressionTestBaselines(char * baselineFilename);

// Needed for explicit instantiate
//#include "itkTestingComparisonImageFilter.hxx"

#endif