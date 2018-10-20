/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClientSocket.cpp
 * Author: kiriazis
 * edit: Ilias
 * 
 * Created on October 17, 2018, 12:30 AM
 */

#include "ClientSocket.h"

ClientSocket::ClientSocket(int fd) {
	this->socket_descriptor = fd;
}

ClientSocket::ClientSocket(const ClientSocket& orig) {
    
}
ClientSocket::ClientSocket() {
    //Closes the current client socket

    
}
ClientSocket::~ClientSocket() {
    //Closes the current client socket
    this->~Socket();
    
}

std::string ClientSocket::receiveData(){
	char* messagebuffer = new char[1000];
        std::string result;
        // Maybe change it to two part reading a)message size 2)message data
	int j = read(this->socket_descriptor, messagebuffer,1000);
	if(j == -1){
		Logger::addLog("Error while receiving Message");
		std::cout<<"Error receiving\n";
		//close(this->socket_descriptor);
	}
	std::cout<<"Client send: "<<messagebuffer<<std::endl;
	result = messagebuffer;
        delete messagebuffer;
	return result;
	
}

void ClientSocket::sendData(std::string data){
    /*
	int i = write(this->socket_descriptor,&data,sizeof(data));
	if(i == -1){
		std::cout<<"Error sending\n";
		Logger::addLog("Error while sending message");
                // remove before flight
		close(this->socket_descriptor);
	}
    */
}

