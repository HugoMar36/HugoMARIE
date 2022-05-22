#ifndef __SUDOKU_H__
#define __SUDOKU_H__


int** creer_grille_sudoku();
void afficher_grille_sudoku(int **matrice);
void fill_diag( int **area);
bool absent_ligne (int ligne, int nmb, int** matrice);
bool absent_colonne (int colonne,int nmb, int** matrice);
bool absent_sur_bloc (int li, int co, int nmb, int** matrice);
bool is_safe_here (int li, int co, int nmb, int** matrice);
bool fill_rest(int li, int co, int** matrice);
void remove_elements (int** matrice, int level);
bool grill_filled (int** matrice);
bool is_solved (int** matrice);

int Sudoku();




#endif
