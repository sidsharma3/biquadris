#ifndef OBLOCK_H
#define OBLOCK_H
#include <string>
#include "Block.h"

class Cell;

class OBlock : public Block {
    public:
    OBlock(bool _isHeavy, int _points, std::string _orientation, Cell origin);
    OBlock(bool _isHeavy, int _points, std::string _orientation);
    OBlock(bool _isHeavy);
    OBlock();
    void clockwise(std::vector<std::vector<Cell>> &theGrid) override;
    void counterClockwise(std::vector<std::vector<Cell>> &theGrid) override;
};

#endif