#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_

#include <cstddef>
#include <string>
#include <vector>
#include "observer.h"
#include "subject.h"
#include "cell.h"
#include "info.h"

class TextDisplay : public Observer<Info> {
    std::vector<std::vector<char>> board;
    std::vector<std::vector<char>> nextBlock; // Will be replaced with Block Class instead
    std::vector<int>printedLevel;
    std::vector<int>printedScore;
    public:
    TextDisplay();
    void notify(Subject<Info> &whoFrom) override;
    friend std::ostream& operator<<(std::ostream& os, const TextDisplay& td);
};

#endif
