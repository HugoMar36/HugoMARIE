#ifndef __MORPION_H__
#define __MORPION_H__


int* creer_grille();
void afficher(int* X );
void test_affichage();
void placer(int* grille, int chiffre, int joueur);
void placer_alea(int* grille, int joueur);
int a_gagne(int* grille,int joueur);
int Morpion();
#endif
