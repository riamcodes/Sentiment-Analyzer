#include "DSString.h"
/*
 * Implement the functions defined in DSString.h. You may add more functions as needed
 * for the project.
 *
 * Note that c-strings use `\0` as a terminator symbol
 * but your class should store its length in a member variable. Do not use c-string functions
 * from <string.h> or <cstring> other than for conversion from a c-string.
 */

// blank constructor
DSString::DSString()
{
    // create a character array and have the pointer point to it

    // 1 new empty string (/0 length will be 1
    data = new char[1];
    // 2 make data point to the new string
    data[0] = '\0';
    // 3 adjust the length variable to 0
    len = 0;
}

// constructor that converts a cstring
// you can also provide  DSString(const string &); for std::string
DSString::DSString(const char *str)
{
    // 1use library or just calculate length using loop
    // 2 copy cstring over charter by character

    // Step 1: Calculate the length of the input C-string
    len = 0;
    while (str[len] != '\0')
    {
        len++;
    }

    // Step 2: Allocate memory for the internal data and copy the C-string
    data = new char[len + 1]; // +1 for the null terminator
    for (size_t i = 0; i < len; i++)
    {
        data[i] = str[i];
    }
    data[len] = '\0'; // Null-terminate the DSString
}

// Rule of three is needed if dynamic memory allocation is used

// copy constructor
DSString::DSString(const DSString &copy)
{
    data = new char[copy.length() + 1];

    // work on this next
    len = copy.length();
    for (int i = 0; i < copy.length(); i++)
    {
        data[i] = copy.data[i];
    }
    data[len] = '\0';
}

// assignment operator
DSString &DSString::operator=(const DSString &newStr)
{
    delete[] data;
    len = newStr.length();
    data = new char[len + 1];
    for (size_t i = 0; i < len; i++)
    {
        *(data + i) = *(newStr.data + i);
        //???? .data what does this mean
    }
    data[len] = '\0';  // Add this line

    return *this;
}

// destructor
DSString::~DSString()
{
    delete[] data;
}

// returns the length of the string
size_t DSString::length() const
{
    return len;
}

// returns a reference to the character at the given index
char &DSString::operator[](size_t index)
{
    if (index < length())
    {
        return data[index];
        throw std::out_of_range("Index out of bounds");
    }
}

// overloaded operator
DSString DSString::operator+(const DSString &adding) const
{
    // WORK ON THIS ONE NEXT
    /*fullSize = len + adding.len;
   char* addedChar = new char[fullSize];
   for (size_t i = 0; i < len-1; i++){
     addedChar[i] = data[i];
   }
   for (size_t i = (len - 1); i < ((len-1) + adding.len);i++){
       int x = 0;
       addedChar[i] = adding.data[x];
       x++;
   }
   return addedChar;
   */
    DSString fullSize;
    fullSize.len = len + adding.len + 1;
    //fullSize.data = new char[fullSize.len + 1]; // +1 for the null terminator
    int x = 0;
    for (size_t i = 0; i < len; i++)
    {
        fullSize.data[i] = data[i];
    }
    for (size_t i = len; i < ((len - 0) + adding.len); i++)
    {
        fullSize[i] = adding.data[x];
        x++;
    }
    fullSize.data[fullSize.len] = '\0';
    return fullSize;
}

// Overloaded operator+ which appends the string in the argument to this string

// DSString operator+(const DSString &) const;

/**
 * Standard relational operators to compare and order your strings.
 * Feel free to add additional.
 **/

bool DSString::operator==(const DSString &checkEqual) const
{
    if(checkEqual.len != this->len) {
        return false;
    }

    bool a = true;
    char *newCh = checkEqual.c_str();

    // Compare each character in the strings
    for (size_t i = 0; i < len + 1; i++)
    {
        if ((data[i]) != newCh[i])
            a = false;
    }
    // If the lengths are the same and all characters match, the strings are equal
    return a;
}

// bool DSString::operator<(const DSString &checkLess) const
// {
//     //std::cout << "Comparing " << data << " with " << checkLess << std::endl;
//     bool a = false;
//     char *newCh = checkLess.c_str();
//     // Compare each character in the strings
//     for (size_t i = 0; i < len + 1; i++)
//     {
//         if ((data[i]) < checkLess.data[i])
//             a = true;
//         break;
//       // continue;
    
//     }

//     //std::cout << "RESULT WAS: " << a << std::endl;
//     return a;
// }

// CODE GENERATED ?????


