#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#define MYMSG "SENT MSG"

int main(){
        int clientSocket, portNum = 3000,clientMsgSize;
        char Buffer[1024];
        struct sockaddr_in serverAddr;

        //Create Socket
        clientSocket = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);

        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(portNum);
        serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");


        
        //connect
        if(!connect(clientSocket,(struct sockaddr*) &serverAddr, sizeof(serverAddr))){
                printf("Successfully Connected\n");
        }
        else{
                perror("Cannot connect\n");
                exit(1);
        }         

        send(clientSocket,MYMSG,sizeof(MYMSG),0);
        recv(clientSocket, Buffer, 1024, 0);
        printf("Received: %s\n",Buffer);
        
        close(clientSocket);
}             
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                      
                
