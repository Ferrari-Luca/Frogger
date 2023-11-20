CXX = $(shell [ `g++ -v 2>&1 | grep -o 'version [0-9]\+' | cut -d' ' -f2` -le 9 ] && echo g++-10 || echo g++)


# Variables
CXXFLAGS += -std='c++20' -Wall -Wextra -pedantic
LDLIBS   += -lfltk

# Première recette = recette par défaut.
.PHONY: default # Attention: cette recette ne fabrique pas la cible (pas de fichier "default" créé)
default: main # Par défaut, faire le lab4

# Recette magique
%: %.cpp
	${CXX} ${CXXFLAGS} $< -o $@ ${LDLIBS}

# make clean supprime les fichiers objets
.PHONY: clean
clean:
	rm -f *.o

# make mrclean supprime les fichiers objets et les exécutables
.PHONY: mrclean
mrclean: clean
	rm -f main

