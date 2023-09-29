#ifndef SENTIMENTANALYZER_H
#define SENTIMENTANALYZER_H

# include <map>
# include "DSString.h"
#include <map>
using namespace std;

class SentimentAnalyzer {
public:
    //void train();
    void train(char*);
    void test(char*, char*, char*, char*);//char*, char*, char*, char*
    //char * later for file paths
private:
    map<DSString, int> dictionary;
//     DSString trainer;
//   char trainingName[1000];
//    char testingName[1000];
//     char sentimentSetName[1000];
};
#endif