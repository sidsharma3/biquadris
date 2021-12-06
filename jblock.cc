#include <string>
#include <stdexcept>
#include "jblock.h"
#include "cell.h"
#include <utility>
#include <iostream>

// Still lots more to do, ie Function ovverides and all, but its for reference 
JBlock::JBlock(bool _isHeavy, int _points, std::string _orientation, Cell _origin) {
        isHeavy = _isHeavy;
        points = _points;
        orientation = "flatLeft";
	    origin = _origin;
        blockType=Type::J;
        blockGrid.emplace_back(Cell{4,0,'J',false});
        // Sets up the cells for the JBlock
        for (size_t col=0; col < 3; col++) {
                blockGrid.emplace_back(Cell{4, col, 'J',false});
        }
}

JBlock::JBlock(bool _isHeavy, int _points, std::string _orientation) {
        isHeavy = _isHeavy;
        points = _points;
        orientation = "flatLeft";
        blockType=Type::J;
		origin = Cell{4,0,' ', true};
        blockGrid.emplace_back(Cell{3,0,'J',false});
        // Sets up the cells for the JBlock
        for (size_t col=0; col < 3; col++) {
                blockGrid.emplace_back(Cell{4, col, 'J',false});
        }
}

JBlock::JBlock(bool _isHeavy) {
        isHeavy = _isHeavy;
        points = 0;
        orientation = "flatLeft";
        blockType=Type::J;
		origin = Cell{4,0,' ', true};
        blockGrid.emplace_back(Cell{3,0,'J',false});
        // Sets up the cells for the JBlock
        for (size_t col=0; col < 3; col++) {
                blockGrid.emplace_back(Cell{4, col, 'J',false});
        }
}



JBlock::JBlock() {
        isHeavy = false;
        points = 0;
        orientation = "flatLeft";
        blockType=Type::J;
		origin = Cell{4,0,' ', true};
        blockGrid.emplace_back(Cell{3,0,'J',false});
		blockGrid.emplace_back(Cell{4,0,'J', false});
		blockGrid.emplace_back(Cell{4,1,'J', false});
		blockGrid.emplace_back(Cell{4,2,'J', false});
        // Sets up the cells for the JBlock
        for (size_t col=0; col < 3; col++) {
               // blockGrid.emplace_back(Cell{4, col, 'J',false});
        }
}

