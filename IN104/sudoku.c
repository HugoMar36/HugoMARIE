#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define size 9 


void initialiserMatrice(int** matrice, int n, int m)
{
    int i=0, j=0;
 
    matrice=malloc(n*sizeof(int*));
    printf("size matrice: %ld\n", sizeof(matrice));
    if (matrice==NULL)
    {
        printf("Allocation impossible");
        exit(0);
    }
 
 
    for(i=0; i<n; i++)
    {
        matrice[i]=calloc(m, sizeof(int));
 
        if(matrice[i]==NULL)
        {
            printf("Allocation impossible");
            exit(0);
        }
    }
 
 
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            matrice[i][j]=0;
        }
    }
}


void fill_diag( int **area){
	int j=0;
	unsigned int deja_vu[9];
	unsigned int gen_nmb;
	unsigned int ind=0;
	bool test=true;
	while(j<9){
		for(int i=j; i<j+3; i++){
			for(int k=j; k<j+3; k++){
				gen_nmb=rand()%10+1;
				for(int q=0; q<9;q++){ 
					if(gen_nmb==deja_vu[q]){
						test =false;
					}}
				if(test){
					area[i][k]=gen_nmb;
					deja_vu[ind]=gen_nmb;
					ind+=1;
					}

			}

		}

		j=j+42;
	}
}

int main (){
	int **sudoku;
	initialiserMatrice(sudoku,9,9);
	fill_diag(sudoku);
	for(int i=0; i<9; i++){
			for(int k=0; k<9; k++){
				printf("%d\n", sudoku[i][k]);
}}
return 0;
}
