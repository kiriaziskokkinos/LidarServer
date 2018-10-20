/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServerSocket.cpp
 * Author: kiriazis
 * 
 * Created on October 16, 2018, 11:00 PM
 */

#include "ServerSocket.h"

ServerSocket::ServerSocket() : Socket(TCP) {

    this->bindsock();
    this->listensock();
    this->ipInfo();
}

ServerSocket::ServerSocket(const ServerSocket& orig) {
}


ServerSocket::ServerSocket(int descriptor, Type t) : Socket(descriptor,t) {
	
}

void ServerSocket::bindsock(){
	int test = bind(this->socket_descriptor,(struct sockaddr *) &this->socket_struct,sizeof(this->socket_struct));
	if ( test == -1 ){
		std::cout<<"Error at bind";
                exit(-1);
	}
}

void ServerSocket::listensock(){
	if ( listen(socket_descriptor, 250) == -1 ){
		std::cout<<"Error at listen";
	}

}

int ServerSocket::acceptsock(){
	int connection_descriptor;
    socklen_t peer_size=sizeof(struct sockaddr_in);
    connection_descriptor = accept(socket_descriptor, (struct sockaddr *) &socket_struct,&peer_size);  
    return connection_descriptor;
}

void ServerSocket::receiveData()
{
}

void ServerSocket::sendData(std::string data)
{
	
}

ServerSocket::~ServerSocket()
{

}

void ServerSocket::ipInfo()
{
    struct sockaddr_in sin;
    socklen_t len = sizeof(sin);
    if (getsockname(this->socket_descriptor, (struct sockaddr *)&sin, &len) == -1)
        perror("getsockname");
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
                        
                        
                        
                        
			printf(" address: %s:%d\n", host,ntohs(sin.sin_port));
		}
	}
	freeifaddrs(ifaddr);
}
