#include <iostream>
#include "SentimentAnalyzer.h"
#include "DSString.h"
#include <chrono>

int main(int argc, char** argv)
{   
   
    //create sentiment analyzer object
    SentimentAnalyzer sa;

    // Record start time for training
    auto startTrain = std::chrono::high_resolution_clock::now();
    
    //pass in argv[1] as first file
        sa.train(argv[1]);
    

    // Record end time for training
    auto finishTrain = std::chrono::high_resolution_clock::now();
    // Compute and print the elapsed time for training
    std::chrono::duration<double> elapsedTrain = finishTrain - startTrain;
    std::cout << "Training elapsed time: " << elapsedTrain.count() << " seconds" << std::endl;

    // Record start time for testing
    auto startTest = std::chrono::high_resolution_clock::now();
    //pass in argv[2], argv[2], argv[2], argv[2], argv[2]
        sa.test(argv[2],argv[3],argv[4],argv[5]);


    // Record end time for testing
    auto finishTest = std::chrono::high_resolution_clock::now();
    // Compute and print the elapsed time for testing
    std::chrono::duration<double> elapsedTest = finishTest - startTest;
    std::cout << "Testing elapsed time: " << elapsedTest.count() << " seconds" << std::endl;

    
    return 0;
}