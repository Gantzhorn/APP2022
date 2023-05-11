#include "5_4.h"
#include <math.h>


double calc_mean(double a[], int length){
    double sum = 0;
    for(int i = 0; i < length; i++){
        sum = sum + a[i];
    }
    return sum/length;
}

double calc_std(double a[], int length){
    if (length == 1){return 0;}
    double mean = calc_mean(a, length);
    double sqdev = 0;
    for(int i = 0; i < length; i++){
        sqdev = sqdev + (a[i]-mean)*(a[i]-mean);
    }
    return sqrt(sqdev/(length-1));
}