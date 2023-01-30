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


int main ( void )
{


int socketClient= socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in addrClient;
addrClient.sin_addr.s_addr=inet_addr(SERVEURNAME);
addrClient.sin_family=AF_INET;
addrClient.sin_port=htons(PORT);
connect(socketClient,(const struct sockaddr *)&addrClient,sizeof(addrClient));
//printf("connecté\n");
system("clear");

printf ("\n\t******************************\n\t****Projet bataille navale****\n\t******************************\n\n");

// boolean: when the client recieve this value the tab will change

int boolean=0;

// game initialization
int tir[2];
int touches=0;
int essais=0;
int plateau[5][5];
int lc[2];

title(3);

initplateau(plateau);
afficheplateau(plateau);

while (touches<3){


    tir_j1(tir,plateau);
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
      printf(GREEN"****TOUCHE**** (%d,%d)\n"RESET,tir[0]+1,tir[1]+1);
      printf("\nessai %d: \nligne %d -> %d bateaux\ncolonne %d -> %d bateaux\n",essais,tir[0]+1,lc[0],tir[1]+1,lc[1]);
    }
    else{
      title(3-touches);
      printf("\nessai %d: \nligne %d -> %d bateaux\ncolonne %d -> %d bateaux\n",essais,tir[0]+1,lc[0],tir[1]+1,lc[1]);
      printf("\n");
    }
    changeplateau_client(tir,plateau,boolean);
    afficheplateau(plateau);
    

}

printf("\nvous avez perdu");
printf("\nMais le plus impoertant c'est que ce programme de merde fonctionne");
/* fermeture de la connection */
close(socketClient);

return EXIT_SUCCESS;
}