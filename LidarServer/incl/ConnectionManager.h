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
private:
    std::vector<std::unique_ptr<Connection> > connection_list;
    std::thread acceptor;
};

#endif /* CONNECTIONMANAGER_H */

