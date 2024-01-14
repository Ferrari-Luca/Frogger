CXX = $(shell [ `g++ -v 2>&1 | grep -o 'version [0-9]\+' | cut -d' ' -f2` -le 9 ] && echo g++-10 || echo g++)

# Variables
CXXFLAGS += -std=c++20 -Wall -Wextra -Wsign-compare -fmax-errors=2 -pedantic -g 
LDLIBS += -lfltk

BUILD_DIR = build

# Liste de tous les fichiers source
SOURCES = $(wildcard *.cpp)

# Liste de tous les fichiers objets à construire dans le dossier de construction
OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

.PHONY: default
default: main

# Règle pour créer le dossier de construction s'il n'existe pas
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Règle pour créer les fichiers objets dans le dossier de construction
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@ $(LOADLIBES) $(LDLIBS)

# make clean supprime les fichiers objets et le dossier de construction
.PHONY: clean
clean:
	-rm -rf $(BUILD_DIR) main

# make mrclean supprime les fichiers objets, le dossier de construction et les exécutables
.PHONY: mrclean
mrclean: clean
