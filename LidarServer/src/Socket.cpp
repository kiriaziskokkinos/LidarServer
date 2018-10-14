#include "Socket.h"


Socket::Socket(int descriptor, Type t){
    this->socket_descriptor= descriptor;
    this->socket_type= t;
}

Socket::Socket(Socket& o){
    this->socket_descriptor=o.socket_descriptor;
    this->socket_type=o.socket_type;
}

Socket::~Socket(){
    close(this->socket_descriptor);
    Logger::addLog("Socket closed"); //addition code must be inserted here in order to log ip and port of client
}