#ifndef BLOCK_H
#define BLOCK_H

#include <cstddef>
#include <string>
#include <vector>
#include "cell.h"

class Block {
    public:
    enum class Type {I, J, L, O, S, Z, T};
    enum class Orientation {N, CW1, CW2, CW3};
    Cell origin;
    protected:
    bool isHeavy;
    int points;
    std::string orientation;
    Type blockType;
    //std::vector<Cell> blockGrid;
    public:
    std::vector<Cell> blockGrid;
    virtual ~Block()=default;
    void eraseBlock(std::vector<std::vector<Cell>> &theGrid);
    bool checkDown(std::vector<std::vector<Cell>> &theGrid);
    void render(std::vector<std::vector<Cell>> &theGrid); // Initially render on top left
    bool down(std::vector<std::vector<Cell>> &theGrid); // Bring block down 1 row
    void left(std::vector<std::vector<Cell>> &theGrid); // Shift block left 1 col
    void right(std::vector<std::vector<Cell>> &theGrid); // Shift block right 1 col
    void drop(std::vector<std::vector<Cell>> &theGrid); // Drop block into grid
    virtual void clockwise(std::vector<std::vector<Cell>> &theGrid)=0; // Rotate block clockwise
    virtual void counterClockwise(std::vector<std::vector<Cell>> &theGrid)=0; // Roate block counterclockwise
    bool checkRotate(Cell c1, Cell c2, Cell c3, Cell c4);
};


#endif
