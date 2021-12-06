// levelAdvanced.cc file

// dependencies
#include "levelAdvanced.h"
#include <cstddef>
#include <string>
#include <memory>
#include <vector>
#include <deque>
#include <iostream>
#include <fstream>
#include "level.h"
#include "Block.h"
#include "Iblock.h"
#include "Lblock.h"
#include "jblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"

// nextBlock for LevelAdvanced
Block* LevelAdvanced::nextBlock() {
    if (sequence.empty()){
        const int num = rand() % 9;
        // std::cout << num;
        if (num==0) {
            return new IBlock{true};
        } else if (num==1) {
            return new JBlock{true};
        } else if (num==2) {
            return new LBlock{true};
        } else if (num==3) {
            return new OBlock{true};
        } else if (num==4 || num==5) {
            return new SBlock{true};
        } else if (num==6 || num==7) {
            return new ZBlock{true};
        } else if (num==8) {
            return new TBlock{true};
        }
    } else {
        return LevelAdvanced::nextBlockSequence();
    }
    return new IBlock{true};
}

Block* LevelAdvanced::nextBlockSequence() {
    // showdq(sequence);
    std::string *temp = this->sequence.front();
    // std::cout << "temp: " << *temp << std::endl;
    this->sequence.pop_front();
    this->sequence.emplace_back(temp);

    if (*temp == "I") {
        std::cout << "giving iBlock" << std::endl;
        return new IBlock{true};
    } else if (*temp=="J") {
        std::cout << "giving jBlock" << std::endl;
        return new JBlock{true};
    } else if (*temp=="L") {
        std::cout << "giving lBlock" << std::endl;
        return new LBlock{true};
    } else if (*temp=="O") {
        std::cout << "giving oBlock" << std::endl;
        return new OBlock{true};
    } else if (*temp=="S") {
        std::cout << "giving sBlock" << std::endl;
        return new SBlock{true};
    } else if (*temp=="Z") {
        std::cout << "giving zBlock" << std::endl;
        return new ZBlock{true}; 
    } else if (*temp=="T") {
        std::cout << "giving tBlock" << std::endl;
        return new TBlock{true};
    }
    return new IBlock{true};
}

// dtor
LevelAdvanced::~LevelAdvanced(){};

