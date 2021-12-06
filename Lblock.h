#ifndef LBLOCK_H
#define LBLOCK_H
#include <string>
#include "Block.h"

class Cell;

class LBlock : public Block {
    public:
    LBlock(bool _isHeavy, int _points, std::string _orientation, Cell origin);
    LBlock(bool _isHeavy, int _points, std::string _orientation);
    LBlock(bool _isHeavy);
    LBlock();
    void clockwise(std::vector<std::vector<Cell>> &theGrid) override;
    void counterClockwise(std::vector<std::vector<Cell>> &theGrid) override;
};

#endif

