// level1.cc file

// dependencies
#include <cstddef>
#include <string>
#include <memory>
#include <vector>
#include <deque>
#include <iostream>
#include <fstream>
#include "level.h"
#include "level1.h"
#include "Block.h"
#include "Iblock.h"
#include "Lblock.h"
#include "jblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"

// default ctor; no sequence
Level1::Level1() {}

// nextBlock for Level1
Block* Level1::nextBlock() {
    if (sequence.empty()) {
        const int num = rand() % 12;
        // std::cout << num;
        if (num== 0 || num==1) {
            return new IBlock{};
        } else if (num==2 || num==3) {
            return new JBlock{};
        } else if (num==4 || num==5) {
            return new LBlock{};
        } else if (num==6 || num == 7) {
            return new OBlock{};
        } else if (num==8) {
            return new SBlock{};
        } else if (num==9) {
            return new ZBlock{};
        } else if (num==10 || num==11) {
            return new TBlock{};
        }
    } else {
        return nextBlockSequence();
    }
    return new IBlock{};
}


// dtor
Level1::~Level1(){};
