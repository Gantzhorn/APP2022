#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
#include<string>
template <class T>
class Vector
{
private:
	std::vector<T> mData; // data stored in vector
	int mSize; // size of vector
//----------------------------------------------------------------------------------------------------//
public:
    // copy constructor 
    
Vector(const Vector& otherVector);

Vector(int size);
    

//----------------------------------------------------------------------------------------------------//

//    ~Vector();

    int size() const;

    T& operator[](int i); 


	T const& operator[] (int i)const;


//----------------------------------------------------------------------------------------------------//
	// assignment operator
	//Vector& operator=(const Vector& otherVector);

    // overloading the unary - operator
	Vector operator-() const;

//----------------------------------------------------------------------------------------------------//

    // overloading the binary + operator
	Vector operator+(const Vector& v1) const;

    // overloading the binary - operator
	Vector operator-(const Vector& v1) const;

//----------------------------------------------------------------------------------------------------//

	// scalar multiplication
	Vector operator*(double a) const;

//----------------------------------------------------------------------------------------------------//
	// p-norm method
	double CalculateNorm(int p) const;

    //Get storage method
    std::vector<T> const& getStorage() const;

    //Resize method
    

};

//Copy-constructor
template <class T>
Vector<T>::Vector(const Vector& otherVector)
{
    mSize = otherVector.size();
    for (int i = 0; i < mSize; i++)
    {
        mData.push_back(otherVector.mData[i]);
    }
}

//Defualt constructor
template <class T>
Vector<T>::Vector(int size)
{
   assert(size >= 0);
   mSize = size;
   for (int i = 0; i < mSize; i++)
   {
      mData.push_back(0.0);
   }
}
/*
//Delete method
template <class T>
Vector<T>::~Vector()
{
   delete[] mData;
}
*/
//size method
template <class T>
int Vector<T>::size() const
{
    return mSize;
}

template <class T>
T& Vector<T>::operator[](int i)
{
    assert(i >= 0 && i < mSize);
    return mData[i];
}

template<class T> 
T const& Vector<T>::operator[](int i)const
{
    assert(i >= 0 && i < mSize);
    return mData[i];
}
/*
//Assignment
template<class T> 
Vector<T>& Vector<T>::operator=(const Vector& otherVector)
{
        assert(mSize == otherVector.mSize);

        for (int i = 0; i < mSize; i++)
        {
            mData[i] = otherVector.mData[i];
        }
        return *this;
}
*/
//Unary
template <class T>
Vector<T> Vector<T>::operator-() const
{
    Vector v(mSize);
    for (int i = 0; i < mSize; i++)
    {
            v[i] = -mData[i];
    }
    return v;
}

// binary + operator
template <class T>
Vector<T> Vector<T>::operator+(const Vector& v1) const
    {
        assert(mSize == v1.mSize);

        Vector v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = mData[i] + v1.mData[i];
        }
        return v;
    }

// Binary - operator
template <class T>
Vector<T> Vector<T>::operator-(const Vector& v1) const
    {
        assert(mSize == v1.mSize);

        Vector v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = mData[i] - v1.mData[i];
        }
        return v;
    }

// Scalar multiplication
template<class T>
Vector<T> Vector<T>::operator*(double a) const
    {
        Vector v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = a*mData[i];
        }
        return v;
    }

// p-norm
template<class T>
double Vector<T>::CalculateNorm(int p) const
{
    double norm_val, sum = 0.0;
    for (int i=0; i<mSize; i++)
    {
        sum += pow(std::abs(mData[i]), p);
    }
    norm_val = pow(sum, 1.0/((double)(p)));
    return norm_val;
}

//Storage method
template<class T> 
std::vector<T> const& Vector<T>::getStorage() const
{
    return mData;
}

#endif
