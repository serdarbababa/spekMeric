//
//  Haberlesme.h
//  mericSpek
//
//  Created by ser on 26/10/2017.
//  Copyright © 2017 home sweet home. All rights reserved.
//

#ifndef Haberlesme_h
#define Haberlesme_h

#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>


using namespace std;
class Haberlesme{
    
public:
    int PORT;
    int BACKLOG;
    Haberlesme(){
        PORT =3490;
        BACKLOG=10;
    }
    
    int test(){
        //grab the port number
        int port = PORT;
        //buffer to send and receive messages with
        char msg[1500];
        
        //setup a socket and connection tools
        sockaddr_in servAddr;
        bzero((char*)&servAddr, sizeof(servAddr));
        servAddr.sin_family = AF_INET;
        servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servAddr.sin_port = htons(port);
        
        //open stream oriented socket with internet address
        //also keep track of the socket descriptor
        int serverSd = socket(AF_INET, SOCK_STREAM, 0);
        if(serverSd < 0)
        {
            cerr << "Error establishing the server socket" << endl;
            exit(0);
        }
        //bind the socket to its local address
        int bindStatus = ::bind(serverSd, (struct sockaddr*) &servAddr,sizeof(servAddr));
        if(bindStatus < 0)
        {
            cerr << "Error binding socket to local address" << endl;
            exit(0);
        }
        cout << "Waiting for a client to connect..." << endl;
        //listen for up to 5 requests at a time
        listen(serverSd, 5);
        //receive a request from client using accept
        //we need a new address to connect with the client
        sockaddr_in newSockAddr;
        socklen_t newSockAddrSize = sizeof(newSockAddr);
        //accept, create a new socket descriptor to
        //handle the new connection with client
        int newSd = accept(serverSd, (sockaddr *)&newSockAddr, &newSockAddrSize);
        if(newSd < 0)
        {
            cerr << "Error accepting request from client!" << endl;
            exit(1);
        }
        cout << "Connected with client!" << endl;
        //lets keep track of the session time
        struct timeval start1, end1;
        gettimeofday(&start1, NULL);
        //also keep track of the amount of data sent as well
        int bytesRead, bytesWritten = 0;
        while(1)
        {
            //receive a message from the client (listen)
            cout << "Awaiting client response..." << endl;
            memset(&msg, 0, sizeof(msg));//clear the buffer
            bytesRead += recv(newSd, (char*)&msg, sizeof(msg), 0);
            if(!strcmp(msg, "exit"))
            {
                cout << "Client has quit the session" << endl;
                break;
            }
            cout << "Client: " << msg << endl;
            cout << ">";
            string data;
            getline(cin, data);
            memset(&msg, 0, sizeof(msg)); //clear the buffer
            strcpy(msg, data.c_str());
            if(data == "quit")
            {
                //send to the client that server has closed the connection
                send(newSd, (char*)&msg, strlen(msg), 0);
                break;
            }
            //send the message to client
            bytesWritten += send(newSd, (char*)&msg, strlen(msg), 0);
        }
        //we need to close the socket descriptors after we're all done
        gettimeofday(&end1, NULL);
        close(newSd);
        close(serverSd);
        cout << "********Session********" << endl;
        cout << "Bytes written: " << bytesWritten << " Bytes read: " << bytesRead << endl;
        cout << "Elapsed time: " << (end1.tv_sec - start1.tv_sec)
        << " secs" << endl;
        cout << "Connection closed..." << endl;
        return 0;
    }
    
    
    
