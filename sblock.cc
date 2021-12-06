#include <string>
#include <stdexcept>
#include "sblock.h"
#include "cell.h"
#include <iostream>

// Still lots more to do, ie Function ovverides and all, but its for reference 
SBlock::SBlock(bool _isHeavy, int _points, std::string _orientation, Cell _origin) {
        isHeavy = _isHeavy;
        points = _points;
        orientation = "flatLeft";
	    origin = _origin;
        blockType=Type::S;
        blockGrid.emplace_back(Cell{3,1,'S',false});
        blockGrid.emplace_back(Cell{3,2,'S',false});
        // Sets up the cells for the SBlock
        for (size_t col=0; col < 2; col++) {
                blockGrid.emplace_back(Cell{4, col, 'S',false});
        }
}

SBlock::SBlock(bool _isHeavy, int _points, std::string _orientation) {
        isHeavy = _isHeavy;
        points = _points;
        orientation = "flatLeft";
        blockType=Type::S;
		origin = Cell{4,0,' ', true};
        blockGrid.emplace_back(Cell{3,1,'S',false});
        blockGrid.emplace_back(Cell{3,2,'S',false});
        // Sets up the cells for the SBlock
        for (size_t col=0; col < 2; col++) {
                blockGrid.emplace_back(Cell{4, col, 'S',false});
        }
}

SBlock::SBlock(bool _isHeavy) {
        isHeavy = _isHeavy;
        points = 0;
        orientation = "flatLeft";
        blockType=Type::S;
		origin = Cell{4,0,' ', true};
        blockGrid.emplace_back(Cell{3,1,'S',false});
        blockGrid.emplace_back(Cell{3,2,'S',false});
        // Sets up the cells for the SBlock
        for (size_t col=0; col < 2; col++) {
                blockGrid.emplace_back(Cell{4, col, 'S',false});
        }
}

SBlock::SBlock() {
        isHeavy = false;
        points = 0;
        orientation = "flatLeft";
        blockType=Type::O;
		origin = Cell{4,0,' ', true};
        blockGrid.emplace_back(Cell{3,1,'S',false});
        blockGrid.emplace_back(Cell{3,2,'S',false});
        // Sets up the cells for the SBlock
        for (size_t col=0; col < 2; col++) {
                blockGrid.emplace_back(Cell{4, col, 'S',false});
        }
}

