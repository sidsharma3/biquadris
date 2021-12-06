#include "cell.h"

// Commentary in cell.h

Cell::Cell(){}

Cell::Cell(size_t row, size_t col, char val, bool isEmpty): row{row}, col{col}, val{val}, isEmpty{isEmpty} {}

void Cell::setRow(int newRow) { row = newRow; }

void Cell::setCol(int newCol) { col = newCol; }

void Cell::setVal(char newVal) { 
    val = newVal;
    isEmpty = (val == ' ') ? true : false;  // Changes to is empty if now empty cell
}

int Cell::getRow(){ return row; }

int Cell::getCol() { return col; }

char Cell::getVal() { return val; }

bool Cell::getIsEmpty() { return isEmpty; }
