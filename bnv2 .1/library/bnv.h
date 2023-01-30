#ifndef AFFICHEPLATEAU_H  /* Include guard */
#define AFFICHEPLATEAU_H 

#define MAX 20

void changeplateau(int tir[2], int bateaux[][2], int plateau[][MAX]);
void initbateau(int bateaux[][2],int taille[2]);
void initplateau(int plateau[][MAX]); 
void tir_j1(int tir[2], int plateau[][MAX],int taille[2]);
int touche (int tir[2], int bateaux[][2]);
int touche2(int tir[2], int plateau[][MAX]);
void tailleplateau(int taille[2]);

// uniquement pour le client
void afficheplateau(int plateau[][MAX],int taille[2]);
void changeplateau_client(int tir[2],int plateau[][MAX],int boolean);
void title(int a);

//uniquement pour le serveur
void afficheplateauclaire(int plateau[][MAX],int taille[2]);
void com(int tir[2], int bateaux[][2], int essai, int lc[2]);

#endif 
