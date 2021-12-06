#ifndef LEVEL3_H
#define LEVEL3_H
//level3.h file

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


class Level3 : public LevelAdvanced {
    public:
    Level3();
    std::deque<std::string*> sequence;
    ~Level3();
};

#endif
