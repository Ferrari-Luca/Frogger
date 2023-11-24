
CXX = $(shell [ `g++ -v 2>&1 | grep -o 'version [0-9]\+' | cut -d' ' -f2` -le 9 ] && echo g++-10 || echo g++)
# Si la ligne précédente provoque une erreur, la supprimer et décommenter la ligne suivante
# CXX = g++ # ou g++-10 si la version par défaut est 9 ou antérieure

# Sur Mac, ou en général si make ne marche pas, décommentez les lignes suivantes
#CXXFLAGS += $(shell fltk-config --cxxflags | sed 's/-I/-isystem/g')
#LDLIBS   += $(shell fltk-config --ldflags)

### MINI TUTO MAKEFILE - PARTIE 6 ###
# Aujourd'hui nous ne verrons rien de particulier quant à make.
# Ce fichier est prévu pour vous servir de référence pour une compilation multi-fichiers.
# Remarquez que si vous ne modifiez qu'un seul fichier, tout ne sera pas re-compilé.
#####################################

# Variables
CXXFLAGS += -std='c++20' -Wall -Wextra -Wsign-compare -fmax-errors=2 -pedantic

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

