#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define size 9 


int** creer_grille()
	{
 	int **matrice;
 	matrice=malloc(9*sizeof(int*));
 	for(int i=0; i<9;i++){
 		matrice[i]=calloc(9, sizeof(int));
 	}
 	return(matrice);
	}

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

void afficher_grille(int **matrice){
	for(int i=0; i<9; i++){
			for(int k=0; k<9; k++){
				printf("%d ", matrice[i][k]);
				}printf("\n");}
}


bool is_safe_here(int nmb, int p, int q, int** matrice){
	bool test=true;
	int *deja_vu_li=calloc(9,sizeof(int));
	int *deja_vu_col=calloc(9,sizeof(int));
	int ind=0;
	for(int i=0; i<9;i++){
		if(i!=q){deja_vu_li[i]=matrice[p][i];}
		if(i!=p){deja_vu_col[i]=matrice[i][q];}
	}
	for(int j=0; j<9;j++){ 
		if(nmb==deja_vu_li[j] || nmb==deja_vu_col[j]){
			test =false;						
		}}
	return test;
}

int** fill_grille(int ** matrice){
	
}

int main (){
	srand(time(NULL));
	int **sudoku=creer_grille();
	printf("%d\n",sudoku[3][2]);

	fill_diag(sudoku);
	afficher_grille(sudoku);


return 0;
}
