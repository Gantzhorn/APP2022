#include <cassert>
#include "5_6.h"
//---------------------------------------------------------------------------------------------------------------------//
//Matrix-udgaven:
void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols){
    assert(ACols == BRows);
    double tempSum = 0;
    for (int i = 0; i<ARows; i++)
    {
        for (int j = 0; j<BCols; j++)
        {
            for (int k = 0; k<ACols; k++)
            {
                tempSum += A[i][k]*B[k][j];
            }
            res[i][j] = tempSum;
            tempSum = 0;
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------//
// Vektor med matrix-udgaven:
void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols){
    assert(ACols == BRows);
    double tempSum = 0;
    for (int i = 0; i <BCols; i++){
        for (int j = 0; j <ACols; j++){
            tempSum += A[j]*B[j][i];
        }
        res[i] = tempSum;
        tempSum = 0;
    }

}
//---------------------------------------------------------------------------------------------------------------------//
// Matrix med vektor-udgaven:
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows){
    assert(ACols == BRows);
    double tempSum = 0;
    for (int i = 0; i < ARows; i++){
        for (int j = 0; j < BRows; j++){
            tempSum += A[i][j]*B[j];
        }
        res[i] = tempSum;
        tempSum = 0;
    }

}
//---------------------------------------------------------------------------------------------------------------------//
// Skalar med matrix-udgaven:
void Multiply(double **res, double scalar, double **B, int BRows, int BCols){
    for (int i = 0; i < BRows; i++){
        for (int j = 0; j < BCols; j++){
            res[i][j] = scalar*B[i][j];
        }
    }
}

// Matrix med skalar-udgaven:
void Multiply(double **res, double **B, double scalar, int BRows, int BCols){
    for (int i = 0; i < BRows; i++){
        for (int j = 0; j < BCols; j++){
            res[i][j] = scalar*B[i][j];
        }
    }
}
