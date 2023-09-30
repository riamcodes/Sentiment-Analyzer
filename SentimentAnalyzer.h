#ifndef SENTIMENTANALYZER_H
#define SENTIMENTANALYZER_H

# include <map>
# include "DSString.h"
#include <map>
using namespace std;

class SentimentAnalyzer {
public:
    void train(char*);
    void test(char*, char*, char*, char*);

private:
   map<DSString, int> dictionary;
   double percentage;
   double accuracyCounter;
   double tweetsClassified; 
};
#endif