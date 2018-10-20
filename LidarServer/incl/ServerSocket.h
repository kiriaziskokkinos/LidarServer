/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServerSocket.h
 * Author: kiriazis
 *
 * Created on October 16, 2018, 11:00 PM
 */


#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H
#include "Socket.h"

class ServerSocket : public Socket{
public:
    ServerSocket();
    ServerSocket(int descriptor, Type t);
    ServerSocket(const ServerSocket& orig);
    virtual ~ServerSocket();
    void receiveData();
    void sendData(std::string data);
    void ipInfo();
    int acceptsock();
private:
    void bindsock();
    void listensock();
    

};

#endif /* SERVERSOCKET_H */

