#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>                     
#include <sys/socket.h>
#include <netinet/in.h>       
#include <arpa/inet.h>
#include <signal.h>


#include "bnv.h"


#define FFLUSH_MY_STDIN() {int _c_; while ((_c_ = getchar()) != '\n' && _c_ != EOF){}} 
#define BUFFERSIZE 512
#define PORT 30000

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

int socketServer = socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in addrSerever;
addrSerever.sin_addr.s_addr=htonl(INADDR_ANY);;
addrSerever.sin_family=AF_INET;
addrSerever.sin_port=htons(30000);

bind(socketServer,(const struct sockaddr *)&addrSerever,sizeof(addrSerever));
//printf("bind : %d\n",socketServer);

listen(socketServer,5);

struct sockaddr_in addrClient;
socklen_t csize = sizeof(addrClient);

//printf("accept\n");

int id=0;

printf ("\n\n\t******************************\n\t****Projet bataille navale****\n\t******************************\n");

while (1) {

    int socketClient = accept(socketServer, (struct sockaddr *)&addrClient,&csize);
    //printf("\nclient: %d\n",socketClient);
    id++;
    printf ("\n\n************************************************************\n");
    printf("le joueur %d rejoint le serveur\n\n ",id);


    if (fork()==0)
    {
        close(socketServer);

        //int id=c;

        send(socketClient,&id,sizeof(id),0);

        int plateau[5][5];
        int bateaux[3][2];
        int tir[2];
        tir[0]=-1;
        tir[1]=-1;
        int essais=0,touches=0;
        initplateau(plateau);           
        initbateau(bateaux);
        afficheplateauclaire(plateau);

        int lc[2];

        while (touches<3) {

            int boolean=0;

            recv(socketClient,&tir,sizeof(tir),0);              
            essais++;

            printf ("\n\n************************************************************\n");

            if ((tir[0]==-1) && (tir[1]==-1)){
                printf("le joueur %d c'est déconecté\n\n",id),
                close(socketClient);

                return EXIT_SUCCESS;
            }

            printf("joueur %d \n",id);


            if(touche (tir,bateaux))
            {
                com(tir,bateaux,essais,lc);
                printf(GREEN"****TOUCHE**** (%d,%d)\n"RESET,tir[0]+1,tir[1]+1);
                touches++;
                boolean=1;
                
            }
                else
                com(tir,bateaux,essais,lc);
                
            changeplateau(tir,bateaux,plateau);
            afficheplateauclaire(plateau);

            tir[0]=-1;
            tir[1]=-1;

            send(socketClient,&lc,sizeof(lc),0);
            send(socketClient,&boolean,sizeof(boolean),0);
        }
        printf("\nle joueur %d a gagné !\n\n",id),
        close(socketClient);
        shutdown(socketClient,2);
        return EXIT_SUCCESS;

    }

 

}

shutdown(socketServer,2);
close(socketServer);

return EXIT_SUCCESS;
}


/*
 * Lorsque SIGINT arrive la fonction deroute() demande
 * si on veut réellement stopper le serveur !
 * Dès qu'un processus fils meure on le termine rééllement
 */