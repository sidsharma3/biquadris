#ifndef __CELL_H__
#define __CELL_H__
#include <cstddef>

class Cell {
    size_t row;
    size_t col;
    char val;
    bool isEmpty;
    public:
    Cell();
    Cell(size_t row, size_t col, char val, bool isEmpty);
    void setRow(int newRow); // Sets the Row Coord
    void setCol(int newCol); // Sets the Col Coord
    void setVal(char newVal); // Changes value of Cell and changes if its empty
    int getRow(); // Gets the Row Coord
    int getCol(); // Gets the Col Coord
    char getVal(); // Gets the value at Cell (x,y)
    bool getIsEmpty();
};


#endif
