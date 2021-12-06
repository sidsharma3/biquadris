CXX=g++
CXXFLAGS=-std=c++14 -Wall -Werror=vla -g -MMD
EXEC=main
OBJECTS= main.o textDisplay.o sampleSubject.o cell.o block.o Iblock.o jblock.o Lblock.o oblock.o sblock.o zblock.o tblock.o level.o level0.o level1.o level2.o levelAdvanced.o level3.o level4.o game.o
DEPENDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean
