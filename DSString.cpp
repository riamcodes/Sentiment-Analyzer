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
DSString::DSString (){
    // create a character array and have the pointer point to it
   
    // 1 new empty string (/0 length will be 1 
     data = new char[1];
    // 2 make data point to the new string
      data[0] = '\0';
    //3 adjust the length variable to 0
    len = 0;
}

// constructor that converts a cstring
// you can also provide  DSString(const string &); for std::string
 DSString::DSString(const char *str){
    // 1use library or just calculate length using loop 
    //2 copy cstring over charter by character 

     // Step 1: Calculate the length of the input C-string
    len = 0;
    while (str[len] != '\0') {
        len++;
    }

    // Step 2: Allocate memory for the internal data and copy the C-string
    data = new char[len + 1]; // +1 for the null terminator
    for (size_t i = 0; i < len; i++) {
        data[i] = str[i];
    }
    data[len] = '\0'; // Null-terminate the DSString

 } 

// Rule of three is needed if dynamic memory allocation is used
// copy constructor
   //DSString::DSString(const DSString &copy){
        // data = new char(*copy.data);// use the previous function as a template 
 // }
 DSString::DSString(const DSString &copy)
 {
    data = new char[copy.length()+1];
   
        //work on this next 
    len = copy.length();
     for (int i = 0; i < copy.length(); i++ ){
data[i] = copy.data[i];
}
 data[len] = '\0';

}

//assignment operator 
 DSString &DSString::operator=(const DSString &newStr){
    delete[] data;
    len = newStr.length();
    data = new char[len+1];
    for (size_t i = 0; i < len; i++){
*(data+i)=*(newStr.data + i );
//???? .data what does this mean
    }


 }

 // destructor
 DSString::~DSString()
 {
     delete [] data;
    }      


// returns the length of the string
size_t DSString::length() const{
    return len;
}

// returns a reference to the character at the given index
char& DSString::operator[](size_t index){
    if (index < length()){
        return data[index];
    }
}



//overloaded operator
DSString DSString::operator+(const DSString &adding) const{
//WORK ON THIS ONE NEXT

}

// Overloaded operator+ which appends the string in the argument to this string

   // DSString operator+(const DSString &) const;


   /**
     * Standard relational operators to compare and order your strings.
     * Feel free to add additional.
     **/
    bool DSString::operator==(const DSString &checkEqual) const{

        char* newCh = checkEqual.c_str();
    // Compare each character in the strings
    for(size_t i = 0; i < len; i++){
        if ((data[i]) != newCh[i])
        return false;
    }

  
    // If the lengths are the same and all characters match, the strings are equal
 return true;
    
}



    bool DSString::operator<(const DSString &) const{}


    
    /**
     * The substring method returns a new string object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     * @return a DSString object containing the requested substring
     **/
    DSString DSString::substring(size_t start, size_t numChars) const{
        DSString substr;
        substr.len = numChars + 1;
for (size_t i = start; i < start+numChars; i++){
          substr.data[i-start] = data[i];
        }
        substr.data[numChars] = '\0';
        return substr;
        
       /* char* newStr = new char[numChars+1];//new character array 
        for (int i = start; i < start+numChars; i++){
            newStr[i-start] =  data[i];
        }
        DSString ret(newStr);
        return ret;
*/
//noun classes verbs = functions  word is a ds string 5 10 different classes tokeniser needs to cut sttings int o pieces 

    }


 /**
     * @brief Returns a new string object with all characters in lowercase
     *
     * @return DSString
     */
    DSString DSString::toLower() const{}// look at the ASCII table for this!
 
    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument. Remember:
     * This operator needs to be implemented outside of the class as
     * a friend because it operates on the stream and not the DSString object.
     **/

   /**
     * the c_str function returns a pointer a null-terminated c-string holding the
     * contents of this object. Since data already has a `\0`
     * at the end of the string in DSString so you can just return a pointer to data.
     **/
    char *DSString::c_str() const{
        
    return data;
}

std::ostream &operator<<(std::ostream &output, const DSString &str){
    char* c = str.c_str();
    // std::cout<<c[0];
    for(int i = 0; i < str.length();i++){
        output.put(c[i]);

    }
    //    output <<  str.data; 
       return output;
    }
  