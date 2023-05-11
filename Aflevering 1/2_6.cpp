#include "2_6.h"
#include <math.h>

double newton_Raphson(double initialGuess, double epsilon){

    double x = initialGuess;
    double x_prev = x;
    double x_next = x-(exp(x)+x*x*x-5)/(exp(x)+3*x*x);
    while(fabs(x_prev-x_next)>=epsilon){
    x_prev = x;
    x_next = x-(exp(x)+x*x*x-5)/(exp(x)+3*x*x);
    x = x_next;
    }
    

    return x;
}
