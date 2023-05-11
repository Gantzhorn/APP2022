#include "CalculateExponential.hpp"

// Allocate memory matrix
ComplexNumber** AllocateMatrixMemory() {
  ComplexNumber** A;
  A = new ComplexNumber * [3];

  for (int j=0; j<3; j++) {
    A[j] = new ComplexNumber [3];
  }
  return A;
}

// Free memory matrix
void FreeMatrixMemory(ComplexNumber** A) {
  for (int j=0; j<3; j++) {
    delete[] A[j];
  }
  delete[] A;
}

// Matrix print
void printMatrix(ComplexNumber **A, int rows, int cols)
{
  for (int i=0; i<rows; i++) {
    for (int j=0; j<cols; j++){
      std::cout << A[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

// Mutiply matrices
void Multiply(ComplexNumber **res, ComplexNumber **A, ComplexNumber **B) {
  ComplexNumber entry;

  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      entry = 0;
      for (int k=0; k<3; k++) {
        entry = entry + A[i][k]*B[k][j];
      }
      res[i][j] = entry;
    }
  }
}

// nth power of matrix divided by n
void MatrixPower(ComplexNumber **res, ComplexNumber **A, int nMax) {
  if (nMax == 0) {
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        res[i][j] = ComplexNumber();
      }
      res[i][i] = ComplexNumber(1,0);
    }
  }
  else if (nMax == 1) {
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        res[i][j] = A[i][j];
      }
    }
  }
  else {
    ComplexNumber **C = AllocateMatrixMemory();
  
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        res[i][j] = A[i][j];
      }
    }

    for (int n = 2; n<=nMax; n++) {
      for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
          C[i][j] = res[i][j]*ComplexNumber(1/(double)n,0);
        }
      }

      Multiply(res, A, C);
    }

    FreeMatrixMemory(C);
  }
}

//Calculate exponential of matrix

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res)
{
  ComplexNumber **B = AllocateMatrixMemory();

  for (int n = 0; n<=nMax; n++) {
    MatrixPower(B, A, n);
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        res[i][j] = res[i][j] + B[i][j];
      }
    }
  }

  FreeMatrixMemory(B);
}