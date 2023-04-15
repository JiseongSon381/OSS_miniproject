CC = gcc
CFLAGS = -W -Wall
TARGET = library
TARGET_L = ./inc/library.o
OBJECTS = main_library.c ./inc/library.o
OBJECTS_L = ./inc/library.c

library : main_library.c ./inc/library.o
	gcc -W -Wall -o library main_library.c ./inc/library.o
library.o : ./inc/library.c ./inc/library.h
	gcc -c ./inc/library.c -o ./inc/library.o
clean:
	rm ./inc/*.o library
