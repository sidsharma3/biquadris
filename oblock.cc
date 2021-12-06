#include <string>
#include <stdexcept>
#include "oblock.h"
#include "cell.h"
#include <iostream>

// Still lots more to do, ie Function ovverides and all, but its for reference 
OBlock::OBlock(bool _isHeavy, int _points, std::string _orientation, Cell _origin) {
        isHeavy = _isHeavy;
        points = _points;
        orientation = "flat";
	origin = _origin;
        blockType=Type::O;
        blockGrid.emplace_back(Cell{3,0,'O',false});
        blockGrid.emplace_back(Cell{3,1,'O',false});
        // Sets up the cells for the OBlock
        for (size_t col=0; col < 2; col++) {
                blockGrid.emplace_back(Cell{4, col, 'O',false});
        }
}

OBlock::OBlock(bool _isHeavy, int _points, std::string _orientation) {
        isHeavy = _isHeavy;
        points = _points;
        orientation = "flat";
        blockType=Type::O;
	origin = Cell{4,0,' ', true};
        blockGrid.emplace_back(Cell{3,0,'O',false});
        blockGrid.emplace_back(Cell{3,1,'O',false});
        // Sets up the cells for the OBlock
        for (size_t col=0; col < 2; col++) {
                blockGrid.emplace_back(Cell{4, col, 'O',false});
        }
}

OBlock::OBlock(bool _isHeavy) {
        isHeavy = _isHeavy;
        points = 0;
        orientation = "flat";
        blockType=Type::O;
	origin = Cell{4,0,' ', true};
        blockGrid.emplace_back(Cell{3,0,'O',false});
        blockGrid.emplace_back(Cell{3,1,'O',false});
        // Sets up the cells for the OBlock
        for (size_t col=0; col < 2; col++) {
                blockGrid.emplace_back(Cell{4, col, 'O',false});
        }
}


OBlock::OBlock() {
        isHeavy = false;
        points = 0;
        orientation = "flat";
        blockType=Type::O;
		origin = Cell{3,0,' ', true};
        blockGrid.emplace_back(Cell{3,0,'O',false});
        blockGrid.emplace_back(Cell{3,1,'O',false});
        // Sets up the cells for the OBlock
        for (size_t col=0; col < 2; col++) {
                blockGrid.emplace_back(Cell{4, col, 'O',false});
        }
}

// Needs to be done
void OBlock::clockwise(std::vector<std::vector<Cell>> &theGrid) {

}

void OBlock::counterClockwise(std::vector<std::vector<Cell>> &theGrid) {

}