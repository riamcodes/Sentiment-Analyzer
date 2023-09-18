#include<vector>

std::vector<DSString> tokenizeDSString(const DSString &phrase) {
    //char* currentChar = phrase.c_str();
    std::vector<DSString> words;
    size_t counter = 0;

    DSString currentWord;
    for (size_t i = 0; i < phrase.length(); ++i){
      char currentChar = phrase[i];
      if (currentChar = ' '){
        currentWord = phrase.substr(counter,i-counter);
        words.push_back(currentWord);
        counter = i;
      }
    }

  }