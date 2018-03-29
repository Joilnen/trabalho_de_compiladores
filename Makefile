SRC=programinha.c lexer.c checker.c
OBJ=programinha.o lexer.o checker.o
CC=cc -std=gnu11
BIN=programinha

.c.o:
	$(CC) -g -c $(SRC)
all:$(OBJ)
	$(CC) -o $(BIN) $(OBJ)
tags:
	ctags -R $(SRC)
clean:
	@rm -rf *.o *~ $(BIN) tags > /dev/null

