#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include "bnv.h"

// COULEURS
#define RESET              "\x1b[0m"
#define BLACK              "\x1b[30m"
#define RED                "\x1b[31m"
#define GREEN              "\x1b[32m"
#define YELLOW             "\x1b[33m"
#define BLUE               "\x1b[34m"
#define MAGENTA            "\x1b[35m"
#define CYAN               "\x1b[36m"
#define WHITE              "\x1b[37m"




// pour les deux

void initplateau(int plateau[0][5])          //initialise le plateau
{
    int ligne, colonne;
    for(ligne=0 ; ligne < 5 ; ligne++ )     //  0 1 2 3 4
        for(colonne=0 ; colonne < 5 ; colonne++ ) // 0 1 2 3 4
            plateau[ligne][colonne]=-1;
}




void changeplateau(int tir[2], int bateaux[][2], int plateau[][5])
{
    if(touche(tir,bateaux))
        plateau[tir[0]][tir[1]]=1;
    else
        plateau[tir[0]][tir[1]]=0;
}



void initbateau(int bateaux[][2])
{
    srand(time(NULL));                  // initialise le random
    int bat, dern;
 
    for(bat=0 ; bat < 3 ; bat++)
    {
        bateaux[bat][0]= rand()%5;
        bateaux[bat][1]= rand()%5;
 
        /* on vérifie que le tir n'a pas déjà été fait, si le tir est fait on sort  
         * de la boucle dowhile, si pas déjà fait ça marche */
        for(dern=0 ; dern < bat ; dern++)  //dern 0 1 2
        {
            if((bateaux[bat][0] == bateaux[dern][0])&&(bateaux[bat][1] == bateaux[bat][1]))
                do
                {
                    bateaux[bat][0]= rand()%5;
                    bateaux[bat][1]= rand()%5;
                }
                while((bateaux[bat][0] == bateaux[dern][0])&&(bateaux[bat][1] == bateaux[dern][1]));
        }
    }
}
 

int touche (int tir[2], int bateaux[][2])
{
    int bat;
 
    for(bat=0 ; bat < 3 ; bat++)
    {
        if( tir[0]==bateaux[bat][0] && tir[1]==bateaux[bat][1])
        {
            
            return 1;
        }
    }
    return 0;
}























// uniquement pour le client


void changeplateau_client(int tir[2],int plateau[][5],int boolean)
{
    if(boolean==1)
        plateau[tir[0]][tir[1]]=1;
    else
        plateau[tir[0]][tir[1]]=0;
}

void afficheplateau(int plateau[][5])
{
    int ligne, colonne;
 
    //printf("\t1 \t2 \t3 \t4 \t5"); // 1 2 3 4 5
    for (int k=0;k<5;k++)
    {
        printf(CYAN"\t%d"RESET,k+1); // 1 2 3 4 5
    }
    printf("\n");
 
    for(ligne=0 ; ligne < 5 ; ligne++ )   // for l 0 1 2 3 4
    {
        printf(CYAN"%d"RESET,ligne+1);
        for(colonne=0 ; colonne < 5 ; colonne++ )
        {
            if(plateau[ligne][colonne]==-1)
            {
                printf("\tH");
            }
            else if(plateau[ligne][colonne]==0)
            {
                printf(RED"\tO"RESET);
            }
            else if(plateau[ligne][colonne]==1)
            {
                printf(GREEN"\tX"RESET);
            }
        }
        printf("\n");
    }
 
}

