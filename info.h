#ifndef __INFO_H__
#define __INFO_H__
#include <cstddef>
#include <string>
#include <vector>
#include "cell.h"

// Struct for representing changes to state of the board
struct Info {
  std::vector<std::vector<Cell>> newGrid;
  size_t playerNum;
  int level;
  int score;
  // Should also contain fields for nextBlock
};

#endif