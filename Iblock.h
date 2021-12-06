#ifndef IBLOCK_H
#define IBLOCK_H
#include <string>
#include "Block.h"

class Cell;

class IBlock : public Block {
    public:
    IBlock(bool _isHeavy, int _points, std::string _orientation, Cell origin);
    IBlock(bool _isHeavy, int _points, std::string _orientation);
    IBlock(bool _isHeavy);
    IBlock();
    void clockwise(std::vector<std::vector<Cell>> &theGrid) override;
    void counterClockwise(std::vector<std::vector<Cell>> &theGrid) override;
};

#endif
