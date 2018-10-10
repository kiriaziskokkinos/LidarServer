/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UdpConnection.h
 * Author: kiriazis
 *
 * Created on October 5, 2018, 10:41 PM
 */

#ifndef UDPCONNECTION_H
#define UDPCONNECTION_H
#include "Connection.h"

class UdpConnection : public Connection{
public:
    UdpConnection();
    UdpConnection(const UdpConnection& orig);
    virtual ~UdpConnection();
    int udpAccept();
private:
    int socket_descriptor;
    struct sockaddr_in socket_struct;
    int PORT = 22222;
    int fd;
};

#endif /* UDPCONNECTION_H */

