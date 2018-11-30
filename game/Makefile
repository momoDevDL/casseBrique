CXX=g++
CXX_FLAGS= -ansi -Wall -pedantic -g
SOURCE= terrain.cpp window.cpp main.cpp balle.cpp
PROG=game
MSG_OK = @ echo "\t\t\t........................OK"

.SUFFIXES : .cpp .h .o

all : $(PROG)

.cpp.o :
	$(CXX) -c $(CXX_FLAGS) $<
	$(MSG_OK)

$(PROG) : $(SOURCE:.cpp=.o)
	$(CXX) $^ $(CXX_FLAGS) -o $(PROG) -lncurses
	$(MSG_OK)
clear :
	rm $(SOURCE:.cpp=.o)



