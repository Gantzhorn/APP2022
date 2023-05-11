#include "Student.hpp"

//--------------------------------------------------------------------------------------------------------------//
//Student class:

//Default constructor

Student::Student() : name("Unknown"), library_fines(0.0), tuition_fees(0.0)
{}

//Constructor uses assertion that fines must be non-negative
Student::Student(std::string name, double fines, double fees) : name(name), tuition_fees(fees) {
    this->SetLibraryFines(fines);
    library_fines = this->GetLibraryFines();
}
//--------------------------------------------------------------------------------------------------------------//

//Default 



//--------------------------------------------------------------------------------------------------------------//
//Student class methods

//MoneyOwed method for student
double Student::MoneyOwed() const{
    return tuition_fees + library_fines;
}

//Not allowing negative fees
void Student::SetLibraryFines(double amount)
{
    if (amount<0)
    {
        library_fines=-amount;
    }
    else
    {
        library_fines=amount;
    }
}

//Accesing library_fines
double Student::GetLibraryFines()const{
return library_fines;
}

