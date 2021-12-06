#ifndef TBLOCK_H
#define TBLOCK_H
#include <string>
#include "Block.h"

class Cell;

class TBlock : public Block {
    public:
    TBlock(bool _isHeavy, int _points, std::string _orientation, Cell origin);
    TBlock(bool _isHeavy, int _points, std::string _orientation);
    TBlock(bool _isHeavy);
    TBlock();
    void clockwise(std::vector<std::vector<Cell>> &theGrid) override;
    void counterClockwise(std::vector<std::vector<Cell>> &theGrid) override;
};

#endif