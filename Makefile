CC = gcc
CFLAGS = -W -Wall
TARGET = library
TARGET_L = library.o
OBJECTS = main_library.c ./inc/library.o
OBJECTS_L = ./inc/library.c

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(TARGET_L) : $()
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm ./inc/*.o library
