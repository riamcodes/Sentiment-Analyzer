#include <iostream>
#include "SentimentAnalyzer.h"
#include "DSString.h"

int main(int argc, char** argv)
{  
    SentimentAnalyzer sa;
    sa.train();
    sa.test();
    return 0;
}