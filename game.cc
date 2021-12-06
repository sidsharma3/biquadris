#include "game.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void Game::playerSeq(string file, sampleSubject &player){
	cout<<"green";
	std::ifstream fin(file + ".txt");
	string word;
	while(fin>>word) {     
					if(word == "I") {
						cout<<"I";
					} else if(word == "J"){
						cout<<"J";
					} else if(word == "L"){
						cout<<"L";
					} else if(word == "O"){
						cout<<"O";
					} else if(word == "S"){
						cout<<"S";
					} else if(word == "Z"){
						cout<<"Z";
					} else if(word == "T"){
						cout<<"T";
					} else if(word.substr(0,3) == "lef"){
						player.left();
					} else if(word.substr(0,6) == "levelu"){
						player.levelUp();
					} else if(word.substr(0,6) == "leveld"){
						player.levelDown();
					} else if(word.substr(0,2) == "ri"){
						player.right();
					} else if(word.substr(0,2) == "ra"){
						string file;
 		   	        		cin>>file;
        			   		player.setSequence(file);
					//	player0.makeRandom();
					} else if(word.substr(0,2) == "re"){
						cout<<"restart";
					} else if(word.substr(0,2) == "do"){
						player.down();
					} else if(word.substr(0,2) == "dr"){
						player.drop();
					//	zeroTurn = false;
					} else if(word.substr(0,2) == "cl"){
						player.clockwise();
					} else if(word.substr(0,2) == "co"){
						player.counterClockwise();
					} else if(word.substr(0,1) == "n"){
						string file;
 		   	        		cin>>file;
        			   		player.setSequence(file);
					} else if(word.substr(0,1) == "s"){
						string file;
 		   	        		cin>>file;
        			   		//std::ifstream fin(file + ".txt");
						playerSeq(file, player);					
					} else {
						stringstream ss;
						ss<<word;
						int iter;
						ss>>iter>>word;
						cout<<iter<<endl;
						cout<<word<<endl;
						for(int i = 0; i < iter; ++i){
							if(word == "I") {
								cout<<"I";
							} else if(word == "J"){
								cout<<"J";
							} else if(word == "L"){
								cout<<"L";
							} else if(word == "O"){
								cout<<"O";
							} else if(word == "S"){
								cout<<"S";
							} else if(word == "Z"){
								cout<<"Z";
							} else if(word == "T"){
								cout<<"T";
							} else if(word.substr(0,3) == "lef"){
								player.left();
							} else if(word.substr(0,6) == "levelu"){
								player.levelUp();
							} else if(word.substr(0,6) == "leveld"){
								player.levelDown();
							} else if(word.substr(0,2) == "ri"){
								player.right();
							} else if(word.substr(0,2) == "do"){
								player.down();
							} else if(word.substr(0,2) == "dr"){
								player.drop();
								//zeroTurn = false;
							} else if(word.substr(0,2) == "cl"){
								player.clockwise();
							} else if(word.substr(0,2) == "co"){
								player.counterClockwise();
							} else if(word.substr(0,1) == "s"){
								string file;
 		   	        				cin>>file;
        			   				player.setSequence(file);
							} 
						}
			}
	}

}

