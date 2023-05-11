#include "FileNotOpenException.hpp"

//Constructor File not open
FileNotOpenException::FileNotOpenException(std::string prob) : Exception("File not open", prob){}