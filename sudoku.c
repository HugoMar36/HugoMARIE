#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "sudoku.h"
#define size 9 


	
	/* Création de la grille vide */

int** creer_grille_sudoku()
	{
 	int **matrice;
 	matrice=malloc(9*sizeof(int*));
 	for(int i=0; i<9;i++){
 		matrice[i]=calloc(9, sizeof(int));
 	}
 	return(matrice);
}

//#######################################


	/* Affichage de la grille */

void afficher_grille_sudoku(int **matrice){
	for(int i=0; i<9; i++){
			for(int k=0; k<9; k++){
				printf("%d ", matrice[i][k]);
			}
			printf("\n");
	}
}

//#######################################



	/* Remplissage des matrices diagonales aléatoirement */

void fill_diag( int **area){
	int j=0;
	int *deja_vu=calloc(9,sizeof(int));
	int gen_nmb;
	int ind=0;
	bool test=false;
	while(j<9){
		for(int i=j; i<j+3; i++){
			for(int k=j; k<j+3; k++){
				while(test==false){
					gen_nmb=rand()%9+1;
					test=true;
					for(int q=0; q<9;q++){ 
						if(gen_nmb==deja_vu[q]){
						test =false;						
					}}}
				area[i][k]=gen_nmb;
				deja_vu[ind]=gen_nmb;
				ind+=1;
				test=false;
				}}
				j=j+3;
				for(int q=0; q<9;q++) deja_vu[q]=0;
				ind=0;
		}

}

//#######################################


/* Test de validité d'un nombre dans une case */

bool absent_ligne (int ligne, int nmb, int** matrice){
	
	for (int col = 0; col < 9; col++){
		if (matrice[ligne][col]==nmb){
			return false;
		}
	}
	return true;
}



bool absent_colonne (int colonne,int nmb, int** matrice){
	
	for (int li = 0; li < 9; li++){
		if (matrice[li][colonne]==nmb){
			return false;
		}
	}
	return true;
}


bool absent_sur_bloc (int li, int co, int nmb, int** matrice){
	int li_ref = li - li%3 ; //nous ramène toujours à la première ligne du bloc : ligne de reference
	int co_ref = co - co%3 ; //nous ramène toujours à la première colonnedu bloc : colonne de reference

	for (int i=li_ref;i<li_ref+3;i++){
		for (int j=co_ref;j<co_ref+3;j++){
			if (matrice[i][j]==nmb){
				
				return false;
			}
		}
	}
	return true;
}



bool is_safe_here (int li, int co, int nmb, int** matrice){
	if ((absent_ligne(li,nmb,matrice)==true) && (absent_colonne(co,nmb,matrice)==true) && (absent_sur_bloc(li,co,nmb,matrice)==true)){
		return true;
	}
	return false;
}

//#######################################



/* Remplissage récursive du reste de la grille */



bool fill_rest(int li, int co, int** matrice){
	

	if (li == 8 && co == 9) return 1;

	if (co==9){
		co = 0;
		li++;
	}

	if (matrice[li][co]>0){
			return fill_rest(li,co+1,matrice);
	}

	for (int test_num = 1; test_num <= 9; test_num++){
		
		
		if (is_safe_here(li, co, test_num,matrice)==true){
			matrice[li][co] = test_num; //premier test

			//check si ça ira pour la suite
			if (fill_rest(li,co+1,matrice)==1) return 1;

			//si ça bloque après, on réessaye avec un autre test_num
			
		}
		matrice[li][co]=0;
	}
	return 0;

}

//#######################################

	/* Suppression de K éléments : we keep 40 for easy, 33 for medium and 29 for hard */

// Level will be : 1 for easy, 2 for medium, 3 for hard

