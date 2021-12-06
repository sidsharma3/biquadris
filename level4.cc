// level4.cc file

// dependencies
#include "level4.h"
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

// default ctor; no sequence
Level4::Level4() {}

void Level4::add1Moves() {
    moves++;
}

// dtor
Level4::~Level4(){};
