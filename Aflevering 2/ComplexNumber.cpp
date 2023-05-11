#include "ComplexNumber.hpp"
#include <cmath>

// Override default constructor
// Set real and imaginary parts to zero
ComplexNumber::ComplexNumber()
{
   mRealPart = 0.0;
   mImaginaryPart = 0.0;
}

// Constructor that sets complex number z=x+iy
ComplexNumber::ComplexNumber(double x, double y)
{
   mRealPart = x;
   mImaginaryPart = y;
}

// Copy constructor
ComplexNumber::ComplexNumber(const ComplexNumber& z)
{
   mRealPart = z.GetRealPart();
   mImaginaryPart = z.GetImaginaryPart();
}

// Constructor that sets complex number z = real + 0i
ComplexNumber::ComplexNumber(double real)
{
   mRealPart = real;
   mImaginaryPart = 0;
}

// Method for computing the modulus of a
// complex number
double ComplexNumber::CalculateModulus() const
{
   return sqrt(mRealPart*mRealPart+
               mImaginaryPart*mImaginaryPart);
}

// Method for computing the argument of a
// complex number
double ComplexNumber::CalculateArgument() const
{
   return atan2(mImaginaryPart, mRealPart);
}

// Method for returning the real part of a
// complex number
double ComplexNumber::GetRealPart() const
{
   return mRealPart;
}

// Method for returning the imaginary part of a
// complex number
double ComplexNumber::GetImaginaryPart() const
{
   return mImaginaryPart;
}

// Friend function for returning the real part of a
// complex number
double RealPart(const ComplexNumber& z)
{
   return z.GetRealPart();
}

// Friend function for returning the imaginary part of a
// complex number
double ImaginaryPart(const ComplexNumber& z)
{
   return z.GetImaginaryPart();
}

// Method for returning the complex conjugate of a complex number
ComplexNumber ComplexNumber::CalculateConjugate() const
{
   ComplexNumber z(mRealPart, -1*mImaginaryPart); 
   return z; 
}

// Set complex number equal to conjugate
void ComplexNumber::SetConjugate()
{
   mImaginaryPart = -1.0*mImaginaryPart;
}

//nth power
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
   double modulus = CalculateModulus();
   double argument = CalculateArgument();
   double mod_of_result = pow(modulus, n);
   double arg_of_result = argument*n;
   double real_part = mod_of_result*cos(arg_of_result);
   double imag_part = mod_of_result*sin(arg_of_result);
   ComplexNumber z(real_part, imag_part); 
   return z; 
}

//Assigment operator overload
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z)
{
   mRealPart = z.mRealPart;
   mImaginaryPart = z.mImaginaryPart;
   return *this;
}

// Unary operator overload
ComplexNumber ComplexNumber::operator-() const
{
   ComplexNumber w;
   w.mRealPart = -mRealPart;
   w.mImaginaryPart = -mImaginaryPart;
   return w;
}

// Binary operator + overload
ComplexNumber ComplexNumber::operator+(const ComplexNumber& z) const
{
   ComplexNumber w;
   w.mRealPart = mRealPart + z.mRealPart;
   w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
   return w;
}

// Binary operator - overload
ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) const
{
   ComplexNumber w;
   w.mRealPart = mRealPart - z.mRealPart;
   w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart;
   return w;
}

// Binary operator * overload
ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) const
{
   ComplexNumber w;
   w.mRealPart = mRealPart*z.mRealPart - mImaginaryPart*z.mImaginaryPart;
   w.mImaginaryPart = mRealPart*z.mImaginaryPart + mImaginaryPart*z.mRealPart;
   return w;
}

// Print complex numbers
std::ostream& operator<<(std::ostream& output,const ComplexNumber& z)
{
   output << "(" << z.mRealPart << " ";
   if (z.mImaginaryPart >= 0.0)
   {
      output << "+ " << z.mImaginaryPart << "i)";
   }
   else
   {
      // Replace + with minus  
      output << "- " << -z.mImaginaryPart << "i)";
   }

   return output;
}