/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClientSocket.cpp
 * Author: kiriazis
 * 
 * Created on October 17, 2018, 12:30 AM
 */

#include "ClientSocket.h"

ClientSocket::ClientSocket(int fd) {
	this->file_discriptor = fd;
}

ClientSocket::ClientSocket(const ClientSocket& orig) {
}

ClientSocket::~ClientSocket() {
}

std::string ClientSocket::receiveData(){
	char* messagebuffer;
	int j = read(this->file_discriptor, messagebuffer,1000);
	if(j == -1){
		Logger::addLog("Error while receiving Message");
		std::cout<<"Error receiving\n";
		close(this->file_discriptor);
	}
	std::cout<<"Client send: "<<messagebuffer<<std::endl;
	
	return messagebuffer;
	
}

void ClientSocket::sendData(std::string data){
	int i = write(this->file_discriptor,&data,sizeof(data));
	if(i == -1){
		std::cout<<"Error sending\n";
		Logger::addLog("Error while sending message");
		close(this->file_discriptor);
	}
}

