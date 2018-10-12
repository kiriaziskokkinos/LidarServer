/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Client.cpp
 * Author: kiriazis
 * 
 * Created on October 5, 2018, 9:32 PM
 */

#include "Client.h"

Client::Client(int descriptor_tcp) {
	this->file_descriptor_tcp = descriptor_tcp;
	this->socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
	if (this->socket_descriptor == -1) { 
		std::cout<<"Error with socket "<<this->socket_descriptor;
	}
	this->sock_udp.sin_addr.s_addr = htons(INADDR_ANY);
	this->sock_udp.sin_family = AF_INET;
	this->sock_udp.sin_port = htons(PORT); 
	if ( bind(this->socket_descriptor,(struct sockaddr *) &this->sock_udp,sizeof(this->sock_udp)) == -1 )
		std::cout<<"Error at bind";
	if ( listen(this->socket_descriptor, 256) == -1 )
		std::cout<<"Error at listen";
	this->acceptor= std::thread{&Client::ConnectionLoop,this};
}

void Client::ConnectionLoop(){
	socklen_t a = sizeof(this->sock_udp);
	this->file_descriptor_udp = accept(socket_descriptor, (struct sockaddr *) &this->sock_udp,&a);
	if ( this->file_descriptor_udp == -1 ){
		std::cout<<"Error";
	}
	Connection c1(this->file_descriptor_udp);
	Connection c2(this->file_descriptor_tcp);
}

Client::Client(const Client& orig) {
}

Client::~Client() {
}

