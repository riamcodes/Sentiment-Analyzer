#include "DSString.h"

struct Word {
    int posCount = 0;
    int negCount = 0;
    DSString content;

    Word(DSString content, int posCount, int negCount) {
        this->content = content;
        this->posCount = posCount;
        this->negCount = negCount;
    }
};