// Needs to be done
void SBlock::clockwise(std::vector<std::vector<Cell>> &theGrid) {
		eraseBlock(theGrid);
	std::vector<Cell> blockGridCopy{blockGrid};
	int index=0;
	if(orientation == "flatLeft") {
		bool posRotate = true;
		posRotate = checkRotate((theGrid.at(origin.getRow()).at(origin.getCol() + 1)),
			(theGrid.at(origin.getRow() - 1).at(origin.getCol() + 1)),(theGrid.at(origin.getRow() - 1).at(origin.getCol())),
		(theGrid.at(origin.getRow() - 2).at(origin.getCol())));
		if(posRotate){
		for(auto &it: blockGrid){
			if((origin.getCol() == blockGridCopy.at(index).getCol()) && (origin.getRow() == blockGridCopy.at(index).getRow())){
				it.setCol(origin.getCol() + 1);
				it.setRow(origin.getRow());
			}
			if((origin.getCol() + 1 == blockGridCopy.at(index).getCol()) && (origin.getRow() == blockGridCopy.at(index).getRow())){
				it.setCol(origin.getCol() + 1);
				it.setRow(origin.getRow() - 1);
			}
			if((origin.getCol() + 1 == blockGridCopy.at(index).getCol()) && (origin.getRow() - 1 == blockGridCopy.at(index).getRow())){
				it.setCol(origin.getCol());
				it.setRow(origin.getRow() - 1);
			}
			if((origin.getCol() + 2 == blockGridCopy.at(index).getCol()) && (origin.getRow() - 1 == blockGridCopy.at(index).getRow())){
				it.setCol(origin.getCol());
				it.setRow(origin.getRow() - 2);
			}
			index++;

		}

		orientation = "vertRight";
		}
	} else if(orientation == "vertRight"){
		bool posRotate = true;
		posRotate = checkRotate((theGrid.at(origin.getRow() - 1).at(origin.getCol())),
			(theGrid.at(origin.getRow() - 1).at(origin.getCol() + 1)),(theGrid.at(origin.getRow()).at(origin.getCol() + 1)),
		(theGrid.at(origin.getRow()).at(origin.getCol() + 2)));
		if(posRotate){
		for(auto &it: blockGrid){
			if((origin.getCol() == blockGridCopy.at(index).getCol()) && (origin.getRow() - 1 == blockGridCopy.at(index).getRow())){
				it.setCol(origin.getCol());
				it.setRow(origin.getRow() - 1);
			}
			if((origin.getRow() - 1 == blockGridCopy.at(index).getRow()) && (origin.getCol() + 1 == blockGridCopy.at(index).getCol())){
				it.setCol(origin.getCol() + 1);
				it.setRow(origin.getRow() - 1);
			}
			if((origin.getRow() - 2 == blockGridCopy.at(index).getRow()) && (origin.getCol() == blockGridCopy.at(index).getCol())){
				it.setCol(origin.getCol() + 1);
				it.setRow(origin.getRow());
			}
			if((origin.getRow() == it.getRow()) && (origin.getCol() + 1 == blockGridCopy.at(index).getCol())){
				it.setCol(origin.getCol() + 2);
				it.setRow(origin.getRow());
			}
			index++;

		}

	orientation = "flatRight";
		}
	} else if(orientation == "flatRight"){
		bool posRotate = true;
		posRotate = checkRotate((theGrid.at(origin.getRow() - 1).at(origin.getCol())),
			(theGrid.at(origin.getRow() - 1).at(origin.getCol())),(theGrid.at(origin.getRow() - 1).at(origin.getCol() + 1)),
		(theGrid.at(origin.getRow() - 2).at(origin.getCol() + 1)));
		if(posRotate){
		for(auto &it: blockGrid){
			if((origin.getCol() == blockGridCopy.at(index).getCol()) && (origin.getRow() - 1 == blockGridCopy.at(index).getRow())){
				it.setCol(origin.getCol());
				it.setRow(origin.getRow());
			}
			if((origin.getRow() - 1 == blockGridCopy.at(index).getRow()) && (origin.getCol() + 1 == blockGridCopy.at(index).getCol())){
				it.setCol(origin.getCol());
				it.setRow(origin.getRow() - 1);
			}
			if((origin.getRow() == blockGridCopy.at(index).getRow()) && (origin.getCol() + 1 == blockGridCopy.at(index).getCol())){
				it.setCol(origin.getCol() + 1);
				it.setRow(origin.getRow() - 1);
			}
			if((origin.getRow() == it.getRow()) && (origin.getCol() + 2 == blockGridCopy.at(index).getCol())){
				it.setCol(origin.getCol() + 1);
				it.setRow(origin.getRow() - 2);
			}
			index++;

		}

	orientation = "vertLeft";
		}
	} else if(orientation == "vertLeft"){
		bool posRotate = true;
		posRotate = checkRotate((theGrid.at(origin.getRow()).at(origin.getCol() + 1)),
			(theGrid.at(origin.getRow()).at(origin.getCol() + 1)),(theGrid.at(origin.getRow() - 1).at(origin.getCol() + 1)),
		(theGrid.at(origin.getRow() - 1).at(origin.getCol() + 2)));
		if(posRotate){
		for(auto &it: blockGrid){
			if((origin.getCol() == blockGridCopy.at(index).getCol()) && (origin.getRow() == blockGridCopy.at(index).getRow())){
				it.setCol(origin.getCol());
				it.setRow(origin.getRow());
			}
			if((origin.getRow() - 1 == blockGridCopy.at(index).getRow()) && (origin.getCol() == blockGridCopy.at(index).getCol())){
				it.setCol(origin.getCol() + 1);
				it.setRow(origin.getRow());
			}
			if((origin.getRow() - 1 == blockGridCopy.at(index).getRow()) && (origin.getCol() + 1 == blockGridCopy.at(index).getCol())){
				it.setCol(origin.getCol() + 1);
				it.setRow(origin.getRow() - 1);
			}
			if((origin.getRow() - 2 == it.getRow()) && (origin.getCol() + 1 == blockGridCopy.at(index).getCol())){
				it.setCol(origin.getCol() + 2);
				it.setRow(origin.getRow() - 1);
			}
			index++;

		}

	orientation = "flatLeft";
	}
	}
	
	render(theGrid);
}

void SBlock::counterClockwise(std::vector<std::vector<Cell>> &theGrid) {
	clockwise(theGrid);
	clockwise(theGrid);
	clockwise(theGrid);
}
