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
    int fd;
    while (true) {
        fd = connection.acceptsock();
        std::cout<< "New client connected" <<std::endl;
        auto r = new Connection(fd);
        connection_list.push_back(r);
    }
}

void ConnectionManager::start(){
    this->acceptor = std::thread(&ConnectionManager::acceptLoop,this);
}