/**
 * File: Socket.h
 * Author Thanasis
 * 
 * */

#ifndef SOCKET_H
#define SOCKET_H

#include <queue>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <stdio.h>
#include "Logger.h"
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <memory>
#include <stdio.h>
#include <errno.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <signal.h>
#include <time.h>
#include <ctime>
//#include "SimpleMessage.h"
//#include "LidarMessage.h"


/**
 * enum Type for distinguishing UDP and TCP socket types.
 * */
enum Type{ TCP=0, UDP=1};

/**
 * Pure abstract class implementing a socket.
 * 
 */
class Socket {
    protected:
        //additional data (IP,PORT) must be added here
        //sockaddr int that Connection Manager uses must be saved here aswell
        int socket_descriptor;
        Type socket_type;
        struct sockaddr_in socket_struct;
        int PORT = 0; // GET PORT FROM SYSTEM
        
    public:
        Socket();
        Socket(int descriptor, Type t);
        Socket(Type t);
        Socket(Socket& o);
        virtual ~Socket();
        void closed();
        
};

#endif