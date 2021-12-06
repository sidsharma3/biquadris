//level.cc file

// dependencies
#include "level.h"
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

// for testing
/* commentted out test printers
void showdq(std::deque<std::string *> g) { 
    std::deque<std::string *>::iterator it; 
    for (it = g.begin(); it != g.end(); ++it) 
        std::cout << '\t' << **it; 
    std::cout << '\n'; 
}
*/


// makes a deque of Blocks to use in Level0,
// which are read from the file, filename.txt.
void Level::readSequence (std::string filename) {
    // open file and push the read blocks into sequence
    std::ifstream fin(filename + ".txt");
    std::string blk;
    while (fin >> blk) {
        // std::cout << blk << " into sequence" << std::endl;
        std::string * temp = new std::string(blk);
        sequence.emplace_back(temp);
        
    }
        // std::cout << *(sequence.at(0)) << std::endl;
        // std::cout << "seq filled" << std::endl;
        // showdq(sequence);
}

Block* Level::nextBlockSequence() {
    // showdq(sequence);
    std::string *temp = this->sequence.front();
    // std::cout << "temp: " << *temp << std::endl;
    this->sequence.pop_front();
    this->sequence.emplace_back(temp);

    if (*temp == "I") {
        std::cout << "giving iBlock" << std::endl;
        return new IBlock{};
    } else if (*temp=="J") {
        std::cout << "giving jBlock" << std::endl;
        return new JBlock{};
    } else if (*temp=="L") {
        std::cout << "giving lBlock" << std::endl;
        return new LBlock{};
    } else if (*temp=="O") {
        std::cout << "giving oBlock" << std::endl;
        return new OBlock{};
    } else if (*temp=="S") {
        std::cout << "giving sBlock" << std::endl;
        return new SBlock{};
    } else if (*temp=="Z") {
        std::cout << "giving zBlock" << std::endl;
        return new ZBlock{}; 
    } else if (*temp=="T") {
        std::cout << "giving tBlock" << std::endl;
        return new TBlock{};
    }
    return new IBlock{};
}


// if a level wants to use sequence
void Level::setSequence(std::string filename) {
    readSequence(filename);
}

// if a level wants to change it's rand's seed
// does nothing if the level is using a sequence
void Level::setSeed(unsigned int seed) {
    srand(seed);
}



int Level::getMoves() {
    return moves;
}
void Level::add1Moves() {}

void Level::resetMoves() {
    moves = 0;
}

bool Level::dropStar() {
    return ((moves - 1) % 5 == 0) ? true : false;
}
// virtual destructor
Level::~Level(){}
