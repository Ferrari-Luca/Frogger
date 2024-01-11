
CXX = $(shell [ `g++ -v 2>&1 | grep -o 'version [0-9]\+' | cut -d' ' -f2` -le 9 ] && echo g++-10 || echo g++)

# Variables
CXXFLAGS += -std='c++20' -Wall -Wextra -Wsign-compare -fmax-errors=2 -pedantic -g 

LDLIBS   += -lfltk

SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, %.o, ${SOURCES})

.PHONY: default
default: main

main: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${LDFLAGS} $^ -o $@ ${LOADLIBES} ${LDLIBS}

# make clean supprime les fichiers objets
.PHONY: clean
clean:
	-rm *.o

# make mrclean supprime les fichiers objets et les exécutables
.PHONY: mrclean
mrclean: clean
	-rm main

