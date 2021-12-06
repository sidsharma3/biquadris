#include <cstddef>
#include <string>
#include <deque>
#include <stdexcept>
#include <iostream>
#include <stdlib.h>
#include "sampleSubject.h"
#include "info.h"
#include "observer.h"
#include "cell.h"
#include "Iblock.h"
#include "jblock.h"
#include "Lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "levelAdvanced.h"
#include "level3.h"
#include "level4.h"

// All commentary found in .h file

sampleSubject::sampleSubject(size_t playerNum, int level, int score, std::string sequence, Observer<Info> &display): 
playerNum{playerNum}, level{level}, score{score}, sequence{sequence} {
    // Attach the display as an observer to the player
    this->attach(&display);

    curLevel = new Level0(sequence); // Initially depends on level the user gives and the sequence the user wants.

    //Initialize an empty grid
    for (size_t row=0; row < 18; row++) {
        std::vector<Cell>emptyRow;
        for (size_t col=0; col<11; col++) {
            emptyRow.emplace_back(Cell{row, col, ' ', true});
        }
        theGrid.emplace_back(emptyRow);
    }

    // Pushes a first block into the players position and all
    prevBlocks.emplace_back(curLevel->nextBlock());
}

Info sampleSubject::getInfo() const {
    return Info{theGrid, playerNum, level, score};
}


void sampleSubject::renderBlock() {
    prevBlocks.back()->render(theGrid);
    notifyObservers();
}

void sampleSubject::down() {
    prevBlocks.back()->down(theGrid);
    notifyObservers();
}

void sampleSubject::drop() {
    prevBlocks.back()->drop(theGrid);
    notifyObservers();
    prevBlocks.emplace_back(curLevel->nextBlock());
    // Over here call the checking row stuff
    clearCheck();
    prevBlocks.back()->render(theGrid);
    notifyObservers();
}

void sampleSubject::left() {
    prevBlocks.back()->left(theGrid);
    notifyObservers();
}

void sampleSubject::right() {
    prevBlocks.back()->right(theGrid);
    notifyObservers();
}

void sampleSubject::clockwise() {
    prevBlocks.back()->clockwise(theGrid);
    notifyObservers();
}

// added counterClockwise
void sampleSubject::counterClockwise() {
    prevBlocks.back()->counterClockwise(theGrid);
    notifyObservers();
}

// Checks to see if row rowNum has been filled fully
bool sampleSubject::rowCheck(size_t rowNum) {
    for (size_t col=0; col < 11; col++) {
        try {
        if (theGrid.at(rowNum).at(col).getIsEmpty()) {
            return false;
        }
        } catch (const std::out_of_range &e) {
            break;
        }
    }
    return true;
}

// rowNum is the row that has been filled, that row must now have stuff dropped into it
// colNum is the column that must drop all cells down by one until we hit rowNum
void sampleSubject::colDown(const size_t colNum, const size_t rowNum) {
    // Goes upwards...
    for(size_t row=rowNum; row > 0; row--) {
        // Sets the value of Grid at Row, colNum to the cell above
        try {
        theGrid.at(row).at(colNum).setVal(theGrid.at(row-1).at(colNum).getVal());
        } catch(const std::out_of_range &g) {
            std::cout << "reached here" << std::endl;
             break;
        }
    }
}

// Will clear the row rowNum and make everything go down
void sampleSubject::clearRow(const size_t rowNum) {
    for (size_t col=0; col < 11; col++) {
        colDown(col, rowNum);
    }
}

void sampleSubject::clearCheck() {
    int numCleared=0;
    // Iterate across all the rows
    for (size_t row=17; row>2; row--) { // set to 20 for testing. Using easyseq, build a layer of at least 4 blocks high, then try to clear it with one piece.
        if (rowCheck(row)) {
            numCleared++;
            clearRow(row);
            row = 18;
        }
        std::cout << row << std::endl;;
    }
}

void sampleSubject::levelUp() {
    if (level == 4) {
        return;
    } else if(level == 3) {
        level++;
        curLevel = new Level3();
    } else if (level == 2) {
        level++;
        curLevel = new Level2();
    } else if (level == 1) {
        level++;
        curLevel = new Level1();
    } else {
        level++;
        curLevel = new Level0(sequence); // notice how sequence parameter is based on a field in player.
    }
    notifyObservers(); // update the board.
}

// add functionality for level
void sampleSubject::levelDown() {
    if (level == 0) {
        return;
    } else if(level == 1) {
        level--;
        curLevel = new Level0(sequence);
    } else if (level == 2) {
        level--;
        curLevel = new Level1();
    } else if (level == 3) {
        level--;
        curLevel = new Level2();
    } else {
        level--;
        curLevel = new Level3();
    }
    notifyObservers(); // update the board.
}

// add functionality for setting sequence
void sampleSubject::setSequence(std::string _sequence) {
    sequence = _sequence;
    curLevel->sequence.clear();
    curLevel->setSequence(sequence);
}

// setting new seed for rand
void sampleSubject::setSeed(unsigned int seed) {
    curLevel->setSeed(seed);
}


