#include "armadillo.hpp"
#include <cassert>
//------------------------------------------------------------------------------------------------------------//

int main(){
    //Define containers using armadillo implementation of vector and matrix. 
    arma::mat xDatL, xTestL; arma::vec yDatL;

    //Read data from file using build in methods:
    xDatL.load("dataX.dat"); xTestL.load("dataXtest.dat"); yDatL.load("dataY.dat");

    double eps = pow(10,-7); //epsilon
    double alph = 0.1; //learning rate

    arma::vec wNew = arma::vec(xDatL.n_cols);
    wNew.zeros(); //Initializes all elements of vector to zero
    arma::vec wOld = arma::vec(xDatL.n_cols);
    arma::vec sumVec = arma::vec(xDatL.n_cols);

    do
    {
        wOld = wNew; //Sets elements of old vector to new vector for every iteration
        sumVec.zeros(); //Armadillo method that resets all elements to 0.
        for (int j = 0; j < xDatL.n_rows; j++){
            //Computes derivative sum from assignment
            sumVec += (yDatL[j]*xDatL.row(j).t())/(1+exp(yDatL[j]*arma::cdot(xDatL.row(j),wOld)));
        } 
        wNew = wOld-alph*(-1.0/xDatL.n_rows)*sumVec; //Update using formula from assignment
    } while(arma::norm(wNew-wOld)>eps); //loops based on euclidian distance between w's. Assumes convergence.

//------------------------------------------------------------------------------------------------------------//
std::vector<int> res;
//Assignment of label based on rule y = sign(f(x))
// where f is the linear function f(x) = w^Tx = arma::cdot((xtestL.row(i).t(),wNew))
for (int i = 0; i<xTestL.n_rows;i++){
    if(arma::cdot((xTestL.row(i).t()),wNew)<0){
        res.emplace_back(-1);
    }
    else{
        res.emplace_back(1);
    }
}
//Creates file and writes res to it
std::ofstream write_output("LogReg.dat"); 
assert(write_output.is_open());
for(int i = 0; i<xTestL.n_rows;i++){
    write_output << res[i] << std::endl;  
}
//Closes file
write_output.close();
return 0;
}
