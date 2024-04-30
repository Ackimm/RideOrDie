CC=gcc

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
FLAGGLUT=-lglut -lGL -lGLU -lSOIL
endif
ifeq ($(UNAME_S),Darwin)
FLAGGLUT=-Wno-deprecated-declarations -framework OpenGL -framework GLUT -lSOIL
endif

FLAG=-Wall -std=c99
SRCS= player.c enemies.c game.c drawMap.c loadMap.c tirs.c collision.c menu.c gameInitAndTimers.c bestScores.c textures.c main.c 
OBJET = $(SRCS:.c=.o)
EXEC= program



all: clean $(EXEC)

$(EXEC): $(OBJET)
	$(CC) -o $(EXEC) $(OBJET) $(FLAG) $(FLAGGLUT)
	
clean:
	$(MAKE) -f Makefile clean_internal

clean_internal:
	rm -rf $(EXEC) $(OBJET)