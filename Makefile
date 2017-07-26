CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = cc3k
OBJECTS = main.o floor.o object.o character.o enemy.o player.o drow.o goblin.o shade.o troll.o vampire.o elf.o dragon.o halfling.o dwarf.o human.o merchant.o orcs.o dragonHoard.o merchantHoard.o normalhoard.o smallGold.o treasure.o subject.o potion.o cell.o chamber.o textdisplay.o stair.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
