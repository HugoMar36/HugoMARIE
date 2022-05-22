#include <stdio.h>
#include <stdlib.h>
#include<time.h>
 
 #include"morpion.h"

int* creer_grille(){
		int* grille = malloc(1024*9);   
		return grille;
}

void afficher(int* X ){

	
	for (int k=0 ; k<9; k=k+3){
	for(int i=0 ; i<2 ; i++){
			


			if(X[k+i]==0){
				printf(".,");}
			if(X[k+i]==1){
				printf("x,");}
			if(X[k+i]==2){
				printf("o,");}

	}
			if(X[k+2]==0){
				printf(".\n");}
			if(X[k+2]==1){
				printf("x,\n");}
			if(X[k+2]==2){
				printf("o,\n");}

}
}

void test_affichage(){

	int* grille = creer_grille(); 
	grille[4-1]=1;
	grille[8-1]=2;
	afficher(grille);
	free(grille);
}


void placer(int* grille, int chiffre, int joueur){

	grille[chiffre-1]=joueur;

}

void placer_alea(int* grille, int joueur){

			int chiffreAl;
			chiffreAl= rand()%9;
			
			while(grille[chiffreAl] !=0 ){
			chiffreAl = rand()%9;
				}

			int chiffre = chiffreAl +1;
			placer(grille,chiffre,joueur);

}

int a_gagne(int* grille,int joueur){


		if(grille[0]==joueur && grille[1]==joueur&& grille[2]==joueur){return joueur;}
		if(grille[3]==joueur && grille[4]==joueur && grille[5]==grille[4]){return joueur;}
		if(grille[6]==joueur&& grille[7]==joueur && grille[8]==grille[7]){return joueur;}

		if(grille[0]==joueur && grille[3]==joueur && grille[6]==grille[0]){return joueur;}
		if(grille[1]==joueur && grille[4]==joueur && grille[7]==grille[1]){return joueur;}
		if(grille[2]==joueur&& grille[5]==joueur && grille[8]==grille[2]){return joueur;}
		
		if(grille[0]==joueur && grille[4]==joueur && grille[8]==grille[0]){return joueur;}
		if(grille[6]==joueur && grille[4]==joueur && grille[2]==grille[6]){return joueur;}

		return 0;
}



 int Morpion(){
 	
 	
	srand(time(0));
	int turn= 0;
 	int* grille = creer_grille(); 
	int vainqueur=0;
	int chiffre;
	while(vainqueur == 0 && turn<9){
		afficher(grille);
		scanf("%d",&chiffre);
		placer(grille, chiffre , 1);
		placer_alea(grille, 2);
		vainqueur=a_gagne(grille,1);
		if (vainqueur==0){
			vainqueur=a_gagne(grille,2);
		}
		turn=turn+2;
	}
	
	if(turn==10){printf("match nul en 9 tours\n");}
	else{
		afficher(grille);
	printf("%d\n",vainqueur);}

	return(0);
}
 
  