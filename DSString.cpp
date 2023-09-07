#include "DSString.h"
/* 
 * Implement the functions defined in DSString.h. You may add more functions as needed
 * for the project. 
 *
 * Note that c-strings use `\0` as a terminator symbol
 * but your class should store its length in a member variable. Do not use c-string functions 
 * from <string.h> or <cstring> other than for conversion from a c-string.
 */  


//blank constructor
DSString::DSString (){}

// constructor that converts a cstring
// you can also provide  DSString(const string &); for std::string
 DSString::DSString(const char *){} 

// Rule of three is needed if dynamic memory allocation is used
// copy constructor
    DSString::DSString(const DSString &copy){
         data = new char(*copy.data);
    }
    
//destructor               
    DSString::~DSString(){
     delete data;
    }      

//assignment operator
   //HAVE NOT WRITTEN THIS YET !!!!
   //DSString::DSString &operator=(const DSString &); 

// returns the length of the string
size_t DSString ::length () const{
    return len;
}

// returns a reference to the character at the given index
char &DSString:: operator[](size_t index){}

// Overloaded operator+ which appends the string in the argument to this string

   // DSString operator+(const DSString &) const;
  