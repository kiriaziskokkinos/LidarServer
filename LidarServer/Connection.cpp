/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Connection.cpp
 * Author: kiriazis
 * 
 * Created on September 30, 2018, 6:45 PM
 */

#include "Connection.h"

Connection::Connection() {
    
 this->descriptor = 0;   
}
Connection::Connection(int fd) {
	this->descriptor = fd;
	this->runner = std::thread{&Connection::singleConnectionThread,this};

}

Connection::Connection(const Connection& orig) {
}

Connection::~Connection() {
	this->runner.join();
}

void Connection::singleConnectionThread(){
	this->receiveMessage(1000);
	while(true){
		switch(5) {
			case 1 : std::cout << '1';
			case 2 : std::cout << '2';
		}
	
	}
	
	
}
/*
 * Send message to client and check if there is a problem
 *
 */
void Connection::sendMessage(std::string s){
	int i = write(this->descriptor,&s,sizeof(s));
	if(i == -1){
		std::cout<<"Error sending\n";
		close(this->descriptor);
	}
}

void Connection::receiveMessage(int count){
	char* messagebuffer;
	int j = read(this->descriptor, messagebuffer, count );
	if(j == -1){
		std::cout<<"Error receiving\n";
		close(this->descriptor);
	}
	std::cout<<"Client send: "<<messagebuffer<<std::endl;
	SimpleMessage tempmsg(messagebuffer);
	this->MessageList.push_back(tempmsg);
	
	
}




