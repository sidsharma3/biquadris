#ifndef SBLOCK_H
#define SBLOCK_H
#include <string>
#include "Block.h"

class Cell;

class SBlock : public Block {
    public:
    SBlock(bool _isHeavy, int _points, std::string _orientation, Cell origin);
    SBlock(bool _isHeavy, int _points, std::string _orientation);
    SBlock(bool _isHeavy);
    SBlock();
    void clockwise(std::vector<std::vector<Cell>> &theGrid) override;
    void counterClockwise(std::vector<std::vector<Cell>> &theGrid) override;
};

#endif