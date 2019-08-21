#Makefile for TV guide
#Typical makefile based on lecture notes except BIN
#BIN is used for program name

OBJ	= tvguide.o fileIO.o linkedList.o interface.o comparison.o
CFLAGS	= -Wall -pedantic -ansi
BIN	= main

$(BIN): $(OBJ)
	cc $(OBJ) -o $(BIN)

tvguide.o: tvguide.c data.h io.h list.h interface.h comparison.h
	cc tvguide.c -c $(CFLAGS)

fileIO.o: fileIO.c data.h list.h
	cc fileIO.c -c $(CFLAGS)

linkedList.o: linkedList.c data.h
	cc linkedList.c -c $(CFLAGS)

interface.o: interface.c boolean.h data.h
	cc interface.c -c $(CFLAGS)

comparison.o: comparison.c data.h boolean.h
	cc comparison.c -c $(CFLAGS)

clean:
	rm $(OBJ) $(BIN)


