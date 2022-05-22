prog : interface.o sudoku.o morpion.o pacman.o
	gcc -o prog interface.o sudoku.o morpion.o pacman.o

interface.o : interface.c
	gcc -o interface.o -c interface.c -W

sudoku.o : sudoku.c
	gcc -o sudoku.o -c sudoku.c -W

morpion.o : morpion.c
	gcc -o morpion.o -c morpion.c -W

pacman.o : pacman.c
	gcc -o pacman.o -c pacman.c -W