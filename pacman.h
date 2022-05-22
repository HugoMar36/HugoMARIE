#ifndef __PACMAN_H__
#define __PACMAN_H__



struct coordinate { 
	unsigned int x; 
	unsigned int y;
};
struct PacMan {
	struct coordinate coor;
	unsigned int nx;
	unsigned int ny;
	unsigned int lives;
	unsigned int food;
};
struct Ghost {
	struct coordinate coor; 
	unsigned int nx; 
	unsigned int ny;
	unsigned char food_before;
};


void crea_player(struct coordinate p_coor, struct PacMan* player);
void affichage(char area[30][60]);
struct Ghost* initialize_Ghosts(struct Ghost allGhosts[4], char area[30][60]);
void initialize_area(char area[30][60]);
void input(struct PacMan *player);
void move_Ghost(struct Ghost allGhosts[4], char area[30][60]);
void move_player(struct PacMan *player, char area[30][60], struct coordinate p_coor);
bool check_end(struct PacMan *player, char area[30][60]);
int Pacman();

#endif
