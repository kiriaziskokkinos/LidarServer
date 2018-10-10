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
	std::thread{&Connection::singleConnectionThread,this};

}

Connection::Connection(const Connection& orig) {
}

Connection::~Connection() {
}

void Connection::singleConnectionThread(){
	this->receiveMessage(1000);
	
	
}

void Connection::sendMessage(std::string s){
	write(this->descriptor,&s,sizeof(s));
}

void Connection::receiveMessage(int count){
	char* messagebuffer;
	read(this->descriptor, messagebuffer, count );
	std::cout<<"Client send: "<<messagebuffer<<std::endl;
}






