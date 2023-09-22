#include "SentimentAnalyzer.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "DSString.h"
#include "Word.h"

using namespace std;

void SentimentAnalyzer::train() {
    //CHANGE THE WAY THE FILE IS READ IN BEFORE SUBMITTING
    std::ifstream file("/users7/cse/rmukherji/assignment-2-don-t-be-sentimental-riamuk101/data/train_dataset_20k.csv");
    if (!file.good())
    {
        throw std::invalid_argument("file could not be opened");
    }
    
    vector<Word> dictionary;

    DSString curLine;
    size_t counter = 0;
    while (curLine.getline(file)) {
        bool senti = (curLine[0] == '4'); // true == good sentiment, false == bad sentiment
        vector<DSString> words = curLine.tokenizeDSString();

        // read current sentiment of current tweet
        // go through words of current tweet and update dictionary vector

        for (DSString& curTweetWord : words) {
            bool found = false;
            for (Word& curDictWord : dictionary) {
                if(curDictWord.content == curTweetWord) {
                    found = true;
                    if(senti == true) {
                        curDictWord.posCount++;
                    }
                    else {
                        curDictWord.negCount++;
                    }
                    break;
                }
            }
            if(found == false) {
                ++counter;
                if(senti == true) {
                    dictionary.push_back(Word(curTweetWord, 1, 0));
                   // if (curTweetWord.substring(0,1) == "@"){
                    //    dictionary.pop_back();
                   // }

                }
                else {
                    dictionary.push_back(Word(curTweetWord, 0, 1));
                   // if (curTweetWord.substring(0,1) == "@"){
                   //     dictionary.pop_back();
                   // }
                }
            }
        }

    }

    // printing for debug purposes
    for (Word cur: dictionary) {
        cout << cur.content << ' ' << cur.posCount << ' ' << cur.negCount << endl;
    }

    cout << counter << endl;
    
}