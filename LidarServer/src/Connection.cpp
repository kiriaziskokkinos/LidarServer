/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Connection.cpp
 * Author: kiriazis
 * 
 * Created on September 30, 2018, 6:45 PM
 */

#include "Connection.h"




Connection::Connection() {   
    
}

Connection::Connection(int fd) {
    this->socket = std::make_unique<ClientSocket>(fd);
    
    this->runner = std::thread(&Connection::startIO,this);
    
}

Connection::~Connection() {
    std::cout<<"Connection destructor called."<<std::endl;
    this->runner.join();
	
}

void Connection::startIO(){
    while(true){
        std::string retval = this->socket->receiveData();
        if (retval == "") {
            std::cout<<"receiveData() returned null. Did the socket close?"<<std::endl;
            return;
        } 
        
        //usleep(200);
    } 
}

/*
 * Send message to client and check if there is a problem
 *
 */

