CC=gcc
Flags= -Wall
Src=game.c ShiftLeftFunc.c shiftRightFunc.c shiftUpEtDown.c utileFunc.c CheckFunc.c GenRandom.c GameStartfun.c
OBJECTS = $(Src:.c=.o)
Exec=main

.PHONY:clean

all:$(Exec)

$(Exec): $(OBJECTS)
	$(CC) -o $(Exec) $(OBJECTS)
.c.o:
	$(CC) $(Flags) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(Exec)