void remove_elements (int** matrice, int level){
	
	int k; //number of elements that will stay per matrix row
	
	int li;
	int co;

	
	if (level == 1) k = 10;
	else if (level == 2) k = 8 ;
	else if (level == 3) k = 6 ;
	else {
		printf("enter level between 1 and 3\n");
	}

	int compteur;
	int j=0;
	
	while (j<7){
		for (compteur=1;compteur<18;compteur++){
			li=rand()%3;
			co=rand()%9;
			while (matrice[li+j][co]==0)
			{
			li=rand()%3;
			co=rand()%9;
			}

			matrice[li+j][co]=0;	
		}

		j = j+3;
	}

}



//#######################################

/* test si la grille est totalement remplise*/
bool grill_filled (int** matrice){
	int c=0;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if (matrice[i][j]!=0) c++;
		}
	}

	if (c == 81) return true;
	return false;
}



//#######################################

/*Fct qui vérifie si le sudoku est bien résolu*/
bool is_solved (int** matrice){

	bool test;
	int x,y;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			test = is_safe_here(i,j,matrice[i][j],matrice);
			if (!test) {
				x = i;
				y = j;
				return false;}
		}
	}
	return true;

}

//#######################################


int Sudoku(){
	
	srand(time(NULL));

	int **matrice=creer_grille_sudoku();
	fill_diag(matrice);
	
	if (fill_rest(0,0,matrice) == true){
	 	//afficher_grille(matrice);
	 	printf("Sudoku generated successfully\n");
	}

	printf("\n");

	int level;
	printf("Niveau de diffculé, choisir 1 pour facile, 2 pour moyen et 2 pour difficile\n");
	scanf("%d",&level);
	while (level<1 || level>3){
		printf("Error : input level between 1 and 3");
		scanf("%d",&level);
	}

	remove_elements(matrice,level);
	afficher_grille_sudoku(matrice);

	int x,y,a;
	
	bool filled = false;
	while(filled!=true){
		printf("input coordinate x between 1 and 9\n");
		scanf("%d",&x);
		printf("input coordinate y between 1 and 9\n");
		scanf("%d",&y);
		printf("input number to fill with between 1 and 9\n");
		scanf("%d",&a);

		while ((x>9 || x<1) || (y<1 || y>9) || (a<1 || a>9)){
			printf("Error : coordinates not in range, input new ones between 1 and 9\n");
			printf("input coordinate x between 1 and 9\n");
			scanf("%d",&x);
			printf("input coordinate y between 1 and 9\n");
			scanf("%d",&y);
			printf("input number to fill with between 1 and 9\n");
			scanf("%d",&a);

		}

		matrice[x-1][y-1] = a; 
		afficher_grille_sudoku(matrice);
		filled = grill_filled(matrice);
	}

	int ok;
	printf("grill is filled, are you done and want to see the answer ? input 0 for No and 1 for Yes\n");
	scanf("%d",&ok);

	while (ok==0){
		
		printf("which coordinates do you want to update?\n");
		printf("Line coordinate x :\n");
		scanf("%d",&x);
		printf("Column coordinate y \n");
		scanf("%d",&y);
		printf("number to fill in with \n");
		scanf("%d",&a);
		while ((x>9 || x<1) || (y<1 || y>9) || (a<1 || a>9)){
			printf("Error : coordinates not in range, input new ones between 1 and 9\n");
			printf("Line coordinate x :\n");
			scanf("%d",&x);
			printf("Column coordinate y \n");
			scanf("%d",&y);
			printf("number to fill in with \n");
			scanf("%d",&a);
		}

		matrice[x-1][y-1] = a; 
		printf("Are you done?\n");
		scanf("%d",&ok);
	}

	// Vérification 
	bool  test = is_solved(matrice);
	if (test){
		printf("Félicitations! Vous avez réussi\n");
	} else {
		printf("Mauvaise nouvelle.. Vous avez perdu ! ");
	}


	/*Rmq: On peut aussi renvoyer un indice de l'emplacement de l'erreur, mais il n'y en a pas que un. Mais de toute façon,
	si on veut le faire, il suffit de changer le résultat de is_solved en une structure contenant le booléen et des coordonnées 
	(i,j) pris lorsqu'on trouve que is_safe_here est faux. */


	return 0;
}



