
#ifndef WORD_H
#define WORD_H
#include "DSString.h"

struct Word {
    int posCount = 0;
    int negCount = 0;
    DSString content;

    void addData(int posCount, int negCount) {
        
        //this->content = content; content is already the first part of the map
        this->posCount += posCount;
        this->negCount += negCount;
    }
};

#endif 