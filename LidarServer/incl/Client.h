/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Client.h
 * Author: kiriazis
 *
 * Created on October 5, 2018, 9:32 PM
 */

#ifndef CLIENT_H
#define CLIENT_H
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <stdio.h>
#include <thread>
#include "Connection.h"

class Client {
public:
    Client();
    Client(int descriptor_tcp);
    Client(const Client& orig);
    virtual ~Client();
    void ConnectionLoop();
private:
    Connection tcp;
    Connection udp;
    struct sockaddr_in sock_udp;
    int socket_descriptor;
    std::thread acceptor;
    int file_descriptor_tcp;
    int file_descriptor_udp;
    int PORT = 5555;
};

#endif /* CLIENT_H */

