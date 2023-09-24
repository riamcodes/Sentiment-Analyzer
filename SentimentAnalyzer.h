#ifndef SENTIMENTANALYZER_H
#define SENTIMENTANALYZER_H

# include <map>
# include "DSString.h"
# include "Word.h"
using namespace std;

class SentimentAnalyzer {
public:
    void train();
private:
map<DSString, Word> dictionary;
    
};
#endif