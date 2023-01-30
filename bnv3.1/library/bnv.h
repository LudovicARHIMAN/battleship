#ifndef AFFICHEPLATEAU_H  /* Include guard */
#define AFFICHEPLATEAU_H

// pour les deux
void initbateau(int bateaux[][2]);
void initplateau(int plateau[][5]); 

// uniquement pour le client
void afficheplateau(int plateau[][5]);
void changeplateau_client(int tir[2],int plateau[][5],int boolean);
void tir_j1(int tir[2], int plateau[][5]);
void title(int a, int id);

//uniquement pour le serveur
void changeplateau(int tir[2], int bateaux[][2], int plateau[][5]);
void afficheplateauclaire(int plateau[][5]);
void com(int tir[2], int bateaux[][2], int essai, int lc[2]);
int touche (int tir[2], int bateaux[][2]);

#endif 