    void haberles(){
        
        struct sockaddr_in server;
        struct sockaddr_in dest;
        int status,socket_fd, client_fd,num;
        socklen_t size;
        
        char buffer[10241];
        char *buff;
        
        int yes =1;
        
        
        
        if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0))== -1) {
            fprintf(stderr, "Socket failure!!\n");
            exit(1);
        }
        
        if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
            perror("setsockopt");
            exit(1);
        }
        memset(&server, 0, sizeof(server));
        memset(&dest,0,sizeof(dest));
        server.sin_family = AF_INET;
        server.sin_port = htons(PORT);
        server.sin_addr.s_addr = INADDR_ANY;
        //if ((bind(socket_fd, (struct sockaddr *)&server, sizeof(struct sockaddr )))== -1)    {
        if ((int)(::bind(socket_fd, (struct sockaddr *)&server, sizeof(struct sockaddr )))== -1)    { //sizeof(struct sockaddr)
            fprintf(stderr, "Binding Failure\n");
            exit(1);
        }
        
        if ((listen(socket_fd, BACKLOG))== -1){
            fprintf(stderr, "Listening Failure\n");
            exit(1);
        }
        
        
        while(1) {
            int messageCounter =0;
            
            size = sizeof(struct sockaddr_in);
            
            if ((client_fd = accept(socket_fd, (struct sockaddr *)&dest, &size))==-1 ) {
                perror("accept");
                exit(1);
            }
            printf("Server got connection from client %s\n", inet_ntoa(dest.sin_addr));
            
            while(1) {
                if(messageCounter == 0){
                    if ((num = recv(client_fd, buffer, 1024,0))== -1) {
                        perror("recv");
                        exit(1);
                    }
                    else if (num == 0) {
                        printf("Connection closed\n");
                        
                        break;
                    }
                    
                    buffer[num-1] = '1';
                    buffer[num] = '1';
                    buffer[num+1] = 'a';
                    buffer[num+2] = '\0';
                    
                    printf("Server:Msg Received %s\n", buffer);
                    if ((send(client_fd,buffer, strlen(buffer)+2,0))== -1)
                    {
                        fprintf(stderr, "Failure Sending Message\n");
                        close(client_fd);
                        break;
                    }
                    
                    printf("Server:Msg being sent: %s\nNumber of bytes sent: %d\n",buffer, (int)strlen(buffer));
                    
                }
                
            }
            
            close(client_fd);
        }
        
        close(socket_fd);
        return ;
        
    }
    
    

    
    /*
    void basla(){
            struct sockaddr_in server;
            struct sockaddr_in dest;
            int status,socket_fd, client_fd,num;
            socklen_t size;
            
            char buffer[10241];
            char *buff;
            
            int yes =1;
            
            
            
            if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0))== -1) {
                fprintf(stderr, "Socket failure!!\n");
                exit(1);
            }
            
            if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
                perror("setsockopt");
                exit(1);
            }
            memset(&server, 0, sizeof(server));
            memset(&dest,0,sizeof(dest));
            server.sin_family = AF_INET;
            server.sin_port = htons(PORT);
            server.sin_addr.s_addr = INADDR_ANY;
            //if ((bind(socket_fd, (struct sockaddr *)&server, sizeof(struct sockaddr )))== -1)    {
            if ((int)(bind(socket_fd, (struct sockaddr *)&server, sizeof(struct sockaddr )))== -1)
            { //sizeof(struct sockaddr)
                fprintf(stderr, "Binding Failure\n");
                exit(1);
            }
            
            if ((listen(socket_fd, BACKLOG))== -1){
                fprintf(stderr, "Listening Failure\n");
                exit(1);
            }
            
            
            while(1) {
                int messageCounter =0;
                
                size = sizeof(struct sockaddr_in);
                
                if ((client_fd = accept(socket_fd, (struct sockaddr *)&dest, &size))==-1 ) {
                    perror("accept");
                    exit(1);
                }
                printf("Server got connection from client %s\n", inet_ntoa(dest.sin_addr));
                
                while(1) {
                    if(messageCounter == 0){
                        if ((num = recv(client_fd, buffer, 1024,0))== -1) {
                            perror("recv");
                            exit(1);
                        }
                        else if (num == 0) {
                            printf("Connection closed\n");
                            
                            break;
                        }
                        
                        buffer[num-1] = '1';
                        buffer[num] = '1';
                        buffer[num+1] = 'a';
                        buffer[num+2] = '\0';
                        
                        printf("Server:Msg Received %s\n", buffer);
                        if ((send(client_fd,buffer, strlen(buffer)+2,0))== -1)
                        {
                            fprintf(stderr, "Failure Sending Message\n");
                            close(client_fd);
                            break;
                        }
                        
                        printf("Server:Msg being sent: %s\nNumber of bytes sent: %d\n",buffer, (int)strlen(buffer));
                        
                    }
                    
                }
                
                close(client_fd);
            }
            
            close(socket_fd);
            return ;
            
        }
*/
};

#endif /* Haberlesme_h */