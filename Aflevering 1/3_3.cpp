#include "3_3.h"
#include <cassert>
#include <fstream>

void implicit_Euler(int n){
    assert(n>1);
    double h = 1.0/(n-1);
    double y_p=1.0;
    double y_m;
    double x;
    std::ofstream write_output("xy.dat");
    assert(write_output.is_open());
    write_output << 0 << "," << 1 << "\n";
    for (int i=1;i<n;i++)
    {
        y_m=y_p/(1+h);
        y_p=y_m;
        x=i*h;
        write_output << x << "," << y_m << "\n";
    }
    write_output.close();

}
