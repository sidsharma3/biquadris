#ifndef LEVEL_H
#define LEVEL_H
//level.h file

// dependencies
#include <deque>
#include <string>
#include <iostream>
#include <fstream>
#include "Block.h"
#include "Iblock.h"
#include "Lblock.h"
#include "jblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"

// Level Class:
// Abstract class for a level in the game.
// This implementation allows for minimal recompilation
// when adding new levels.

class Level {
    public:
    std::deque<std::string*> sequence;

    // Factory Method Pattern; each level's nextBlock uses
    // different rules based on the level#.
    virtual Block* nextBlock() = 0;

    virtual Block * nextBlockSequence();

    // Pure Virtual Dtor; prevents creation of Level objects
    virtual ~Level() = 0;

    // readSequence; each level can generate sequence from a file
    // rather than (pseudo)randomly.
    void readSequence(std::string filename);

    void setSequence(std::string filename);

    void setSeed(unsigned int seed);

    int getMoves();
    virtual void add1Moves();
    void resetMoves();
    bool dropStar();
    protected:
    int moves = 0;
};

#endif
