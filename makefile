TXT_FLAGS = -Wall -ggdb -c
TXT_FLAGS_O = -Wall -ggdb -o
CC = g++
SRC_DIR_CORE = src/core
SRC_DIR_TXT = src/txt
OBJ_DIR = obj/Debug/src
BIN_DIR = bin
EXEC_NAME = SURVIE10

OBJS := $(OBJ_DIR)/Jeu.o\
	$(OBJ_DIR)/Plateau.o\
	$(OBJ_DIR)/mainTxt.o\
	$(OBJ_DIR)/Plante.o\
	$(OBJ_DIR)/Poulet.o\
	$(OBJ_DIR)/Singe.o\
	$(OBJ_DIR)/txtJeu.o\
	$(OBJ_DIR)/winTxt.o

all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJS)
	$(CC) $(TXT_FLAGS_O) $(BIN_DIR)/$(EXEC_NAME) $(OBJS)

$(OBJ_DIR)/Jeu.o: $(SRC_DIR_CORE)/Jeu.cpp $(SRC_DIR_CORE)/Jeu.h $(OBJ_DIR)/Plateau.o $(OBJ_DIR)/Singe.o $(OBJ_DIR)/Poulet.o $(OBJ_DIR)/Plante.o
	$(CC) $(FLAGS) $(SRC_DIR_CORE)/Jeu.cpp -o $(OBJ_DIR)/Jeu.o
		
$(OBJ_DIR)/Plateau.o: $(SRC_DIR_CORE)/Plateau.cpp $(SRC_DIR_CORE)/Plateau.h $(OBJ_DIR)/Plante.o
	$(CC) $(FLAGS) $(SRC_DIR_CORE)/Plateau.cpp -o $(OBJ_DIR)/Plateau.o 

$(OBJ_DIR)/Plante.o: $(SRC_DIR_CORE)/Plante.cpp $(SRC_DIR_CORE)/Plante.h
	$(CC) $(FLAGS) $(SRC_DIR_CORE)/Plante.cpp -o $(OBJ_DIR)/Plante.o

$(OBJ_DIR)/Poulet.o: $(SRC_DIR_CORE)/Poulet.cpp $(SRC_DIR_CORE)/Poulet.h $(OBJ_DIR)/Singe.o $(OBJ_DIR)/Plateau.o
	$(CC) $(FLAGS) $(SRC_DIR_CORE)/Poulet.cpp -o $(OBJ_DIR)/Poulet.o
	 
$(OBJ_DIR)/Singe.o: $(SRC_DIR_CORE)/Singe.cpp $(SRC_DIR_CORE)/Singe.h $(OBJ_DIR)/Plante.o $(OBJ_DIR)/Plateau.o
	$(CC) $(FLAGS) $(SRC_DIR_CORE)/Singe.cpp -o $(OBJ_DIR)/Singe.o

$(OBJ_DIR)/txtJeu.o: $(SRC_DIR_TXT)/txtJeu.cpp $(SRC_DIR_TXT)/txtJeu.h $(OBJ_DIR)/Jeu.o $(OBJ_DIR)/winTxt.o
	$(CC) $(FLAGS) $(SRC_DIR_TXT)/txtJeu.cpp -o $(OBJ_DIR)/txtJeu.o

$(OBJ_DIR)/winTxt.o: $(SRC_DIR_TXT)/winTxt.cpp $(SRC_DIR_TXT)/winTxt.h
	$(CC) $(FLAGS) $(SRC_DIR_TXT)/winTxt.cpp -o $(OBJ_DIR)/winTxt.o

$(OBJ_DIR_SDL)/sdlJeu.o: $(SRC_DIR_SDL)/sdlJeu.cpp $(SRC_DIR_SDL)/sdlJeu.h $(OBJ_DIR)/jeuSdl.o $(OBJ_DIR)/Plateau.o $(OBJ_DIR)/Plante.o $(OBJ_DIR)/Poulet.o $(OBJ_DIR)/Singe.o 
	$(CC) $(SDL_FLAGS_O) $(OBJ_DIR)/sdlJeu.o $(OBJ_DIR)/sdlJeu.cpp $(OBJ_DIR)/jeuSdl.o $(OBJ_DIR)/Plateau.o $(OBJ_DIR)/Plante.o $(OBJ_DIR)/Poulet.o $(OBJ_DIR)/Singe.o

$(OBJ_DIR)/mainTxt.o: $(SRC_DIR_TXT)/mainTxt.cpp $(SRC_DIR_TXT)/txtJeu.h
	$(CC) $(TXT_FLAGS) $(SRC_DIR_TXT)/mainTxt.cpp -o $(OBJ_DIR)/mainTxt.o

$(OBJ_DIR)/mainSdl.o: $(SRC_DIR_SDL)/mainSdl.cpp $(SRC_DIR_SDL)/sdlJeu.h
	$(CC) $(SDL_FLAGS_O) $(OBJ_DIR)/mainSdl.o $(SRC_DIR_SDL)/mainSdl.cpp $(OBJ_DIR)/sdlJeu.o

clean :
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/$(EXEC_NAME)

