#include <iostream>
#include "SentimentAnalyzer.h"
#include "DSString.h"

int main(int argc, char** argv)
{   
   //std::cout<<argv[1];
        // std::cout << "Usage: ";
        // std::cin >> argv[0];
        // std::cout << " <parameter>" << std::endl;
        // return 1;

    //return 0;

    //cout<<argv[1];
    //cout<<argv[2];
    SentimentAnalyzer sa;
    sa.train(argv[1]);
    sa.test(argv[2],argv[3],argv[4],argv[5]);
    return 0;
}