Game::Game(int hs, int level, std::string seq0, std::string seq1): hs{hs}, t{TextDisplay{}}, player0{sampleSubject{0,level,0,seq0, t}},
					    player1{sampleSubject{1,level,0,seq1,t}}  {
		//	t = TextDisplay{};
		//	player0 = sampleSubject{0,0,0,"easyseq",t};
		//	player1 = sampleSubject{1,0,0,"sequence2",t};
		}

		void Game::start(){
    			//TextDisplay t{};
    			//sampleSubject player0{0,0,0,"easyseq",t};
    			//sampleSubject player1{1,0,0,"sequence2",t}; 
    			string turn;
    			string word;
    			bool zeroTurn = true;
    			player0.renderBlock();
    			player1.renderBlock();
    			while(cin>>word) {    
				if(zeroTurn){  
					if(word == "I") {
						cout<<"I";
					} else if(word == "J"){
						cout<<"J";
					} else if(word == "L"){
						cout<<"L";
					} else if(word == "O"){
						cout<<"O";
					} else if(word == "S"){
						cout<<"S";
					} else if(word == "Z"){
						cout<<"Z";
					} else if(word == "T"){
						cout<<"T";
					} else if(word.substr(0,3) == "lef"){
						player0.left();
					} else if(word.substr(0,6) == "levelu"){
						player0.levelUp();
					} else if(word.substr(0,6) == "leveld"){
						player0.levelDown();
					} else if(word.substr(0,2) == "ri"){
						player0.right();
					} else if(word.substr(0,2) == "ra"){
						string file;
 		   	        		cin>>file;
        			   		player0.setSequence(file);
					//	player0.makeRandom();
					} else if(word.substr(0,2) == "re"){
						cout<<"restart";
					} else if(word.substr(0,2) == "do"){
						player0.down();
					} else if(word.substr(0,2) == "dr"){
						player0.drop();
						zeroTurn = false;
					} else if(word.substr(0,2) == "cl"){
						player0.clockwise();
					} else if(word.substr(0,2) == "co"){
						player0.counterClockwise();
					} else if(word.substr(0,1) == "n"){
						string file;
 		   	        		cin>>file;
        			   		player0.setSequence(file);
					} else if(word.substr(0,1) == "s"){
						string file;
 		   	        		cin>>file;
        			   		cout<<file<<endl;
						cout<<"green"<<endl;	
						playerSeq(file, player0);					
					} else {
						stringstream ss;
						ss<<word;
						int iter;
						ss>>iter>>word;
						cout<<iter<<endl;
						cout<<word<<endl;
						for(int i = 0; i < iter; ++i){
							if(word == "I") {
								cout<<"I";
							} else if(word == "J"){
								cout<<"J";
							} else if(word == "L"){
								cout<<"L";
							} else if(word == "O"){
								cout<<"O";
							} else if(word == "S"){
								cout<<"S";
							} else if(word == "Z"){
								cout<<"Z";
							} else if(word == "T"){
								cout<<"T";
							} else if(word.substr(0,3) == "lef"){
								player0.left();
							} else if(word.substr(0,6) == "levelu"){
								player0.levelUp();
							} else if(word.substr(0,6) == "leveld"){
								player0.levelDown();
							} else if(word.substr(0,2) == "ri"){
								player0.right();
							} else if(word.substr(0,2) == "do"){
								player0.down();
							} else if(word.substr(0,2) == "dr"){
								player0.drop();
								zeroTurn = false;
							} else if(word.substr(0,2) == "cl"){
								player0.clockwise();
							} else if(word.substr(0,2) == "co"){
								player0.counterClockwise();
							} else if(word.substr(0,1) == "s"){
								string file;
 		   	        				cin>>file;
        			   				player0.setSequence(file);
							} 
						}
						continue;
					}
   			 	} else {
					if(word == "I") {
						cout<<"I";
					} else if(word == "J"){
						cout<<"J";
					} else if(word == "L"){
						cout<<"L";
					} else if(word == "O"){
						cout<<"O";
					} else if(word == "S"){
						cout<<"S";
					} else if(word == "Z"){
						cout<<"Z";
					} else if(word == "T"){
						cout<<"T";
					} else if(word.substr(0,3) == "lef"){
						player1.left();
					} else if(word.substr(0,6) == "levelu"){
						player1.levelUp();
					} else if(word.substr(0,6) == "leveld"){
						player1.levelDown();
					} else if(word.substr(0,2) == "ri"){
						player1.right();
					} else if(word.substr(0,2) == "ra"){
						string file;
 		   	        		cin>>file;
        			   		player1.setSequence(file);
					//	player1.makeRandom();
					} else if(word.substr(0,2) == "re"){
						cout<<"restart";
					} else if(word.substr(0,2) == "do"){
						player1.down();
					} else if(word.substr(0,2) == "dr"){
						player1.drop();
						zeroTurn = true;
					} else if(word.substr(0,2) == "cl"){
						player1.clockwise();
					} else if(word.substr(0,2) == "co"){
						player1.counterClockwise(); 
					} else if(word.substr(0,1) == "n"){
						string file;
		    	        	    	cin>>file;
        			       		player1.setSequence(file);
					} else if(word.substr(0,1) == "s"){
						string file;
 		   	        		cin>>file;
        			   		playerSeq(file, player1);	
					} else {
						stringstream ss;
						ss<<word;
						int iter;
						ss>>iter>>word;
						cout<<iter<<endl;
						cout<<word<<endl;
						for(int i = 0; i < iter; ++i){
							if(word == "I") {
								cout<<"I";
							} else if(word == "J"){
								cout<<"J";
							} else if(word == "L"){
								cout<<"L";
							} else if(word == "O"){
								cout<<"O";
							} else if(word == "S"){
								cout<<"S";
							} else if(word == "Z"){
								cout<<"Z";
							} else if(word == "T"){
								cout<<"T";
							} else if(word.substr(0,3) == "lef"){
								player1.left();
							} else if(word.substr(0,6) == "levelu"){
								player1.levelUp();
							} else if(word.substr(0,6) == "leveld"){
								player1.levelDown();
							} else if(word.substr(0,2) == "ri"){
								player1.right();
							} else if(word.substr(0,2) == "do"){
								player1.down();
							} else if(word.substr(0,2) == "dr"){
								player1.drop();
								zeroTurn = false;
							} else if(word.substr(0,2) == "cl"){
								player1.clockwise();
							} else if(word.substr(0,2) == "co"){
								player1.counterClockwise();
							} else if(word.substr(0,1) == "s"){
								string file;
 		   	        				cin>>file;
        			   				player1.setSequence(file);
							} 
						}
						
					} 
				}
   			}
		}

		void Game::end(){
			cout<<"Game is completed"<<endl;
		}

		void Game::ApplyEffects(sampleSubject& curPlayer, string effect){
			if(effect == "blind"){
				curPlayer.blinded = true;
			}
	
			if(effect == "heavy"){
				curPlayer.heavy = true;
			}
		}
	
