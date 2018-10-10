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
#include <memory>
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
using namespace std;
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
    /*  
     *  Here we initialize the tcp socket struct as we need it for the initial communitation with the clients. 
     */
    	socket_struct.sin_addr.s_addr = htons(INADDR_ANY);
	socket_struct.sin_family = AF_INET;
	socket_struct.sin_port = htons(PORT);
        
    /*
     *  We then create our socket descriptor which we will need to manage the socket. 
     */    
        
	socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_descriptor == -1) { 
		std::cout<<"Error with socket "<<socket_descriptor;
	}

    /* 
     *  What remains is to bind our socket and put it in a listening state.   
     */
	if ( bind(socket_descriptor,(struct sockaddr *) &socket_struct,sizeof(socket_struct)) == -1 )
		std::cout<<"Error at bind";
        
	if ( listen(socket_descriptor, 250) == -1 )
		std::cout<<"Error at listen";
    /*  
     *  Our acceptor thread will be the one that will start accepting new connections.
     *  We accept the connections on a separate thread since accept() will be called in blocking mode.
     */
	acceptor= std::thread{&ConnectionManager::acceptConnectionsLoop,this};			
}





ConnectionManager::ConnectionManager(const ConnectionManager& orig) 
{
	
}

ConnectionManager::~ConnectionManager()
{
    this->acceptor.join();
}

/*
 * @Success returns the file descriptor of a new connection.
 * @Fail returns -1.
 */
int ConnectionManager::acceptConnection(){
    
    
    int connection_descriptor;
    socklen_t peer_size=sizeof(struct sockaddr_in);
    connection_descriptor = accept(socket_descriptor, (struct sockaddr *) &socket_struct,&peer_size);  
    return connection_descriptor;
}


/*
 * This function is run infinitely so as to always accept new connections.
 * 
 */
void ConnectionManager::acceptConnectionsLoop() {
    int fd ;
    while (true){
        fd = acceptConnection();
        if ( fd == -1 ){
            cout<<"An error occured while trying to accept a new connection."<<endl;  
            continue;
        }
        else {
            cout<<"Accepted new connection."<<endl;
            connection_list.emplace_back(make_unique<Connection>(fd));
            //cout<<"Accepted new connection."<<endl;
        }
    }
}

