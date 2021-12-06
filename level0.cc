// level0.cc file

// dependencies
#include <cstddef>
#include <string>
#include <memory>
#include <vector>
#include <deque>
#include <iostream>
#include <fstream>
#include "level.h"
#include "level0.h"
#include "Block.h"
#include "Iblock.h"
#include "Lblock.h"
#include "jblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"

// default ctor; uses file for sequence
Level0::Level0(std::string filename) {
    readSequence(filename);
}

/*
void showdq2(std::deque<std::string *> g) 
{ 
    std::deque<std::string *>::iterator it; 
    for (it = g.begin(); it != g.end(); ++it) 
        std::cout << '\t' << **it;


    std::cout << *(g.at(0)) << std::endl;
    std::cout << '\n'; 
} 
*/

// nextBlock functionality for Level0
Block* Level0::nextBlock() {
    return nextBlockSequence();
}

// dtor
Level0::~Level0(){};