void tir_j1(int tir[2],int plateau[][5])
{
    printf("\nEntrez la ligne du tir : ");
    while((scanf("%d",&tir[0])!= 1) || ((tir[0]<1)||(tir[0]>5)))
    {
        printf(RED"rentrez un nombre plus petit que 6 et plus grand que 0:"RESET);
        while(getchar() != '\n');
    }
    tir[0]--;

 
    printf("\nEntre la colonne du tir : ");
    while((scanf("%d",&tir[1])!= 1) || ((tir[1]<1)||(tir[1]>5)))
    {
        printf(RED"rentrez un nombre plus petit que 6 et plus grand que 0:"RESET);
        while(getchar() != '\n');
    }
    tir[1]--;

    if (plateau[tir[0]][tir[1]]==1)
    {
        printf(GREEN"la cible à déja été touchée à l'emplacement (%d,%d). Veuillez réésayer\n"RESET,tir[0]+1,tir[1]+1);
        tir_j1(tir,plateau);
        
    }

    if (plateau[tir[0]][tir[1]]==0)
    {
        printf(CYAN"Il n'y a rien à l'emplacement (%d,%d) Veuillez réésayer\n"RESET,tir[0]+1,tir[1]+1);
        tir_j1(tir,plateau);
        
    }

}
























//uniquement pour le serveur

void com(int tir[2], int bateaux[][2], int essai,int lc[2])
{
    int ligne=0,colonne=0,rang;
 
    //compte le nombre de bateaux ligne/colonne
    for(rang=0 ; rang < 3 ; rang++)
    {
        if(bateaux[rang][0]==tir[0])
            ligne++;
        if(bateaux[rang][1]==tir[1])
            colonne++;
    }

    lc[0]=ligne;
    lc[1]=colonne;
 
    printf("\nessai %d: \nligne %d -> %d bateaux\ncolonne %d -> %d bateaux\n",essai,tir[0]+1,ligne,tir[1]+1,colonne);
}

void afficheplateauclaire(int plateau[0][5])
{
    int ligne, colonne;
 
    //printf("\t1 \t2 \t3 \t4 \t5"); // 1 2 3 4 5
    for (int k=0;k<5;k++)
    {
        printf(CYAN"\t%d"RESET,k+1); // 1 2 3 4 5
    }
    printf("\n");
 
    for(ligne=0 ; ligne < 5 ; ligne++ )   // for l 0 1 2 3 4
    {
        printf(CYAN"%d"RESET,ligne+1);
        for(colonne=0 ; colonne < 5 ; colonne++ )
        {
            if(plateau[ligne][colonne]==-1)
            {
               printf("\t%d",plateau[ligne][colonne]);
            }
            else if(plateau[ligne][colonne]==0)
            {
                printf(RED"\t%d"RESET,plateau[ligne][colonne]);
            }
            else if(plateau[ligne][colonne]==1)
            {
                printf(GREEN"\t%d"RESET,plateau[ligne][colonne]);
            }
        }
        printf("\n");
    }
    
}




void title(int a,int id)
{
    printf("                       $o                                                      \n");
    printf("                        $                     .........                        \n");
    printf("                       $$$      .oo..     'oooo'oooo'ooooooooo....             \n");
    printf("                        $       $$$$$$$                                        \n");
    printf("                    .ooooooo.   $$!!!!!                  bataille navale       \n");
    printf("                  .'.........'. $$!!!!!      o$$oo.        joueur  %d          \n",id);
    printf("     $          .o'  oooooo   '.$$!!!!!      $$!!!!!  %d bateaux à éliminer !  \n",a);
    printf("  ..o$ooo...    $                '!!''!.     $$!!!!!                           \n");
    printf("  $    ..  '''oo$$$$$$$$$$$$$.    '    'oo.  $$!!!!!                           \n");
    printf("  !.......      '''..$$ $$ $$$   ..        '.$$!!''!                           \n");
    printf("  !!$$$!!!!!!!!oooo......   '''  $$ $$ :o           'oo.                       \n");
    printf("  !!$$$!!!$$!$$!!!!!!!!!!oo.....     ' ''  o$$o .      ''oo..                  \n");
    printf("  !!!$$!!!!!!!!!!!!!!!!!!!!!!!!!!!!ooooo..      'o  oo..    $                  \n");
    printf("   '!!$$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!oooooo..  ''   ,$                  \n");
    printf("    '!!$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!oooo..$$                  \n");
    printf("     !!$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!$'                  \n");
    printf("     '$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$!!!!!!!!!!!!!!!!!!,                  \n");
    printf(" .....$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$.....             \n\n");
}