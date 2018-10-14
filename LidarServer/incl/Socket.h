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
//#include "SimpleMessage.h"
//#include "LidarMessage.h"


/**
 * enum Type for distinguishing UDP and TCP socket.
 * */
enum Type { TCP=0, UDP=1};

/**
 * Pure abstract class implementing a socket.
 * 
 */
class Socket {
    protected:
        int socket_descriptor;
        Type socket_type;
        virtual void sendData(std::string data) =0;
        virtual void receiveData() =0;
    public:
        Socket(int descriptor);
};

#endif