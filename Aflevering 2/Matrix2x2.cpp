#include "Matrix2x2.hpp"
#include <cassert>
//Default constructor
Matrix2x2::Matrix2x2(){
    val00 = 0;
    val01 = 0;
    val10 = 0;
    val11 = 0;
}

//Copy-constructoren
Matrix2x2::Matrix2x2(const Matrix2x2& A)
{
   val00 = A.val00;
   val01 = A.val01;
   val10 = A.val10;
   val11 = A.val11;
}

//Constructor
Matrix2x2::Matrix2x2(double a,double b,double c,double d){
    val00 = a;
    val01 = b;
    val10 = c;
    val11 = d;
}

//Determinant method
double Matrix2x2::CalcDeterminant() const
{
double res = val00*val11-val01*val10;
return res;
}

//Invese method
Matrix2x2 Matrix2x2::CalcInverse() const{
    double deter = val00*val11-val01*val10; //Might be able to use Determinant method somehow
    assert(deter != 0); //Check if inverse is well-defined
    Matrix2x2 res = Matrix2x2(val11/deter,-val01/deter,-val10/deter, val00/deter);
return res;
}

//Matrix assignment
Matrix2x2& Matrix2x2::operator=(const Matrix2x2& z){
val00 = z.Getval00();
val01 = z.Getval01();
val10 = z.Getval10();
val11 = z.Getval11();
return *this;
}

//Matrix unary operator
Matrix2x2 Matrix2x2::operator-() const{
    Matrix2x2 A =  Matrix2x2(-val00, -val01, -val10, -val11);
return A;
}

//Matrix addition
Matrix2x2 Matrix2x2::operator+(const Matrix2x2& z) const{
    Matrix2x2 A;
    A.val00 = val00 + z.val00;
    A.val01 = val01 + z.val01;
    A.val10 = val10 + z.val10;
    A.val11 = val11 + z.val11;
return A;
}

//Matrix subtraction
Matrix2x2 Matrix2x2::operator-(const Matrix2x2& z) const{
    Matrix2x2 A;
    A.val00 = val00 - z.val00;
    A.val01 = val01 - z.val01;
    A.val10 = val10 - z.val10;
    A.val11 = val11 - z.val11;
return A;
}

//Scalar multiplication
void Matrix2x2::MultScalar(double scalar){
    val00 = val00*scalar;
    val01 = val01*scalar;
    val10 = val10*scalar;
    val11 = val11*scalar;
}

//Print matrix method
void Matrix2x2::Print() const {
  std::cout << val00 << ' ' << val01 << std::endl;
  std::cout << val10 << ' ' << val11 << std::endl;
}