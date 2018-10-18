
#include "Socket.h"

Socket::Socket(int descriptor, Type t){
    this->socket_descriptor= descriptor;
    this->socket_type= t;
	
	/*  
     *  Here we initialize the tcp socket struct as we need it for the initial communitation with the clients. 
     */
	socket_struct.sin_addr.s_addr = htons(INADDR_ANY);
	socket_struct.sin_family = AF_INET;
	socket_struct.sin_port = htons(PORT);
        
    /*
     *  We then create our socket descriptor which we will need to manage the socket. 
     */    
    
	if(this->socket_type == Type::TCP){
		socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
		if (socket_descriptor == -1) { 
			std::cout<<"Error with socket "<<socket_descriptor;
		}
	}
	else if(this->socket_type == Type::UDP){
		socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
		if (socket_descriptor == -1) { 
			std::cout<<"Error with socket "<<socket_descriptor;
		}
	}

}

Socket::Socket()
{
	
}

Socket::Socket(Socket& o){
    this->socket_descriptor=o.socket_descriptor;
    this->socket_type=o.socket_type;
}

Socket::~Socket(){
    close(this->socket_descriptor);
    Logger::addLog("Socket: closed"); //addition code must be inserted here in order to log ip and port of client
}


void Socket::closed(){
	close(this->socket_descriptor);
}



void Socket::ipInfo()
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