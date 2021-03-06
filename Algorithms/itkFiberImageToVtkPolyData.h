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
#ifndef _itk_FiberImageToVtkPolyData_h_
#define _itk_FiberImageToVtkPolyData_h_

#include <itkProcessObject.h>
#include <vtkPolyData.h>
#include <itkTensor.h>
#include <itkImage.h>
#include <itkAffineTransform.h>

namespace itk
{
  /*! \class FiberImageToVtkPolyData
    \ingroup TensorToolKit
    Transforms a fiber image into a vtkPolyData.
   */

  template <class TInputImage>
    class ITK_EXPORT FiberImageToVtkPolyData: public ProcessObject
  {

  public:

    typedef FiberImageToVtkPolyData  Self;
    typedef ProcessObject            Superclass;
    typedef SmartPointer<Self>       Pointer;
    typedef SmartPointer<const Self> ConstPointer;

    itkNewMacro  (Self);
    itkTypeMacro (FiberImageToVtkPolyData, ProcessObject);

    typedef TInputImage                        InputImageType;
    typedef typename InputImageType::PixelType FiberType;
    typedef typename FiberType::PointType      PointType;
    typedef typename FiberType::TensorType     TensorType;
    typedef typename PointType::VectorType     VectorType;
    typedef typename FiberType::FiberPoint     FiberPointType;
    typedef typename FiberType::FiberPointListType  FiberPointListType;
    typedef typename FiberType::ScalarType     ScalarType;
    typedef vtkPolyData                        OutputType;

      using Superclass::SetInput;
    itkSetObjectMacro (Input, InputImageType);
    itkGetObjectMacro (Input, InputImageType);

    OutputType *GetOutput (void) const;
    
    void Update (void);

  protected:
    FiberImageToVtkPolyData();
    ~FiberImageToVtkPolyData();

    
  private:
    FiberImageToVtkPolyData (const Self&);
    void operator=(const Self&);

    typename InputImageType::Pointer m_Input;
    OutputType*                      m_Output;
  };
    

} // end of namespace itk


#ifndef ITK_MANUAL_INSTANTIATION
#include "itkFiberImageToVtkPolyData.txx"
#endif

#endif
