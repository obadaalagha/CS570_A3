################################################################################
# Obada Alagha cssc2115 RedID: 819 852 274
# Amiel Nava   cssc2124 RedID: 824 264 864
# CS570 Summer 2020
# Assignment #3, Management of Threads
# Filename: Makefile
# WRITTEN BY OBADA.
################################################################################

EXEC = mot
FILES = main.c input.c threads.c
CC = gcc
LFLAGS = -o
CFLAGS = -c

OBJECTS = $(FILES:.c=.o)

$(EXEC):$(OBJECTS)
	$(CC) $(LFLAGS) $(EXEC) $(OBJECTS)
	rm -f *.o

.c.o:
	$(CC) $(CFLAGS) $<

clean:
	rm -f *.o $(EXEC)

###############################[ EOF: Makefile ]################################
