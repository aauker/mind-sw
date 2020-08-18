#==========================================================================
#
#   Copyright NumFOCUS
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#          http://www.apache.org/licenses/LICENSE-2.0.txt
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#
#==========================================================================*/

#
#  Example on the use of the SigmoidImageFilter
#

import itk
from sys import argv
itk.auto_progress(2)

dim = 2
IType = itk.Image[itk.UC, dim]

reader = itk.ImageFileReader[IType].New(FileName=argv[1])
filter = itk.SigmoidImageFilter[IType, IType].New(reader,
                                                  OutputMinimum=eval(argv[3]),
                                                  OutputMaximum=eval(argv[4]),
                                                  Alpha=eval(argv[5]),
                                                  Beta=eval(argv[6]),
                                                  )
writer = itk.ImageFileWriter[IType].New(filter, FileName=argv[2])

writer.Update()
