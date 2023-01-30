#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVEURNAME "127.0.0.1"
#define PORT 30000
#define BUFFERSIZE 512

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

#define MAX 20


int main ( void )
{

int socketClient= socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in addrClient;
addrClient.sin_addr.s_addr=inet_addr("127.0.0.1");
addrClient.sin_family=AF_INET;
addrClient.sin_port=htons(30000);
connect(socketClient,(const struct sockaddr *)&addrClient,sizeof(addrClient));
printf("connecté\n");

system("clear");

// boolean: when the client recieve this value the tab will change
int boolean=0;

//taille tableau
int plateau[MAX][MAX];
int bateaux[3][2];
int tir[2];
int taille[2];
int essais=0,touches=0;

int lc[2];

title(3);

tailleplateau(taille);
printf("\n");

send(socketClient,&taille,sizeof(taille),0);
initplateau(plateau);
afficheplateau(plateau);

/* envoie de donne et reception */
do {

    tir_j1(tir,plateau,taille);
    essais++;

    // send the shooting coordinates
    send(socketClient,&tir,sizeof(tir),0);

    // read server response
    recv(socketClient,&lc,sizeof(lc),0);
    recv(socketClient,&boolean,sizeof(boolean),0);

    printf("\n");
    system("clear");


    if (boolean==1)
    {
      touches++;
      title(3-touches);
      printf(GREEN"\n****TOUCHE**** (%d,%d)\n"RESET,tir[0]+1,tir[1]+1);
      printf("\nessai %d: \nligne %d -> %d bateaux\ncolonne %d -> %d bateaux\n",essais,tir[0]+1,lc[0],tir[1]+1,lc[1]);
    }
    else{
      title(3-touches);
      printf("\nessai %d: \nligne %d -> %d bateaux\ncolonne %d -> %d bateaux\n",essais,tir[0]+1,lc[0],tir[1]+1,lc[1]);
    }
    printf("\n");
    changeplateau_client(tir,plateau,boolean);
    afficheplateau(plateau,taille);

}while (touches<3);

printf("\nEnfin ce programme de merde fonctionne\ndéso je voulais dire bravo pour votre victoire !!!");
/* fermeture de la connection */
close(socketClient);

return EXIT_SUCCESS;
}