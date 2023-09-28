#include "SentimentAnalyzer.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "DSString.h"
#include "Word.h"
#include <map>
#include <iomanip>


//using namespace std;

void SentimentAnalyzer::train() {

    //CHANGE THE WAY THE FILE IS READ IN BEFORE SUBMITTING
    std::ifstream file("/users7/cse/rmukherji/assignment-2-don-t-be-sentimental-riamuk101/data/train_dataset_20k.csv");
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

   //for (auto& curDictWord : dictionary) { 
      // std:: cout << curDictWord.first << ' ' << curDictWord.second << endl; this prints out map
   // }
}

void SentimentAnalyzer::test() {
vector<DSString> forOutput;
//vector<DSString> forOutput1;
vector<DSString> forOutput2;
vector<DSString> forOutput3;
    std::ofstream outFile;
    std::ofstream outFile2;
    
    // Step 3: Open the file
    // If the file does not exist, it will be created.
    // If the file exists, its contents will be overwritten.
    outFile.open("output.txt");
    outFile2.open("output2.txt");
    
    // Check if the file is open
    if (!outFile) {
        throw std::invalid_argument("file could not be opened");
        std:: cout << "NO";
    }

    // Step 4: Write to the file
    // outFile << "Writing this text to the file.\n";
    // outFile << "C++ file handling is easy!\n";
    
    


    // Open the first file
    std::ifstream file("/users7/cse/rmukherji/assignment-2-don-t-be-sentimental-riamuk101/data/test_dataset_10k.csv");
    if (!file.good()) {
        throw std::invalid_argument("file could not be opened");
    }

    char buffer[10000];  // Buffer to store each field
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
        file.getline(buffer, 1000, '\n');  // Read until newline or 10000 characters
        DSString tweetDSString(buffer);

            //   std::cout << "Analyzing tweet: " << tweetDSString << std::endl;  // Output the tweet being analyzed
      
        vector<DSString> words = tweetDSString.tokenizeDSString();

        // ... Your existing code for analyzing the tweet
        for (size_t i = 0; i < words.size(); i++) {
            DSString lowerWord = (words.at(i).toLower());  // Convert word to lowercase
    auto indWord = dictionary.find(lowerWord);  // Lookup the lowercase word in dictionary

           // auto indWord = dictionary.find(words.at(i).toLower());
            if (indWord != dictionary.end()) {
                if (indWord->second > 0) {
                    counter++;
                } else if (indWord->second < 0) {
                    counter --;
                }
            }
        }

        if (counter > 0) {
            guessedSentiments.push_back("4");
        } else {
            guessedSentiments.push_back("0");
        }

        // std::cout << ids.at(idVectorCounter) << std::endl;
        // std::cout << guessedSentiments.at(idVectorCounter) << std::endl;
        // std::cout << counter << endl;
        counter = 0;
        idVectorCounter++;
    }

    // Open the second file

    std::ifstream file2("/users7/cse/rmukherji/assignment-2-don-t-be-sentimental-riamuk101/data/test_dataset_sentiment_10k.csv");
    if (!file2.good()) {
        throw std::invalid_argument("file could not be opened");
    }

    char buffer2[1000];
double accuracyCounter = 0;
double tweetsClassified = 0;

// Ignore header line
file2.ignore(1000, '\n');

while (file2.getline(buffer2, 1000, ',')) {
    DSString tempTrueSentiment(buffer2);  // Capture sentiment from the first column
   // std::cout << "Sentiment: " << tempTrueSentiment << std::endl;

    file2.getline(buffer2, 1000, '\n');  // Capture id from the second column until the end of line
    DSString tempId(buffer2);
   // std::cout << "ID: " << tempId << std::endl;

        for (int i = 0; i < ids.size(); i++) {
//std:: cout << " reaches here ";
            if (ids.at(i) == tempId) {
                tweetsClassified++;
              // std:: cout << " reaches here ";
                if (guessedSentiments.at(i) == tempTrueSentiment) {
                    accuracyCounter++;
outFile << guessedSentiments.at(i) << ","  << ids.at(i) << '\n';
                }
                else{
                    outFile << guessedSentiments.at(i) << ","  << ids.at(i) << '\n';
                     //outFile2 << guessedSentiments.at(i) << ", " << tempTrueSentiment << ", " << ids.at(i) << '\n';
                    //  DSString comma = ", ";
                    //  DSString trueSent= tempTrueSentiment;
                    //  DSString ID = ids.at(i);
                    // DSString ab = "hello";
                    // DSString ba = " there ";
                    DSString tempA = guessedSentiments.at(i);
                    DSString tempB = tempTrueSentiment;
                    DSString tempC = ids.at(i);
                     //DSString tempA = ab + ba;
                      //", " + tempTrueSentiment + ", " + ids.at(i));
                     forOutput.push_back(tempA);
                     forOutput2.push_back(tempB);
                     forOutput3.push_back(tempC);
                     //DSString a = guessedSentiments.at(i) + ", " + tempTrueSentiment + ", " + ids.at(i);
                     //cout << a << "\n";
                }
            }
        } 
        //delete[] buffer; 
        //delete[] buffer2;
         
   }
//     std :: cout << "first 3 id values" << ids.at(0) << " "<< ids.at(1) << " "<< ids.at(2) << " " << endl;
// std::cout <<" how many values in vector: " << ids.size() << endl;
//     std::cout << guessedSentiments.at(0) << " " << guessedSentiments.at(1) << " " << guessedSentiments.at(2);
    std::cout << "accuracy level: " << accuracyCounter << endl;
    std::cout << "totalTweetsAssesed: " << tweetsClassified << endl;
double percentage = (accuracyCounter*100)/tweetsClassified;
    // Your existing code for outputting or using 'accuracyCounter'

      std::cout << "percent correct: " << percentage <<"%" << endl;
     outFile2 << std::fixed << std::setprecision(3) <<percentage << "\n";
      for (size_t i = 0; i < forOutput.size(); i++){
       outFile2 << forOutput.at(i) << "," << forOutput2.at(i) << "," << forOutput3.at(i) << '\n';
       }
       // outFile2 << "C++ file handling is easy!\n";



    outFile.close();
    outFile2.close();
}
