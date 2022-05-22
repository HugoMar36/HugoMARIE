#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "pacman.h"

#define H 30
#define W 60
#define NR_GOSTS 4
#define NB_LIVES 3

void crea_player(struct coordinate p_coor, struct PacMan* player){
	player->coor=p_coor;
	player->nx=0;
	player->ny=0;
	player->lives=NB_LIVES;
	player->food=0;
}


char area[H][W]={
   { "############################################################" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#        # # # # #          #             # # # # # #      #" },
   { "#        #       #         # #            #                #" },
   { "#        #       #        #   #           #                #" },
   { "#        # # # # #       #     #          #                #" },
   { "#        #              # # # # #         #                #" },
   { "#        #             #         #        #                #" },
   { "#        #            #           #       #                #" },
   { "#        #           #             #      #                #" },
   { "#        #          #               #     # # # # # #      #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#        ##        ##           #          ##        #     #" },
   { "#        # #      # #          # #         # #       #     #" },
   { "#        #  #    #  #         #   #        #  #      #     #" },
   { "#        #    # #   #        #     #       #   #     #     #" },
   { "#        #     #    #       # # # # #      #    #    #     #" },
   { "#        #          #      #         #     #     #   #     #" },
   { "#        #          #     #           #    #      #  #     #" },
   { "#        #          #    #             #   #       # #     #" },
   { "#        #          #   #               #  #        ##     #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "############################################################" }
};

void affichage(char area[H][W]){
	for(int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			printf("%c", area[i][j]);
		}
		printf("\n");
	}
}


struct coordinate generate_coor(){
	int gen_x;
	int gen_y;
	bool test=false;
	while(test==false){
		gen_x=rand()%W;
		gen_y=rand()%H;
		if(area[gen_x][gen_y]!=('#') || (gen_x!=1 && gen_y!=1)){
			test=true;
		}
	}
	struct coordinate coor={gen_x,gen_y};
	return(coor);
}

struct Ghost* initialize_Ghosts(struct Ghost allGhosts[NR_GOSTS], char area[H][W]){
	for(int i=0;i<NR_GOSTS;i++){
		allGhosts[i].coor=generate_coor();
		printf("%c\n", allGhosts[i].coor.x);
		printf("%c\n", allGhosts[i].coor.y);
		area[allGhosts[i].coor.x][allGhosts[i].coor.y]=('G');
		allGhosts[i].food_before='.';
	}
	return (allGhosts);
}

void initialize_area(char area[H][W]){
	for(int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			if(area[i][j]==' '){
				area[i][j]='.';
			}
		}
	}
	area[1][1]='P';
}


void input(struct PacMan *player){
	printf("rentrer une commande\n");
	char buffer;
	scanf("%c", &buffer);
	if(buffer=='z'){player->ny=1; player->nx=0;}
	if(buffer=='q'){player->nx=1; player->ny=0;}
	if(buffer=='s'){player->ny=-1; player->nx=0;}
	if(buffer=='d'){player->nx=-1; player->ny=0;}
	if(buffer!='z' && buffer!='q' && buffer!='s' && buffer!='d'){
		printf("commande non valide\n");
		input(player);
	}

}

void move_Ghost(struct Ghost allGhosts[NR_GOSTS],char area[H][W]){
	int buffer;
	bool test=false;
	for(int i=0;i<NR_GOSTS;i++){
		while(test=false){
			test=true;
			buffer=rand()%4;
			if(buffer==0){allGhosts[i].ny=1; allGhosts[i].nx=0;}
			if(buffer==1){allGhosts[i].nx=1; allGhosts[i].ny=0;}
			if(buffer==2){allGhosts[i].ny=-1; allGhosts[i].nx=0;}
			if(buffer==3){allGhosts[i].nx=-1; allGhosts[i].ny=0;}
			if(area[allGhosts[i].nx][allGhosts[i].ny]=='#'){test=false;}
		}
		test=false;
		area[allGhosts[i].coor.x][allGhosts[i].coor.y]=allGhosts[i].food_before;
		allGhosts[i].coor.x=allGhosts[i].nx;
		allGhosts[i].coor.y=allGhosts[i].ny;
		if(area[allGhosts[i].coor.x][allGhosts[i].coor.y]=='.'){allGhosts[i].food_before='.';}
		else{allGhosts[i].food_before=' ';}
		area[allGhosts[i].coor.x][allGhosts[i].coor.y]='G';
	}
	affichage(area);
}



void move_player(struct PacMan *player, char area[H][W], struct coordinate p_coor){
	printf("move_player2\n");
	area[player->coor.x][player->coor.y]=' ';
	player->coor.x=player->nx;
	player->coor.y=player->ny;
	if(area[player->coor.x][player->coor.y]=='#' || area[player->coor.x][player->coor.y]=='G'){
		printf("move_player3\n");
		player->lives=player->lives-1;
		player->coor=p_coor;
	}
	else{
		printf("move_player4\n");
		if(area[player->coor.x][player->coor.y]==1){printf("move_player5\n");player->food+=1;}
		area[player->coor.x][player->coor.y]='P';
	}
}

bool check_lives(struct PacMan *player, char area[H][W]){
	printf("check_lives\n");
	if(player->lives==0){printf("Perdu! score:%d\n", player->food); return false ;}
	else{affichage(area); return (true);}

}



int Pacman()
{
	srand(time(NULL));
	struct coordinate p_coor={1,1};
	struct PacMan *player=malloc(sizeof(struct PacMan));
	crea_player(p_coor, player);

	struct Ghost allGhosts[NR_GOSTS];
	initialize_Ghosts(allGhosts, area);



	initialize_area(area);
	affichage(area);
	bool test=true;
	while(test=true){
		input(player);
		move_Ghost(allGhosts, area);
		move_player(player, area, p_coor);
		test=check_lives;
	}




}

