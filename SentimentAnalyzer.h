#ifndef SENTIMENTANALYZER_H
#define SENTIMENTANALYZER_H

# include <map>
# include "DSString.h"
# include "Word.h"
#include <map>
using namespace std;

class SentimentAnalyzer {
public:
    void train();
    void test();
    //char * later for file paths
private:
    map<DSString, int> dictionary;
    
};
#endif