bool DSString::operator<(const DSString &checkLess) const
{
    // Make sure both strings are of the same length or find the minimum length
    size_t minLen = std::min(len, checkLess.len); 

    for (size_t i = 0; i < minLen; i++)
    {
        if (data[i] < checkLess.data[i])
            return true;
        else if (data[i] > checkLess.data[i])
            return false;
    }

    // If you reach here, the strings are equal up to minLen.
    // The shorter string is considered "smaller"
    return len < checkLess.len;
}


/**
 * The substring method returns a new string object that contains a
 * sequence of characters from this string object.
 *
 * param start - the index of where to start
 * param numChars - the number (count) of characters to copy into
 *    the substring
 * @return a DSString object containing the requested substring
 **/
DSString DSString::substring(size_t start, size_t numChars) const
{
    DSString substr;
    substr.len = numChars;
    delete[] substr.data;
    substr.data = new char[numChars + 1];
    for (size_t i = start; i < start + numChars; i++)
    {
        substr.data[i - start] = data[i];
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
    // noun classes verbs = functions  word is a ds string 5 10 different classes tokeniser needs to cut sttings int o pieces
}

/**
 * @brief Returns a new string object with all characters in lowercase
 *
 * @return DSString
 */
DSString DSString::toLower() const
{
    int lowAsciiVal = 0;
    for (size_t i = 0; i < len; i++)
    {
        if ((data[i] < 91) && (data[i] > 64))
        {
            lowAsciiVal = toascii(data[i]) + 32;
            data[i] = char(lowAsciiVal);
        }
    }
    return data;
} // look at the ASCII table for this!

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
char *DSString::c_str() const
{

    return data;
}

std::ostream &operator<<(std::ostream &output, const DSString &str)
{
    // char *c = str.c_str();
    // // std::cout<<c[0];
    // for (size_t i = 0; i < str.length(); i++)
    // {
    //     output.put(c[i]);
    // }
    //    output <<  str.data;
    return output << str.data;
}

// // Implementation of the tokenize function
// std::vector<DSString> DSString::tokenizeDSString()
// {
//     std::vector<DSString> words;
//     size_t counter = 0;

//     for (size_t i = 0; i < length(); ++i)
//     {
//         char currentChar = data[i];
//         bool isDelimiter = (currentChar == ' ' || currentChar == ',' || currentChar == ';' || currentChar == '.' || currentChar == ':' || currentChar == '!' || currentChar == '?');
        
//         if (isDelimiter || (i == length() - 1)) {
//             if (i != counter || (i == length() - 1 && !isDelimiter)) {
//                 // Edge case: if the last character is not a delimiter, include it in the last token
//                 size_t end = isDelimiter ? i : i + 1;
//                 DSString currentWord = substring(counter, end - counter);
//                 words.push_back(currentWord);
//             }
//             counter = i + 1;
//         }
//     }
//     return words;
// }

std::vector<DSString> DSString::tokenizeDSString()
{
    // char* currentChar = phrase.c_str();
    std::vector<DSString> words;
    size_t counter = 0;

    DSString currentWord;

    for (size_t i = 0; i < length() + 1; ++i)
    {
        char currentChar = data[i];
        /*
        if ((currentChar != ' ') && (isalpha(currentChar)==false)){
        DSString special = "" + currentChar;
            words.push_back(special);
            i++;
        }
        */
        if (currentChar == ' ' || currentChar == ',' || currentChar == ';' || currentChar == '.' || currentChar == ':' || currentChar == '!' || currentChar == '?' || currentChar == '\0'
        && i!= counter)
        {
            // if(isalpha(data[i])){
            currentWord = substring(counter, i - counter);
            words.push_back(currentWord);
            counter = i + 1;
        }
        else if (currentChar == ' ' || currentChar == ',' || currentChar == ';' || currentChar == '.' || currentChar == ':' || currentChar == '!' || currentChar == '?' || currentChar == '\0'
        && i!= counter){
            counter++;
        }
    }
    return words;
}

/*bool DSString::getline(std::istream &in)
{
    // go until EOF or \n
    char *content = new char[10000];
    char cur;
    size_t i = 0;
    bool eof = false;
    while (in.get(cur) && i < 10000)
    {
        if (cur == '\n')
        {
            eof = true;
            break;
        }
        content[i] = cur;
        ++i;
    }

    // i is len of content
    content[i] = '\0';
    this->len = i;
    delete[] this->data;
    this->data = content;
    return eof;
}
*/