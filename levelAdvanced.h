#ifndef LEVELADVANCED_H
#define LEVELADVANCED_H
//levelAdvanced.h file

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


class LevelAdvanced : public Level {
    public:
    std::deque<std::string*> sequence;
    Block* nextBlock() override;
    Block* nextBlockSequence() override;
    virtual ~LevelAdvanced() = 0;
};

#endif

