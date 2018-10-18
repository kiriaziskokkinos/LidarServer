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

ConnectionManager::ConnectionManager() 
{
    this->connection.bindd();
            //object ok 
    
}

ConnectionManager::~ConnectionManager()
{
	
}

void ConnectionManager::acceptLoop(){
    while (true) {
        int fd=this->connection.acceptt();
        
        
        
       // this->connection_list.push_back(std::make_unique(new Connection(0)));
        
    }
}

void ConnectionManager::acceptConnections(){
    //this->acceptor = new std::thread();
}