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

#include <vector>
#include <memory>
#include <thread>

//#include <string.h>
#include "Client.h"
#include "Logger.h"

class ConnectionManager {
public:
    ConnectionManager();
    ConnectionManager(const ConnectionManager& orig);
    virtual ~ConnectionManager();
    /**
     * Returns the file descriptor of the new connection
     * If no file descriptor is creted the returns -1
     * @return file descriptor or -1 if fails
     */
    int acceptConnection();
    void acceptConnectionsLoop();
private:
    std::vector<std::unique_ptr<Connection> > connection_list;
    struct sockaddr_in sock;
    int socket_descriptor;
    std::thread acceptor;
    int PORT = 5555;
    void ipInfo();
};

#endif /* CONNECTIONMANAGER_H */

