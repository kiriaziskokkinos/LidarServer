
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
		socket_descriptor = socket(AF_INET,SOCK_DGRAM, 0);
		if (socket_descriptor == -1) { 
			std::cout<<"Error with socket "<<socket_descriptor;
		}
	}

}

Socket::Socket(Type t){
    
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
		socket_descriptor = socket(AF_INET,SOCK_DGRAM, 0);
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



