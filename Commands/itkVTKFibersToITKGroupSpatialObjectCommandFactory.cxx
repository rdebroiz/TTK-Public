/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkVTKFibersToITKGroupSpatialObjectCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkVTKFibersToITKGroupSpatialObjectCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  VTKFibersToITKGroupSpatialObjectCommandFactory::VTKFibersToITKGroupSpatialObjectCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkVTKFibersToITKGroupSpatialObjectCommand",
			   "Convert a vtkPolyData fiber representation to an ITK GroupSpatialObject file",
			   1,
			   CreateObjectFunction<VTKFibersToITKGroupSpatialObjectCommand>::New());
  }
  
  VTKFibersToITKGroupSpatialObjectCommandFactory::~VTKFibersToITKGroupSpatialObjectCommandFactory()
  {
  }
  
  const char* 
  VTKFibersToITKGroupSpatialObjectCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  VTKFibersToITKGroupSpatialObjectCommandFactory::GetDescription(void) const
  {
    return "Convert a vtkPolyData fiber representation to an ITK GroupSpatialObject file";
  }
  
} // end namespace itk
