#ifndef LEVEL0_H
#define LEVEL0_H
//level0.h file

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


class Level0 : public Level {
    public:
    Level0(std::string filename);
    std::deque<std::string*> sequence;
    Block* nextBlock() override;
    ~Level0();
};

#endif
