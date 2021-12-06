#ifndef SAMPLE_SUBJECT_H
#define SAMPLE_SUBJECT_H

#include <cstddef>
#include <string>
#include <memory>
#include <vector>
#include "subject.h"
#include "info.h"
#include "cell.h"
#include "Block.h"
#include "Iblock.h"
#include "jblock.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "levelAdvanced.h"
#include "level3.h"
#include "level4.h"
#include <deque>

// Pseudo use for Player, before player is truly implemented
class sampleSubject : public Subject<Info> {
    std::vector<std::vector<Cell>> theGrid;
    size_t playerNum;
    std::vector<std::unique_ptr<Block>>prevBlocks;
    int level;
    int score;
    std::string sequence;
    Level* curLevel;
    public:
    sampleSubject(size_t playerNum, int level, int score, std::string sequence, Observer<Info> &display);
    Info getInfo() const override;
    void renderBlock();
    void down();
    void drop();
    void left();
    void right();
    void clockwise();
    void counterClockwise();
    bool rowCheck(size_t rowNum);
    void colDown(size_t colNum, size_t rowNum); // Brings all cells above rowNum in column colNum down by one
    void clearRow(size_t rowNum); //Clears row rowNum, and then brings all rows above that down by one
    void clearCheck(); // Checks to see how many rows one has cleared
    void levelUp();
    void levelDown();
    void setSequence(std::string seq);
    void setSeed(unsigned int seed);
    public:
	bool heavy = false;
        bool blinded = false;

};

#endif

