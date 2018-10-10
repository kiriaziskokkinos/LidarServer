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
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <signal.h>
#include <time.h>
#include <ctime>

void ConnectionManager::ipInfo()
{
	struct ifaddrs *ifaddr, *ifa;
	int family, s, n;
	char host[NI_MAXHOST];
	if (getifaddrs(&ifaddr) == -1) {
		perror("getifaddrs");
		exit(EXIT_FAILURE);
	}

	/* Walk through linked list, maintaining head pointer so we
	can free list later */

	printf("\nConnect to one of these addresses:\n\n");

	for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
		if (ifa->ifa_addr == NULL)
			continue;
		family = ifa->ifa_addr->sa_family;
		/* Display interface name and family (including symbolic
		form of the latter for the common families) */
		if (family == AF_INET && ( (strcmp(ifa->ifa_name,"lo") != 0) || (strcmp(ifa->ifa_name,"lo0vboxnet0") != 0) ))
			printf("\t%s", ifa->ifa_name);

			/* For an AF_INET* interface address, display the address */
		if (family == AF_INET) {
			s = getnameinfo(ifa->ifa_addr,(family == AF_INET) ? sizeof(struct sockaddr_in) :
					sizeof(struct sockaddr_in6), host, NI_MAXHOST,NULL, 0, NI_NUMERICHOST);
			if (s != 0) {
				printf("getnameinfo() failed: %s\n", gai_strerror(s));
				exit(EXIT_FAILURE);
			}
			printf(" address: %s:%d\n", host,PORT);
		}
	}
	freeifaddrs(ifaddr);
}


ConnectionManager::ConnectionManager() 
{
	this->socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
	if (this->socket_descriptor == -1) { 
		std::cout<<"Error with socket "<<this->socket_descriptor;
	}
	this->sock.sin_addr.s_addr = htons(INADDR_ANY);
	this->sock.sin_family = AF_INET;
	this->sock.sin_port = htons(PORT); 
	if ( bind(this->socket_descriptor,(struct sockaddr *) &this->sock,sizeof(this->sock)) == -1 )
		std::cout<<"Error at bind";
	if ( listen(this->socket_descriptor, 256) == -1 )
		std::cout<<"Error at listen";
	this->ipInfo();
	this->acceptor= std::thread{&ConnectionManager::acceptConnectionsLoop,this};
			
}





ConnectionManager::ConnectionManager(const ConnectionManager& orig) 
{
	
}

ConnectionManager::~ConnectionManager()
{
    this->acceptor.join();
}


int ConnectionManager::acceptConnection(){
	int a;
	socklen_t peer_size=sizeof(struct sockaddr_in);
	if ((a = accept(socket_descriptor, (struct sockaddr *) &this->sock,&peer_size)) == -1 ) {
		std::cout<<"Error";
	}
	std::cout<<"Client Connected"<<std::endl;
	return a;
}

void ConnectionManager::acceptConnectionsLoop() {
	
	while (true){
		Connection tmp(this->acceptConnection());
	}
}

