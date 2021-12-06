#ifndef JBLOCK_H
#define JBLOCK_H
#include <string>
#include "Block.h"

class Cell;

class JBlock : public Block {
    public:
    JBlock(bool _isHeavy, int _points, std::string _orientation, Cell origin);
    JBlock(bool _isHeavy, int _points, std::string _orientation);
    JBlock(bool _isHeavy);
    JBlock();
    void clockwise(std::vector<std::vector<Cell>> &theGrid) override;
    void counterClockwise(std::vector<std::vector<Cell>> &theGrid) override;
};

#endif
