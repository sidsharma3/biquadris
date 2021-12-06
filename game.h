#ifndef GAME_H
#define GAME_H
#include <string>
#include "fstream"
#include "sampleSubject.h"
#include "textDisplay.h"

class Game {
	public:
		int hs;
		int level;
		std::string seq0;
		std::string seq1;
		TextDisplay t;
		sampleSubject player0;
		sampleSubject player1;
		Game(int hs, int level, std::string seq0, std::string seq1);
		void start();
		void end();
		void ApplyEffects(sampleSubject& curPlayer, std::string effect);
		void playerSeq(std::string file, sampleSubject & player);
};

#endif

