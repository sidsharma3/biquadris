#ifndef LEVEL4_H
#define LEVEL4_H
//level4.h file

// dependencies
#include "level.h"
#include "levelAdvanced.h"
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


class Level4 : public LevelAdvanced {
    public:
    Level4();
    std::deque<std::string*> sequence;
    void add1Moves() override;
    ~Level4();
};

#endif

