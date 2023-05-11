#include "OutOfRangeException.hpp"
//Constructor out of range
OutOfRangeException::OutOfRangeException(std::string prob) : Exception("Out of range", prob){
}
