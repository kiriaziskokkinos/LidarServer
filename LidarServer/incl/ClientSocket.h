/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClientSocket.h
 * Author: kiriazis
 * edit: Ilias
 *
 * Created on October 17, 2018, 12:30 AM
 */
 
#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H
#include <string>
#include "Socket.h"


class ClientSocket : public Socket{
public:
    ClientSocket(int fd);
    ClientSocket(const ClientSocket& orig);
    virtual ~ClientSocket();
    void sendData(std::string data);
    std::string receiveData();
private:
    
};

#endif /* CLIENTSOCKET_H */

