#include <iostream>
#include <cstring>
#include <stdexcept>
#include <memory>
#include "str.h"

// use this to run
// g++ --std=c++17 -o test str.cpp strtest.cpp

Str::Str() // Default constructor Str s;
{ // This empty constructor should store the empty string
	len = 0;
	buffer = std::make_unique<char []>(len + 1); // includes null character
}

Str::Str(const char* s) // String constructor Str s("hello");
{ // This constructor should store the string passed as argument
	len = strlen(s);
	buffer = std::make_unique<char []>(len + 1); // includes null character


}		

// This is a copy constructor. It is necessary to pass Str objects too and from functions
// We will discuss more next class meeting

Str::Str(const Str& other) // Copy constructor
{
   buffer = std::make_unique<char[]>(other.size()+1);
   len = other.size();
    strcpy(this->buffer.get(), other.buffer.get());

}

Str::~Str() // Destructor
{

}

size_t Str::size() const // returns size
{
	return len;
}


