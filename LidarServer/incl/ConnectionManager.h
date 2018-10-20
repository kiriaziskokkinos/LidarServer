/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConnectionManager.h
 * Author: kiriazis
 *
 * Created on September 30, 2018, 6:46 PM
 */


#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H
#include "Connection.h"
#include "ServerSocket.h"
#include "thread"
#include "Logger.h"

class ConnectionManager {
public:
    ConnectionManager();
    void acceptConnections();
    virtual ~ConnectionManager();
protected:
    std::vector<std::unique_ptr<Connection>> connection_list;
    std::thread acceptor;
    void acceptLoop(); 
    ServerSocket connection;
};

#endif /* CONNECTIONMANAGER_H */

