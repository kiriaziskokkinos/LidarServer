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
    
 this->descriptor = 0;   
}
Connection::Connection(int fd) {
	this->descriptor = fd;
}

Connection::Connection(const Connection& orig) {
}

Connection::~Connection() {
}






