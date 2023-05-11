#include "5_3.h"

void swap_pointer(double *a, double *b){
	double x = *a;
	*a = *b;
	*b = x;
}

void swap_ref(double &a, double &b){
    double temp = a;
    a = b;
    b = temp;
}