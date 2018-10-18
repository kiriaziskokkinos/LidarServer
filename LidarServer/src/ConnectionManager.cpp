/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConnectionManager.cpp
 * Author: kiriazis
 * 
 * Created on September 30, 2018, 6:46 PM
 */

#include "ConnectionManager.h"
#include "ServerSocket.h"

ConnectionManager::ConnectionManager(){
    
}

ConnectionManager::~ConnectionManager(){
    this->acceptor.join();
}

void ConnectionManager::acceptLoop(){
    while (true) {
        int fd = connection.acceptt();
        connection_list.push_back(std::make_unique<Connection>(fd));
        
    }
}

void ConnectionManager::acceptConnections(){
    this->acceptor = std::thread(&ConnectionManager::acceptLoop,this);
}