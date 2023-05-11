#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF
#include "Vector.hpp"
template <class T>
class Matrix
{
private:
	std::vector<T> mData; // entries of matrix
	int mNumRows, mNumCols; // dimensions

public:
    // copy constructor
	Matrix(const Matrix& otherMatrix);

	Matrix(int numRows, int numCols);
    /*
	~Matrix()
    {
        for (int i = 0; i < mNumRows; i++)
        {
            delete[] mData[i];
        }
        delete[] mData;
    }
    */

	int GetNumberOfRows() const;

	int GetNumberOfColumns() const;

	T& operator()(int i, int j);

	T const& operator()(int i, int j) const;

	// overloaded assignment operator
	//Matrix& operator=(const Matrix& otherMatrix);

    // unary -
	Matrix operator-() const;
    // binary +
	Matrix operator+(const Matrix& m1) const;
    // binary -
	Matrix operator-(const Matrix& m1) const;

	// scalar multiplication
	Matrix operator*(double a) const;

    //Get storage operator
    std::vector<T> const& getStorage() const;
};
//---------------------------------------------------------------------------------------------------------//
template<class T> 
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v);
template<class T> 
Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m);

//Copy contructor 
template <class T>
Matrix<T>::Matrix(const Matrix& otherMatrix)
    {
    mNumRows = otherMatrix.mNumRows;
    mNumCols = otherMatrix.mNumCols;
    for (int i=0; i<mNumRows*mNumCols; i++)
    {
        mData.emplace_back(otherMatrix.mData[i]);
    }

}

//Default contructor
template <class T>
Matrix<T>::Matrix(int numRows, int numCols)
   {
    assert((numRows > 0) && (numCols > 0));
    mNumRows = numRows;
    mNumCols = numCols;
    for (int i=0; i<mNumRows*mNumCols; i++)
    {
        mData.emplace_back(0.0);
    }

    }

//---------------------------------------------------------------------------------------------------------//
//Number of rows method 
template <class T>
int Matrix<T>::GetNumberOfRows() const
{
    return mNumRows;
}
//Number of cols method
template <class T>
int Matrix<T>::GetNumberOfColumns() const
{
    return mNumCols;
}

//return cell operator
template <class T>
T& Matrix<T>::operator()(int i, int j)
{
    assert(i >= 0);
    assert(i < mNumRows);
    assert(j >= 0);
    assert(j < mNumCols);
    return mData[GetNumberOfColumns()*(i)+j];
}



template <class T>
T const& Matrix<T>::operator()(int i, int j) const
{
    assert(i >= 0);
    assert(i < mNumRows);
    assert(j >= 0);
    assert(j < mNumCols);
    return mData[GetNumberOfColumns()*(i)+j];
}

//---------------------------------------------------------------------------------------------------------//
/*
//Assignment operator
template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix& otherMatrix)
{
    assert(mNumRows == otherMatrix.mNumRows);
    assert(mNumCols == otherMatrix.mNumCols);

    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            mData[i] = otherMatrix.mData[i];
        }
    }
    return *this;
}
*/
//Unary operator
template <class T>
Matrix<T> Matrix<T>::operator-() const 
{
    Matrix mat(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            mat(i,j) = -mData[GetNumberOfColumns()*(i)+j];
        }
    }
    return mat;
}

//---------------------------------------------------------------------------------------------------------//

//Binary +
template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix& m1) const
{
    assert(mNumRows == m1.mNumRows);
    assert(mNumCols == m1.mNumCols);

    Matrix mat(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            mat(i,j) = mData[GetNumberOfColumns()*(i)+j] + m1.mData[GetNumberOfColumns()*(i)+j];
        }
    }
    return mat;
}

//Binary -
template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix& m1) const 
{
    assert(mNumRows == m1.mNumRows);
    assert(mNumCols == m1.mNumCols);

    Matrix mat(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            mat(i,j) = mData[GetNumberOfColumns()*(i)+j] - m1.mData[GetNumberOfColumns()*(i)+j];
        }
    }
    return mat;
}

//---------------------------------------------------------------------------------------------------------//


//Matrix multiplication
template <class T>
Matrix<T> Matrix<T>::operator*(double a) const
{
    Matrix mat(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            mat(i,j) = a*mData[GetNumberOfColumns()*(i)+j];
        }
    }
    return mat;
}

//---------------------------------------------------------------------------------------------------------//

template<class T> 
std::vector<T> const& Matrix<T>::getStorage() const
{
    return mData;
}

//---------------------------------------------------------------------------------------------------------//

//Matrix-vector multiplication

template<class T> 
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v)
{
    int original_vector_size = v.size();
	assert(m.GetNumberOfColumns() == original_vector_size);

	int new_vector_length = m.GetNumberOfRows();
	Vector<T> new_vector(new_vector_length);

	for (int i = 0; i < new_vector_length; i++)
	{
		for (int j = 0; j < original_vector_size; j++)
		{
			new_vector[i] += m(i,j)*v[j];
		}
	}

	return new_vector;
}

template<class T>
Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m)
{
	int original_vector_size = v.size();
	assert(m.GetNumberOfRows() == original_vector_size);

	int new_vector_length = m.GetNumberOfColumns();
	Vector<T> new_vector(new_vector_length);

	for (int i = 0; i < new_vector_length; i++)
	{
		for (int j = 0; j < original_vector_size; j++)
		{
			new_vector[i] += v[j]*m(j,i);
		}
	}

	return new_vector;

}


#endif
