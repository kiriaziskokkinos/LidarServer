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
#include "ClientSocket.h"

class Connection {
    
public:
    Connection();
    Connection(int fd);
    ~Connection();
    std::thread runner;
protected:
    
    std::queue <Message> MessageList;
    std::unique_ptr<ClientSocket> socket;
    void startIO();

};

#endif /* CONNECTION_H */

