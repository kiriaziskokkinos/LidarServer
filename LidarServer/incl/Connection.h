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

#include <thread>

#include "SimpleMessage.h"
#include "Socket.h"

class Connection {
    
public:
    Connection(){};
    Connection(int fd);
    Connection(const Connection& orig);
    virtual ~Connection();
    void singleConnectionThread();
    void sendMessage(std::string s);
protected:
    std::thread runner;
    std::vector <Message> MessageList;
    int descriptor;
    void receiveMessage(int len);

};

#endif /* CONNECTION_H */