// Needs to be done
void JBlock::clockwise(std::vector<std::vector<Cell>> &theGrid) {
	eraseBlock(theGrid);
	
	std::vector<Cell> blockGridCopy{blockGrid};
	//std::cout << o->blockGrid.at(0).getVal();
	int index=0;
	if(orientation == "flatLeft") {
		bool posRotate = true;
		posRotate = checkRotate((theGrid.at(origin.getRow() - 2).at(origin.getCol())),
			(theGrid.at(origin.getRow() - 2).at(origin.getCol() + 1)),(theGrid.at(origin.getRow() - 1).at(origin.getCol() + 1)),
		(theGrid.at(origin.getRow() - 1).at(origin.getCol() + 1)));
		if(posRotate){
		for(auto &it: blockGrid){
			if((origin.getCol() == blockGridCopy.at(index).getCol()) && (origin.getRow() == blockGridCopy.at(index).getRow())){
				it.setCol(origin.getCol());
				it.setRow(origin.getRow() - 2);
			}
			if((origin.getCol() == blockGridCopy.at(index).getCol()) && (origin.getRow() - 1 == blockGridCopy.at(index).getRow())){
				it.setCol(origin.getCol() + 1);
				it.setRow(origin.getRow() - 2);
			}
			if((origin.getCol() + 1 == blockGridCopy.at(index).getCol()) && (origin.getRow() == blockGridCopy.at(index).getRow())){
				it.setCol(origin.getCol());
				it.setRow(origin.getRow() - 1);
			}
			if((origin.getCol() + 2 == blockGridCopy.at(index).getCol()) && (origin.getRow() == blockGridCopy.at(index).getRow())){
				it.setCol(origin.getCol());
				it.setRow(origin.getRow());
			}
			index++;

		}

	orientation = "vertRight";
	}
	} else if(orientation == "vertRight"){
		bool posRotate = true;
		posRotate = checkRotate((theGrid.at(origin.getRow() - 1).at(origin.getCol())),
			(theGrid.at(origin.getRow() - 1).at(origin.getCol() + 1)),(theGrid.at(origin.getRow() - 1).at(origin.getCol() + 2)),
		(theGrid.at(origin.getRow()).at(origin.getCol() + 2)));
		if(posRotate){
		for(auto &it: blockGrid){
			if((origin.getCol() == blockGridCopy.at(index).getCol()) && (origin.getRow() == blockGridCopy.at(index).getRow())){
				it.setCol(origin.getCol());
				it.setRow(origin.getRow() - 1);
			}
			if((origin.getRow() - 1 == blockGridCopy.at(index).getRow()) && (origin.getCol() == blockGridCopy.at(index).getCol())){
				it.setCol(origin.getCol() + 1);
				it.setRow(origin.getRow() - 1);
			}
			if((origin.getRow() - 2 == blockGridCopy.at(index).getRow()) && (origin.getCol() == blockGridCopy.at(index).getCol())){
				it.setCol(origin.getCol() + 2);
				it.setRow(origin.getRow() - 1);
			}
			if((origin.getRow() - 2 == it.getRow()) && (origin.getCol() + 1 == blockGridCopy.at(index).getCol())){
				it.setCol(origin.getCol() + 2);
				it.setRow(origin.getRow());
			}
			index++;

		}

	orientation = "flatRight";
		}
	} else if(orientation == "flatRight"){
		bool posRotate = true;
		posRotate = checkRotate((theGrid.at(origin.getRow()).at(origin.getCol() + 1)),
			(theGrid.at(origin.getRow()).at(origin.getCol() + 1)),(theGrid.at(origin.getRow() - 1).at(origin.getCol() + 1)),
		(theGrid.at(origin.getRow() - 2).at(origin.getCol() + 1)));
		if(posRotate){
		for(auto &it: blockGrid){
			if((origin.getCol() == blockGridCopy.at(index).getCol()) && (origin.getRow() - 1 == blockGridCopy.at(index).getRow())){
				it.setCol(origin.getCol());
				it.setRow(origin.getRow());
			}
			if((origin.getRow() - 1 == blockGridCopy.at(index).getRow()) && (origin.getCol() + 1 == blockGridCopy.at(index).getCol())){
				it.setCol(origin.getCol() + 1);
				it.setRow(origin.getRow());
			}
			if((origin.getRow() - 1 == blockGridCopy.at(index).getRow()) && (origin.getCol() + 2 == blockGridCopy.at(index).getCol())){
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
		posRotate = checkRotate((theGrid.at(origin.getRow() - 1).at(origin.getCol())),
			(theGrid.at(origin.getRow() - 1).at(origin.getCol())),(theGrid.at(origin.getRow()).at(origin.getCol() + 1)),
		(theGrid.at(origin.getRow()).at(origin.getCol() + 2)));
		if(posRotate){
		for(auto &it: blockGrid){
			if((origin.getCol() == blockGridCopy.at(index).getCol()) && (origin.getRow() == blockGridCopy.at(index).getRow())){
				it.setCol(origin.getCol());
				it.setRow(origin.getRow());
			}
			if((origin.getRow() == blockGridCopy.at(index).getRow()) && (origin.getCol() + 1 == blockGridCopy.at(index).getCol())){
				it.setCol(origin.getCol());
				it.setRow(origin.getRow() - 1);
			}
			if((origin.getRow() - 1 == blockGridCopy.at(index).getRow()) && (origin.getCol() + 1 == blockGridCopy.at(index).getCol())){
				it.setCol(origin.getCol() + 1);
				it.setRow(origin.getRow());
			}
			if((origin.getRow() - 2 == it.getRow()) && (origin.getCol() + 1 == blockGridCopy.at(index).getCol())){
				it.setCol(origin.getCol() + 2);
				it.setRow(origin.getRow());
			}
			index++;

		}

	orientation = "flatLeft";
	}
	}
	
	render(theGrid);
}

void JBlock::counterClockwise(std::vector<std::vector<Cell>> &theGrid) {
	clockwise(theGrid);
	clockwise(theGrid);
	clockwise(theGrid);

}
