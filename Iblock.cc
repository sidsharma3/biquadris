#include <string>
#include <stdexcept>
#include "Iblock.h"
#include "cell.h"
#include <iostream>

// Still lots more to do, ie Function ovverides and all, but its for reference 
IBlock::IBlock(bool _isHeavy, int _points, std::string _orientation, Cell _origin) {
        isHeavy = _isHeavy;
        points = _points;
        orientation = "flat";
	    origin = _origin;
        blockType=Type::I;
        // Sets up the cells for the IBlock
        for (size_t col=0; col < 4; col++) {
                blockGrid.emplace_back(Cell{3, col, 'I',false});
        }
}

IBlock::IBlock(bool _isHeavy, int _points, std::string _orientation) {
        isHeavy = _isHeavy;
        points = _points;
        orientation = "flat";
        blockType=Type::I;
		origin = Cell{3,0,' ', true};
        // Sets up the cells for the IBlock
        for (size_t col=0; col < 4; col++) {
                blockGrid.emplace_back(Cell{3, col, 'I',false});
        }
}

IBlock::IBlock() {
        isHeavy = false;
        points = 0;
        orientation = "flat";
        blockType=Type::I;
		origin = Cell{3,0,' ', true};
        // Sets up the cells for the IBlock
        for (size_t col=0; col < 4; col++) {
                blockGrid.emplace_back(Cell{3, col, 'I',false});
        }
}

IBlock::IBlock(bool _isHeavy) {
        isHeavy = _isHeavy;
        points = 0;
        orientation = "flat";
        blockType=Type::I;
		origin = Cell{3,0,' ', true};
        // Sets up the cells for the IBlock
        for (size_t col=0; col < 4; col++) {
                blockGrid.emplace_back(Cell{3, col, 'I',false});
        }
}


void IBlock::clockwise(std::vector<std::vector<Cell>> &theGrid) {
    // Cover scenario where it is on extreme right or extreme left
	eraseBlock(theGrid);

	if(orientation == "flat"){
		bool posRotate = true;
		posRotate = checkRotate((theGrid.at(origin.getRow() - 1).at(origin.getCol())),
			(theGrid.at(origin.getRow() - 2).at(origin.getCol())),(theGrid.at(origin.getRow() - 3).at(origin.getCol())),
		(theGrid.at(origin.getRow() - 3).at(origin.getCol())));
		if(posRotate){	
			for(auto &it: blockGrid) {	
				if (origin.getCol() + 1 == it.getCol()) {
					it.setCol(origin.getCol());
					it.setRow(origin.getRow() - 1);	
				}
			}
			for(auto &it: blockGrid) {
				if (origin.getCol() + 2 == it.getCol()) {
					it.setCol(origin.getCol());
					it.setRow(origin.getRow() - 2);	
				}
			}
			for(auto &it: blockGrid) {
				if (origin.getCol() + 3 == it.getCol()) {
					it.setCol(origin.getCol());
					it.setRow(origin.getRow() - 3);	
				}
			}
			orientation = "vertical";
		}
	} else {
		bool posRotate = true;
		posRotate = checkRotate((theGrid.at(origin.getRow()).at(origin.getCol() + 1)),
			(theGrid.at(origin.getRow()).at(origin.getCol() + 2)),(theGrid.at(origin.getRow()).at(origin.getCol() + 3)),
		(theGrid.at(origin.getRow()).at(origin.getCol() + 3)));
		if(posRotate){
		for(auto &it: blockGrid) {
			if (origin.getRow() - 1 == it.getRow()) {
				it.setRow(origin.getRow());
				it.setCol(origin.getCol() + 1);	
			}
		}
		for(auto &it: blockGrid) {
			if (origin.getRow() - 2 == it.getRow()) {
				it.setRow(origin.getRow());
				it.setCol(origin.getCol() + 2);	
			}
		}
		for(auto &it: blockGrid) {
			if (origin.getRow() - 3 == it.getRow()) {
				it.setRow(origin.getRow());
				it.setCol(origin.getCol() + 3);	
			}
		}

		orientation = "flat";
	}
	}
	render(theGrid);
}

void IBlock::counterClockwise(std::vector<std::vector<Cell>> &theGrid) {
	eraseBlock(theGrid);

	if(orientation == "flat"){
		
		for(auto &it: blockGrid) {
			if (origin.getCol() + 1 == it.getCol()) {
				it.setCol(origin.getCol());
				it.setRow(origin.getRow() - 1);	
			}
		}
		for(auto &it: blockGrid) {
			if (origin.getCol() + 2 == it.getCol()) {
				it.setCol(origin.getCol());
				it.setRow(origin.getRow() - 2);	
			}
		}
		for(auto &it: blockGrid) {
			if (origin.getCol() + 3 == it.getCol()) {
				it.setCol(origin.getCol());
				it.setRow(origin.getRow() - 3);	
			}
		}
		orientation = "vertical";
	} else {
		for(auto &it: blockGrid) {
			if (origin.getRow() - 1 == it.getRow()) {
				it.setRow(origin.getRow());
				it.setCol(origin.getCol() + 1);	
			}
		}
		for(auto &it: blockGrid) {
			if (origin.getRow() - 2 == it.getRow()) {
				it.setRow(origin.getRow());
				it.setCol(origin.getCol() + 2);	
			}
		}
		for(auto &it: blockGrid) {
			if (origin.getRow() - 3 == it.getRow()) {
				it.setRow(origin.getRow());
				it.setCol(origin.getCol() + 3);	
			}
		}

		orientation = "flat";
	}
	render(theGrid);
}

