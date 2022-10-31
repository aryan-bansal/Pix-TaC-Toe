CC = gcc

SOURCE = *.c Sources/*.c

LINKER_FLAGS = -lSDL2 -lSDL2_image

OUTPUT = game

all: $(SOURCE)
	$(CC) $^ $(LINKER_FLAGS) -o $(OUTPUT)