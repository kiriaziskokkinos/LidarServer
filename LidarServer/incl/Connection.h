/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Connection.h
 * Author: kiriazis
 *
 * Created on September 30, 2018, 6:45 PM
 */

#ifndef CONNECTION_H
#define CONNECTION_H
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <stdio.h>
#include <thread>
#include <vector>
#include "Logger.h"
#include "SimpleMessage.h"


class Connection {
    
public:
    Connection();
    Connection(int fd);
    Connection(const Connection& orig);
    virtual ~Connection();
    void singleConnectionThread();
    void sendMessage(std::string s);
    char* receiveMessage(int count);
private:
    std::thread runner;
    std::vector <Message> MessageList;
protected:
    int descriptor;
};

#endif /* CONNECTION_H */

