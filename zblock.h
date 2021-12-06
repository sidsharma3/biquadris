#ifndef ZBLOCK_H
#define ZBLOCK_H
#include <string>
#include "Block.h"

class Cell;

class ZBlock : public Block {
    public:
    ZBlock(bool _isHeavy, int _points, std::string _orientation, Cell origin);
    ZBlock(bool _isHeavy, int _points, std::string _orientation);
    ZBlock(bool _isHeavy);
    ZBlock();
    void clockwise(std::vector<std::vector<Cell>> &theGrid) override;
    void counterClockwise(std::vector<std::vector<Cell>> &theGrid) override;
};

#endif