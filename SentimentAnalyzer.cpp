#include "SentimentAnalyzer.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "DSString.h"
#include <map>
#include <iomanip>


void SentimentAnalyzer::train(char* argv) {

    //file is read in through passed arg
    std::ifstream file(argv);
    if (!file.good())
    {
        throw std::invalid_argument("file could not be opened");
    }
    

    //create a new buffer to seperate and store from csv
    char* buffer = new char[1000];
    size_t counter = 0;
    file.ignore(1000,'\n');
    while (file.getline(buffer, 1000, ',')) {

    //stores the sentiment value 0 or 4 into a DSString
    DSString sentiment(buffer);

    //ignore csv irrelevant lines
    file.ignore(1000,',');
    file.ignore(1000,',');
    file.ignore(1000,',');
    file.ignore(1000,',');

    //get the actual tweet 
    file.getline(buffer, 10000, '\n');
    DSString tweetDSString(buffer);

    //tokenize tweet store in vector using DSString func
    vector<DSString> words = tweetDSString.tokenizeDSString();

    //adding to map. toLower for no duplicates. Determines sentiment and updates key value attached to word in map
    for (DSString& curTweetWord : words) {
      curTweetWord.toLower(); 
         if (sentiment == "4"){
        dictionary[curTweetWord]++;

     }
     else if(sentiment == "0"){
      // cout << curTweetWord << endl;
        dictionary[curTweetWord]--;
     }
    }
   }
    cout << counter << endl;
   delete[]  buffer;
}

void SentimentAnalyzer::test(char* argv, char* argv2, char* argv3, char* argv4) {
vector<DSString> forOutput;
vector<DSString> forOutput2;
vector<DSString> forOutput3;
    std::ofstream outFile;
    std::ofstream outFile2;
    
    //Open the two files for output
    outFile.open(argv3);
    outFile2.open(argv4);
    
    // Check if the file is open
    if (!outFile) {
        throw std::invalid_argument("file could not be opened");
        std:: cout << "NO";
    }

    // Open the first file for testing without sentiments
    std::ifstream file(argv);
    if (!file.good()) {
        throw std::invalid_argument("file could not be opened");
    }

     // Buffer to store each field
    char buffer[10000];  
    double counter = 0;
    int idVectorCounter = 0;
    vector<DSString> guessedSentiments;
    vector<DSString> ids;

    // Ignore header line
    file.ignore(1000, '\n');

    while (file.getline(buffer, 1000, ',')) {  // Reading ID
        DSString idValue(buffer);
        ids.push_back(idValue);

        // Skipping Date, Query, User
        file.ignore(1000, ',');  // Skip to next comma (Date)
        file.ignore(1000, ',');  // Skip to next comma (Query)
        file.ignore(1000, ',');  // Skip to next comma (User)

        // Reading the tweet
        file.getline(buffer, 1000, '\n'); 
        DSString tweetDSString(buffer);

        //Tokenize the tweet storing it in a DSString vector
        vector<DSString> words = tweetDSString.tokenizeDSString();
            for (size_t i = 0; i < words.size(); i++) {
             DSString lowerWord = (words.at(i).toLower());  // Convert word to lowercase
             auto indWord = dictionary.find(lowerWord);  // Lookup the low word

            //if the word is less tha 0 negative word, else positive if equal or greater than or 0 
            //adds to the dictionary in either case adds or subtracts one for sentiment
            if (indWord != dictionary.end()) {
                if (indWord->second >= 0) {
                    counter++;
                } else if (indWord->second < 0) {
                    counter --;
                }
            }
        }
  
        
        // based on if negative or positive if sentiment of tweet is positive push 4 else push 0
        if (counter > 0) {
            guessedSentiments.push_back("4");
        } else {
            guessedSentiments.push_back("0");
        }
        counter = 0;
        idVectorCounter++;
    }

    // Open the second file
    std::ifstream file2(argv2);
    if (!file2.good()) {
        throw std::invalid_argument("file could not be opened");
    }

    //char to read in file 2 with sentiments and tweetslike before 
    char buffer2[1000];
    accuracyCounter = 0;
    tweetsClassified = 0;

    // Ignore header line
    file2.ignore(1000, '\n');
   
    //while it has other lines get the sentiment 
    while (file2.getline(buffer2, 1000, ',')) {
    DSString tempTrueSentiment(buffer2);  

    // Capture id from the second column until the end of line
    file2.getline(buffer2, 1000, '\n');  
    DSString tempId(buffer2);

        //compare all ids ids to the id of the tweet
        for (size_t i = 0; i < ids.size(); i++) {
            if (ids.at(i) == tempId) {
                tweetsClassified++;

                //If the sentiment is correct improve accuracy counter by one 
                if (guessedSentiments.at(i) == tempTrueSentiment) {
                    accuracyCounter++;
                    //inside loop print out guess and id and then skip line
                    outFile << guessedSentiments.at(i) << ","  << ids.at(i) << '\n';
                }
                //output a file with sentiments, correct id
                else{
                    outFile << guessedSentiments.at(i) << ","  << ids.at(i) << '\n';

                    //Create three vectors so can put percentage first in accuracy
                    DSString tempA = guessedSentiments.at(i);
                    DSString tempB = tempTrueSentiment;
                    DSString tempC = ids.at(i);

                    //push them to vector
                    forOutput.push_back(tempA);
                    forOutput2.push_back(tempB);
                    forOutput3.push_back(tempC);
                }
            }
        } 
     }

     //cout accuracy level and tweets it classified
    std::cout << "accuracy level: " << accuracyCounter << endl;
    std::cout << "totalTweetsAssesed: " << tweetsClassified << endl;
    percentage = (accuracyCounter*100)/tweetsClassified;
    
    //cout percent correct 
    std::cout << "percent correct: " << percentage <<"%" << endl;
    outFile2 << std::fixed << std::setprecision(3) <<percentage << "\n";
      //put percent into output files followed by the three parallel vectors created earlier for our information
      for (size_t i = 0; i < forOutput.size(); i++){
       outFile2 << forOutput.at(i) << "," << forOutput2.at(i) << "," << forOutput3.at(i) << '\n';
       }
    //close files
    outFile.close();
    outFile2.close();
}
