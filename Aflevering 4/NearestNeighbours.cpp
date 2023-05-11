#include "armadillo.hpp"
#include <cassert>

//----------------------------------------------------------------------------------------------------------------------------//

struct P
{
    double d; //distance to neighbour
    int lab; // Given label
};
    
//----------------------------------------------------------------------------------------------------------------------------//
//Metric for comparing points based on distances
bool comp(const P &left, const P &right);

//----------------------------------------------------------------------------------------------------------------------------//

int main(){
    
    //Define containers using armadillo implementation of vector and matrix. 
    arma::Mat<double> xDat, xTest; arma::Col<int> yDat;

    //Read data from file using build in methods:
    xDat.load("dataX.dat"); xTest.load("dataXtest.dat"); yDat.load("dataY.dat");

    //Also possible to print data with .print() method if one wishes to

//----------------------------------------------------------------------------------------------------------------------------//

    //Define container for result using <vector>
    std::vector<int> res;
    //Implent k-nearest neighbors with k = 5
    int k = 5;

//----------------------------------------------------------------------------------------------------------------------------//
    
        for (int n=0;n<xTest.n_rows;n++){
            std::vector<P> D; //Vector containg the information in "points" for point n.
            for (int j=0;j<xDat.n_rows;j++){
            P Q; //Container
            //Computes and stores the euclidian distance between test point and point
                Q.d=arma::norm(xDat.row(j)-xTest.row(n));
                Q.lab = yDat(j); //Stores the actual y value. 
                D.emplace_back(Q); //Stores result in D
            }

//----------------------------------------------------------------------------------------------------------------------------//

        std::sort(D.begin(), D.end(), comp); //Sort D using own comparisons between points s.t. we for every point get its
        //nearest neighbours
        int pos = 0; //Container for positive neighbours
        int neg = 0; //Container for negative neighbours
        for (int j=0;j<k;j++){
            if (D[j].lab == -1) {
                neg +=1;
            } else{
                pos +=1;
            } //Checks if there a more negative or postive neighbours
        }
        if (neg>=pos){
            res.emplace_back(-1);
        }else{
            res.emplace_back(1);
        }
    }
    
//----------------------------------------------------------------------------------------------------------------------------//

    std::ofstream write_output("NN.dat"); //Creates a dat file we can write to

    assert(write_output.is_open()); //Ensures we do not write to an open file.

    //Writes to output just like yDat was structured
    for(int m = 0; m<xTest.n_rows; m++){
        write_output << res[m] << std::endl;
    }
    //close file
    write_output.close();
return 0;
}

//----------------------------------------------------------------------------------------------------------------------------//
//Metric comparing whether a point is closer to our specific point than another point is
bool comp(const P &left, const P &right){
    return left.d < right.d;
}