#include <string>
#include <stdexcept>
#include "Block.h"
#include "cell.h"
#include <iostream>

// Renders the Transformed Block onto the actual Game Board Grid
void Block::render(std::vector<std::vector<Cell>> &theGrid) {
        for (size_t col=0; col < 4; col++) {
                theGrid.at(blockGrid.at(col).getRow()).at(blockGrid.at(col).getCol()).setVal(blockGrid.at(col).getVal());
        }
}      

// Erases the block from the grid
void Block::eraseBlock(std::vector<std::vector<Cell>> &theGrid) {
        for (size_t col=0; col < blockGrid.size(); col++) {
                theGrid.at(blockGrid.at(col).getRow()).at(blockGrid.at(col).getCol()).setVal(' ');
        }
}

bool Block::checkDown(std::vector<std::vector<Cell>> &theGrid) {
        eraseBlock(theGrid);
        // Checks to see if the below cells are used or not for IIII, if not moves down by one
        for (auto &it: blockGrid) {
                try {
                        if (!(theGrid.at(it.getRow() + 1).at(it.getCol()).getIsEmpty())) {
                                render(theGrid);
                                return false; // Indicates the below rows are taken up, hence dont do this action
                                // We can also call drop() here as well
                        } 
                } catch (const std::out_of_range& oor) { // Occurs when on the last row
                        render(theGrid);
                        return false;
                }
        }

        return true;
}



bool Block::down(std::vector<std::vector<Cell>> &theGrid) {
        
       if (checkDown(theGrid)) {

                // Now push all the blocks Y Values down by one
                for (auto &it: blockGrid) {
                        it.setRow(it.getRow() + 1);
                }
                origin.setRow(origin.getRow() + 1);
                // Rerender the block
                render(theGrid);
                return true;
       } 

        return false;
}

void Block::left(std::vector<std::vector<Cell>> &theGrid) {
        // Implemented for IIII
        // Check to see if any of the cells is already touching the left wall
        for (auto &it: blockGrid) {
                if (it.getCol() == 0) { return; } // If so, just stop
        }

        eraseBlock(theGrid);

        // Now check if any blocks already on the left or stop from moving it left
        for (auto &it: blockGrid) {
                try {
                        if (!(theGrid.at(it.getRow()).at(it.getCol() - 1).getIsEmpty())) {
                                render(theGrid); // Resets grid back to normal
                                return; // Indicates the left cols are taken up, hence dont do this action
                        } 
                } catch (const std::out_of_range& oor) { // Occurs when on the last row
                        return;
                }
        }
        
        // Now move the all the cells in the blocks left 1 unit
        for (auto &it: blockGrid) {
                it.setCol(it.getCol()-1);
        }
	
	origin.setCol(origin.getCol() - 1);

        render(theGrid);
}

void Block::right(std::vector<std::vector<Cell>> &theGrid) {
        // Implemented for IIII
        // Check to see if any of the cells is already touching the left wall
        for (auto &it: blockGrid) {
                if (it.getCol() == 10) { return; } // If so, just stop
        }
        eraseBlock(theGrid);
        // Now check if any blocks already on the right or stop from moving it right
        for (auto &it: blockGrid) {
                try {
                        if (!(theGrid.at(it.getRow()).at(it.getCol() + 1).getIsEmpty())) {
                                render(theGrid); // Resets grid back to normal
                                return; // Indicates the left cols are taken up, hence dont do this action
                        } 
                } catch (const std::out_of_range& oor) { // Occurs when on the last row
                        return;
                }
        }
        
        // Now move the all the cells in the blocks left 1 unit
        for (auto &it: blockGrid) {
                it.setCol(it.getCol()+1);
        }
	
	origin.setCol(origin.getCol() + 1);

        render(theGrid);
}

void Block::drop(std::vector<std::vector<Cell>> &theGrid) {
        while (checkDown(theGrid)) {
                // Now push all the blocks Y Values down by one
                for (auto &it: blockGrid) {
                        it.setRow(it.getRow() + 1);
                }
                origin.setRow(origin.getRow() + 1);
                // Rerender the block
                render(theGrid);
        }
}

bool Block::checkRotate(Cell c1, Cell c2, Cell c3, Cell c4){
	bool answer = true;
	try {
		if(!c1.getIsEmpty()){
			answer = false;
		}
		if(!c2.getIsEmpty()){
			answer = false;
		}
		if(!c3.getIsEmpty()){
			answer = false;
		}
		if(!c4.getIsEmpty()){
			answer = false;
		}
	} catch (const std::out_of_range& oor) { // Occurs when on the last row
                answer = false;
        }
	return answer;
}
