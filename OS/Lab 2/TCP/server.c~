#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#define MYMSG "Received Msg"

int main(){
        int clientSocket,  serverSocket, portNum = 3000,clientMsgSize;
        char Buffer[1024];
        struct sockaddr_in serverAddr;

        //Create Socket
        serverSocket = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);

        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(portNum);
        serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");


        //bind
        bind(serverSocket,(struct socketaddr *)&serverAddr, sizeof(serverAddr));
        
        //Listen
        if(listen(serverSocket,5)){
                perror("Error\n");
                exit(1);
         }
         
         //accept
         while(1){
                clientSocket = accept(serverSocket,NULL,NULL);  
                clientMsgSize = recv(clientSocket,Buffer,sizeof(Buffer),0);
                printf("Received: %s\n",Buffer);
                send(clientSocket,MYMSG,sizeof(MYMSG),0);
                close(clientSocket);
        }
}             
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                      
                
