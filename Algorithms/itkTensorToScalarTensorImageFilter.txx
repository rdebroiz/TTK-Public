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
#ifndef _itk_TensorToScalarTensorImageFilter_txx_
#define _itk_TensorToScalarTensorImageFilter_txx_
#endif

#include "itkTensorToScalarTensorImageFilter.h"
#include <itkImageRegionIterator.h>
#include <itkImageRegionConstIterator.h>

namespace itk
{

  template <class TInputImage, class TOutputImage>
  TensorToScalarTensorImageFilter<TInputImage, TOutputImage>
  ::TensorToScalarTensorImageFilter()
  {
    m_TensorToScalarFunction = 0;
  }


  template <class TInputImage, class TOutputImage>
  void
  TensorToScalarTensorImageFilter<TInputImage, TOutputImage>
  ::BeforeThreadedGenerateData()
  {
    if (m_TensorToScalarFunction.IsNull())
    {
      itkExceptionMacro ( << "Tensor to scalar function is not set");
    }
  }
  
  template <class TInputImage, class TOutputImage>
  void
  TensorToScalarTensorImageFilter<TInputImage, TOutputImage>
  ::ThreadedGenerateData ( const OutputImageRegionType &outputRegionForThread, ThreadIdType threadId )
  {
    typedef ImageRegionIterator<OutputImageType>      IteratorOutputType;
    typedef ImageRegionConstIterator<InputImageType>  IteratorInputType;

    unsigned long numPixels = outputRegionForThread.GetNumberOfPixels();
    unsigned long step = numPixels/100;
    unsigned long progress = 0;
	
    IteratorOutputType itOut(this->GetOutput(), outputRegionForThread);
    IteratorInputType  itIn(this->GetInput(), outputRegionForThread);

    if( threadId==0 )
      this->UpdateProgress (0.0);
    
    while(!itOut.IsAtEnd())
    {
      if( this->GetAbortGenerateData() )
        throw itk::ProcessAborted(__FILE__,__LINE__);
      
      
      OutputPixelType out = static_cast<OutputPixelType>( 0.0 ); // be careful, overload in MedINRIA

      InputPixelType T = itIn.Get();

      if ( !T.IsZero() )
        out = m_TensorToScalarFunction->ComputeScalar( T );

      if( threadId==0 && step>0)
      {        
        if( (progress%step)==0 )
          this->UpdateProgress ( double(progress)/double(numPixels) );
      }

      
      itOut.Set (out);
      ++progress;
      ++itOut;
      ++itIn;
      
    }

    if( threadId==0 )
      this->UpdateProgress (1.0);
    
  }
  
  

} // end of namespace
