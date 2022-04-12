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


bool absent_sur_bloc (int p, int q, int nmb, int** matrice){
	bool res=true;
	

	int li_ref = p - p%3 ; //nous ramène toujours à la première ligne du bloc : ligne de reference
	int co_ref = q - q%3 ; //nous ramène toujours à la première colonnedu bloc : colonne de reference
	// (li-ref,co_ref) est donc toujours le coin haut gauche du bloc 3*3

	/* On remplit déjà vu */
	for (int i=li_ref;i<li_ref+3;i++){
		for (int j=co_ref;j<co_ref+3;j++){
			if (nmb == matrice[i][j]){
				res = false;
				return res;
			}
		}
	}


	return res;
}


bool absent_li_et_co (int nmb, int p, int q, int** matrice){
	
	
	//parcours colonne
	for(int i=0; i<9;i++){
		if (nmb == matrice[i][q]){
			return false;
		}
	}

	//parcours ligne
	for(int j=0; j<9;j++){ 
		if(nmb==matrice[p][j]){
			return false;						
		}
	}
	return true;
}


bool is_safe_here (int nmb, int p, int q, int** matrice){
	bool li_co = absent_li_et_co(nmb,p,q,matrice);
	bool bloc = absent_sur_bloc(p,q,nmb,matrice);
	if (li_co==true && bloc==true){
		return true;
	}
	return false;
}



void fill_reste_grille(int ** matrice){
	
	/*sous-blocs en haut*/
	
	/*int chiffres[9];
	for (int k=0;k<9;k++){
		chiffres[k]=k+1 ;
		printf("%d\n",chiffres[k]);
	}*/

	bool test;

	int nmb = 1;

	for (int i=6;i<9;i++){
		for (int j=0;j<6;j++){
			
			while (matrice[i][j]==0){
				test = is_safe_here(nmb,i,j,matrice);
				if (test == false){
					nmb = nmb + 1;
					test = is_safe_here(nmb,i,j,matrice);
				} else if (test==true){
					matrice[i][j]=nmb;
					nmb = 1;
				}

			}
		
		}
	} 
	
}

int main (){
	srand(time(NULL));
	int **sudoku=creer_grille();
	//printf("%d\n",sudoku[3][2]);


	fill_diag(sudoku);

	//bool test=is_safe_here(7,0,8,sudoku);
	//printf("%d \n",test);

	fill_reste_grille(sudoku);
	afficher_grille(sudoku);


return 0;
}
