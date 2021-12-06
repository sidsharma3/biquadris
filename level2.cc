// level2.cc file

// dependencies
#include "level2.h"
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

// default ctor; no sequence
Level2::Level2() {}

// nextBlock for Level2
Block* Level2::nextBlock() {
    if (sequence.empty()) {
        const int num = rand() % 7;
        // std::cout << num;
        if (num==0) {
            return new IBlock{};
        } else if (num==1) {
            return new JBlock{};
        } else if (num==2) {
            return new LBlock{};
        } else if (num==3) {
            return new OBlock{};
        } else if (num==4) {
            return new SBlock{};
        } else if (num==5) {
            return new ZBlock{};
        } else if (num==6) {
            return new TBlock{};
        }
    } else {
        return nextBlockSequence();
    }
    return new IBlock{};
}

// dtor
Level2::~Level2(){};

