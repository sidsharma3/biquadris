#include <cstddef>
#include <string>
#include <iostream>
#include <vector>
#include "observer.h"
#include "subject.h"
#include "cell.h"
#include "info.h"
#include "textDisplay.h"

using namespace std;

// Constructor for making an empty board
TextDisplay::TextDisplay(): Observer{}, printedLevel{0, 0}, printedScore{0, 0} {
    // Create an empty board
    for (size_t row=0; row < 18; row++) {
        vector<char> emptyRow;
        for (size_t col=0; col < 29; col++) {
            emptyRow.emplace_back(' ');
        }
        board.emplace_back(emptyRow);
    }

    // Create an empty next block section - This will be replaced with real representation of block
    for (size_t row=0; row < 2; row++) {
        vector<char> emptyRow;
        for (size_t col=0; col < 29; col++) {
            emptyRow.emplace_back(' ');
        }
        nextBlock.emplace_back(emptyRow);
    }
}

// Called when Subject Changes, updates Text Display
void TextDisplay::notify(Subject<Info> &whoFrom) {
    // Gets the information about changes in the board
    Info info = whoFrom.getInfo();

    // Make changes to score and level as well
    printedLevel.at(info.playerNum) = info.level;
    printedScore.at(info.playerNum) = info.score;

    // Change the text's values depending on the player side
    const size_t colStart = info.playerNum == 0 ? 0 : 17;
    const size_t colEnd = info.playerNum == 0 ? 11 : 28;
    for (size_t row=0; row < board.size(); row++) {
        size_t gridCol=0;
        for (size_t col = colStart; col < colEnd; col++) { 
            board.at(row).at(col) = info.newGrid.at(row).at(gridCol).getVal(); // Will update the side of grid depending on player
            gridCol++;
        }
    }
    cout << *this;
}

// Output Operator for the Board
ostream& operator<<(std::ostream& os, const TextDisplay& td) {
    
    // Firstly print the Level and Score
    os << "Level:" << "    " << td.printedLevel.at(0) << "      " << "Level:" << "    " << td.printedLevel.at(1) << '\n';
    os << "Score:" << "    " << td.printedScore.at(0) << "      " << "Score:" << "    " << td.printedScore.at(1) << '\n';

    // Print the --- Dash line
    os << "-----------" << "      " << "-----------" << '\n';

    // Prints everything in the board
    for (size_t row=0; row < td.board.size(); row++) {
        for (size_t col=0; col<td.board.at(row).size(); col++) {
            os << td.board.at(row).at(col);
        }
        os << '\n';
    }

    // Print the --- Dash line
    os << "-----------" << "      " << "-----------" << '\n';

    os << "Next:" << "            " << "Next:" << "     " << '\n';

    // Bottom section will be removed or redone to accomodate actual block printing
    for (size_t row=0; row < td.nextBlock.size(); row++) {
        for (size_t col=0; col<td.nextBlock.at(row).size(); col++) {
            os << td.nextBlock.at(row).at(col);
        }
        os << '\n';
    }

    return os;
}

