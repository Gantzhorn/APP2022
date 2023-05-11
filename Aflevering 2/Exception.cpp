#include "Exception.hpp"
#include <iostream>
// Constructor
Exception::Exception(std::string tagString,std::string probString) : mTag(tagString), mProblem(probString){}


void Exception::PrintDebug() const
{
  std::cerr << "Error "<<mTag<< std::endl;
  std::cerr << "Problem: " << mProblem << std::endl;;
}