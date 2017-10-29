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
#include <string.h>

#include "Bellek.hpp"

using namespace std;
class Haberlesme{
private:
    Bellek * bellek;
    //configuration
    int PORT;
    int BACKLOG;
public:
    
    //constructor
    Haberlesme(){
        PORT =3490;
        BACKLOG=10;
        //bellek = new Bellek(treeDepth);
    }
    
    //starts the communication
    void haberles();
    
    //act on commands sent from client
    int actToCommands(char * args);
    
    
    
    void testNefunctional();
};

#endif /* Haberlesme_h */
