#ifndef LEVEL2_H
#define LEVEL2_H
//level2.h file

// dependencies
#include "level.h"
#include "Block.h"
#include "Iblock.h"
#include "Lblock.h"
#include "jblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include <cstddef>
#include <string>
#include <memory>
#include <deque>
#include <iostream>
#include <fstream>


class Level2 : public Level {
    public:
    Level2();
    std::deque<std::string*> sequence;
    Block* nextBlock() override;
    ~Level2();
};

#endif

