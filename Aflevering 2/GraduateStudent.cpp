#include "GraduateStudent.hpp"
//Graduate student:

//Defualt constructor
GraduateStudent::GraduateStudent() : Student(), fullTime(true){
}

//Constructor
GraduateStudent::GraduateStudent(std::string name, double fines, double fees, bool fullTime) : Student(name, fines, 0.0) , fullTime(fullTime){
}

//Graduate student methods
double GraduateStudent::MoneyOwed() const{
    return GetLibraryFines();
}