#include <iostream>
#include "SentimentAnalyzer.h"
#include "DSString.h"

int main(int argc, char** argv)
{   
   
        // std::cout << "Usage: ";
        // std::cin >> argv[0];
        // std::cout << " <parameter>" << std::endl;
        // return 1;

    //return 0;
    SentimentAnalyzer sa;
    sa.train();
    sa.test();
    return 0;
}