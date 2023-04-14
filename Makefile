CC = gcc
CFLAGS = -W -Wall
TARGET = library
DTARGET = library_debug
OBJECTS = main_library.c ./inc/menu.o ./inc/guest.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
clean:
	rm *.o library
