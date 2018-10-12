/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UdpConnection.cpp
 * Author: kiriazis
 * 
 * Created on October 5, 2018, 10:41 PM
 */

#include "UdpConnection.h"

UdpConnection::UdpConnection() {
    
    /*  
     *  Here we initialize the udp socket struct as we need it for the initial communitation with the clients. 
     */
    socket_struct.sin_addr.s_addr = htons(INADDR_ANY);
	socket_struct.sin_family = AF_INET;
	socket_struct.sin_port = htons(PORT);
        
    /*
     *  We then create our socket descriptor which we will need to manage the socket. 
     */    
        
	socket_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
	if (socket_descriptor == -1) {
		std::cout<<"Error with socket "<<socket_descriptor;
		Logger::addLog("Error with socket at udp socket");
	}

    /* 
     *  What remains is to bind our socket and put it in a listening state.   
     */
	if ( bind(socket_descriptor,(struct sockaddr *) &socket_struct,sizeof(socket_struct)) == -1 ){
		std::cout<<"Error at bind";
		Logger::addLog("Error at bind at udp connection");
	}
        
	if ( listen(socket_descriptor, 250) == -1 ){
		std::cout<<"Error at listen";
		Logger::addLog("Error at listen at udp connection");
	}
        
        
         
	
}

UdpConnection::UdpConnection(const UdpConnection& orig) {
}

UdpConnection::~UdpConnection() {
}

int UdpConnection::udpAccept(){
    socklen_t peer_size=sizeof(struct sockaddr_in);
    this->fd = accept(socket_descriptor, (struct sockaddr *) &socket_struct,&peer_size); 
	if(this->fd == -1){
		std::cout<<"Error while accepting abort udp connection";
		Logger::addLog("Error while accepting abort udp connection");
	}
	
	
    return this->fd;
}

