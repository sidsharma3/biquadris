#ifndef LEVEL1_H
#define LEVEL1_H
//level1.h file

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


class Level1 : public Level {
    public:
    Level1();
    std::deque<std::string*> sequence;
    Block* nextBlock() override;
    ~Level1();
};

#endif
