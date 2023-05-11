#include "PhdStudent.hpp"

//--------------------------------------------------------------------------------------------------------------//
//phd constructor
PhdStudent::PhdStudent(std::string name, double fines, double fees, bool fullTime) : GraduateStudent(name, 0.0, fees, fullTime){}

//phd student methods
double PhdStudent::MoneyOwed() const{
    return 0;
}

