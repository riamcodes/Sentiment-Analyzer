#include "SentimentAnalyzer.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "DSString.h"
#include "Word.h"
#include <map>


//using namespace std;

void SentimentAnalyzer::train() {
    //CHANGE THE WAY THE FILE IS READ IN BEFORE SUBMITTING
    std::ifstream file("/users7/cse/rmukherji/assignment-2-don-t-be-sentimental-riamuk101/smallTrainingSet.csv");
    if (!file.good())
    {
        throw std::invalid_argument("file could not be opened");
    }
    

    //DSString curLine;
    char* buffer = new char[1000];
    size_t counter = 0;
    file.ignore(1000,'\n');
    while (file.getline(buffer, 1000, ',')) {
        //stores the sentiment value 0 or 4 into a DSString
     DSString sentiment(buffer);
     file.ignore(1000,',');
     file.ignore(1000,',');
     file.ignore(1000,',');
     file.ignore(1000,',');

  file.getline(buffer, 10000, '\n');
     DSString tweetDSString(buffer);
     vector<DSString> words = tweetDSString.tokenizeDSString();

 for (DSString& curTweetWord : words) {
     if (sentiment == "4"){
        cout << curTweetWord << endl;
        dictionary[curTweetWord].addData(1,0);

     }
     else if(sentiment == "0"){
        cout << curTweetWord << endl;
        dictionary[curTweetWord].addData(0,1);
     }
        
        for (auto& curDictWord : dictionary) { 
        cout << curDictWord.first << ' ' << curDictWord.second.posCount << ' ' << curDictWord.second.negCount << endl;
    }

 }
     }


    cout << counter << endl;
   delete[]  buffer;
}