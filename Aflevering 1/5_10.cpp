#include "5_10.h"

void guassian_elimination(double **A, double *b, double *u, int n)
{   
    double tempSum1;
    double tempSum2;
    double tempSum;
    double M;
        for (int l=0; l<n; l++)
        {
            int S=A[l][l];
            int largest = l;
            for (int q=l+1; q<n; q++)
            {
                    if (A[q][l]>S)
                    {
                        S=A[l][q];
                        largest = q;
                    }
            }
        
        
            double P[n][n];
            for (int i=0; i< n; i++)
            {
                for (int j=0;j<n;j++)
                {
                    if (((i==j) && (i!=largest) && (j!=largest) && (i!=l) && (j!=l)) ||
                    ((i==l) && (j==largest)) ||((i==largest) && (j==l)))
                    {
                        P[i][j]=1;
                    }
                    else
                    {
                        P[i][j]=0;
                    }
                }
            }
        
        double PA[n][n];
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n;j++)
            {
                for (int p=0; p< n; p++)
                {
                    tempSum1 += P[i][p]*A[p][j];
                }
                PA[i][j] = tempSum1;
                tempSum1=0;
            }
        }

        double Pb[n];
        for (int i=0; i<n; i++)
        {
            for (int j=0; j< n; j++)
            {
                tempSum2 += P[i][j]*b[j];
            }
            Pb[i] = tempSum2;
            tempSum2=0;
        }
        

            for (int i=0; i<n; i++)
            {
                for (int j=0; j<n;j++)
                {
                    A[i][j]=PA[i][j];
                }
                b[i] = Pb[i];
            }

        
            M = 0.0;
            for (int i= l+1; i<n; i++)
            {
                M=A[i][l]/A[l][l];
                A[i][l]=0;
                for (int j=l+1; j<n;j++)
                {
                    A[i][j]=A[i][j]-M*A[l][j];
                }
                b[i]= b[i] - M*b[l];
            }
        }
        
        tempSum=0;
        for (int i =n-1; i>-1;i--)
        {
            for (int j =i+1; j<n;j++)
            {
                tempSum= tempSum+A[i][j]*u[j];
            }
            u[i]=(b[i]-tempSum)/A[i][i];
            tempSum=0;
        }
    }
