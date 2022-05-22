#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include"sudoku.h"
#include"morpion.h"
#include"pacman.h"

int main(){

	printf("bonjour !\n");
	int x;
	int y;
	bool test=true;
	while(test==true){
		printf("A quel jeu voulez vous jouez ?\n Tapez 1 pour sudoku, 2 pour morpion, 3 pour pacman :\n");
		test=false;

		scanf("%d",&x);
		while(x !=1 && x!=2 && x!=3){
			printf("cette entrée ne fonctionne pas, recommencez :\n");
			scanf("%d",&x);
		}
		if(x==1){Sudoku();}
		if(x==2){Morpion();}
		if(x==3){Pacman();}
		printf("voulez vous continuez à jouez ? 1 pour OUI, 2 pour NON\n");
		scanf("%d",&y);
		while(y !=1 && y !=2){
			printf("cette entrée ne fonctionne pas, recommencez :\n");
			scanf("%d",&y);
		}
		if(y==1){test=true;};
	}
	return 0;
}
