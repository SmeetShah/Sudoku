all: sudoku

sudoku: sudoku.c
	gcc -g -Wall -Werror -fsanitize=address -std=c99 sudoku.c -o sudoku

clean:	sudoku
	rm -rf sudoku
