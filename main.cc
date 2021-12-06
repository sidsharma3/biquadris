#include <iostream>
#include <string>
#include <vector>
#include "info.h"
#include "observer.h"
#include "sampleSubject.h"
#include "textDisplay.h"
#include "game.h"
#include <sstream>
using namespace std;

// Main used for testing Observer Pattern (Not Real Main)
int main(int argc, char*argv[]) {
    if(argc == 1){
    	Game begin = Game{0,0, "easyseq", "sequence2"};
		begin.start();

    }
    int i = 1;
    cout<<argc;
    while(i < argc){
    	string arg = argv[i];
	if(arg == "-text"){
		Game begin =  Game{0,0, "easyseq", "sequence2"};
		begin.start();
	} else if ((arg == "-seed") && (argc == 3)){
		string seed = argv[i+1];
		int val;
		istringstream iss (seed);
		iss >> val;
		srand(val);
		++i;
	} else if (arg == "-scriptfile1"){
		string seq;
		seq = argv[i+1];
		Game begin = Game{0,0,seq,"sequence2"};
		begin.start();
		++i;
	} else if (arg == "-scriptfile2"){
		string seq;
		seq = argv[i+1];
		Game begin = Game{0,0,"easyseq",seq};
		begin.start();
		++i;
	} else if ((arg == "-startlevel") && (argc == 3)){
		string levVal = argv[i+1];
		int level;
		istringstream iss (levVal);
		iss >> level;
		Game begin = Game{0,level,"easyseq","sequence2"};
		begin.start();
	} else if ((arg == "-startlevel") && (argc == 2)){
		Game begin = Game{0,0, "easyseq", "sequence2"};
		begin.start();
	}

		++i;
    }
	
}
