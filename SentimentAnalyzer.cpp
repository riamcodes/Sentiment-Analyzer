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
    int sentimentValue;
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
   curTweetWord.toLower(); 
     if (sentiment == "4"){
        //cout << curTweetWord << endl;
        //dictionary[curTweetWord].sentimentValue++;
        dictionary[curTweetWord]++;

     }
     else if(sentiment == "0"){
      //  cout << curTweetWord << endl;
        dictionary[curTweetWord]--;
     }
        
       

   
 }
 
     }


    cout << counter << endl;
   delete[]  buffer;

   for (auto& curDictWord : dictionary) { 
        cout << curDictWord.first << ' ' << curDictWord.second << endl;
    }
}

void SentimentAnalyzer::test(){

   std::ifstream file("/users7/cse/rmukherji/assignment-2-don-t-be-sentimental-riamuk101/smallTrainingSet.csv");
    if (!file.good())
    {
        throw std::invalid_argument("file could not be opened");
    }
    

    //DSString curLine;
   
    int idVectorCounter = 0;
    int sentimentValue;
    char* buffer = new char[1000];
   // char* buffer2 = new char[1000];
    double counter = 0;
    
    vector<DSString> guessedSentiments;
   vector<DSString> ids ;
    file.ignore(1000,'\n');
    while (file.getline(buffer, 1000, ',')) {
      //stores the sentiment value 0 or 4 into a DSString
     //DSString sentiment(buffer);
     //file.ignore(1000,',');
     char id[500];
     file.getline(id,500,',');
     DSString idValue(id);  
     ids.push_back(idValue);
    // DSString a = DSString sentiment(buffer);
     file.ignore(1000,',');
     file.ignore(1000,',');

  file.getline(buffer, 10000, '\n');
     DSString tweetDSString(buffer);
     vector<DSString> words = tweetDSString.tokenizeDSString();






// index through the vector of words from an individual tweet and find the values of those words in my map
     for (size_t i = 0; i < words.size();i++){
      auto indWord = dictionary.find(words.at(i));
    // get whether the value associated in the word is negative or positive and if it is positive add 1 to counter else subtract 1
      // Check if the word was found in the dictionary
    if (indWord != dictionary.end()) {
        // The word was found, indWord->second is its value (sentiment score)
        std::cout << indWord->first << " ";
        if (indWord->second > 0) {
            // The value is positive
            counter++;
        } else if (indWord->second < 0) {
            // The value is negative
            counter--;
        }
        // Note: if indWord->second is 0, do nothing
        
    } else {
        // The word was not found in the dictionary
        // Do nothing or handle this case as you see fit
    }
    }
        std::cout << std::endl;

//std::cout<< "counter: " << counter << std::endl;
// counter = counter/(words.size());
// Now the variable 'counter' contains the sum of sentiment values for all words in the tweet
if(counter > 0){
 // std::cout <<"4" << std::endl;
  guessedSentiments.push_back("4");
}
else if(counter <= 0){
 // std::cout <<"0" << std::endl;
   guessedSentiments.push_back("0");
}
std::cout << ids.at(idVectorCounter) << endl;
std::cout << guessedSentiments.at(idVectorCounter) << endl;
counter = 0;
idVectorCounter++;
//delete[] buffer;
//std::cout << "The sentiment counter for this tweet is: " << counter << std::endl;

     }
//std:: vector sentiment
delete[] buffer;




// start reading in the actual values 

std::ifstream file2("/users7/cse/rmukherji/assignment-2-don-t-be-sentimental-riamuk101/data/test_dataset_sentiment_10k.csv");
   if (!file2.good())
    {
        throw std::invalid_argument("file could not be opened");
    }


   char* buffer2 = new char[1000];
//    // char* buffer2 = new char[1000];
 double accuracyCounter = 0;
//     int newCounter = 0; 
    

   file2.ignore(1000,'\n');
while (file2.getline(buffer2, 1000, ',')) {
 
  file2.getline(buffer2, 1000, ',');
  DSString tempTrueSentiment(buffer2);
  file2.getline(buffer2, 1000, ',');
   DSString tempId(buffer2);
//std::cout << tempTrueSentiment << tempId;

for(int i = 0; i < ids.size(); i ++){
    if (ids.at(i) == tempId){
        if(guessedSentiments.at(i)==tempTrueSentiment){
              accuracyCounter++;
        }
        else{

        }
    }
}

 }
}
