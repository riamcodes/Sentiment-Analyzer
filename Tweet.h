#ifndef TWEET_H
#define TWEET_H
#include<vector>
#include "DSString.h"
//using namespace std;

// created during testing only
class Tweet
{
private:
    std::vector<DSString> content; // tokenized words of tweet
    DSString id;
    int sentiment = 0;
};
#endif