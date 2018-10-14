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
#include "UdpConnection.h"

/*
Connection::Connection() {
    
 this->descriptor = 0;   
}
*/
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
	std::string ans = this->receiveMessage(2);
	int asn_int = std::stoi(ans,nullptr,10);

    int udpFileDescriptor;
	while(true){
		switch(asn_int) {
			case 1 : {
                UdpConnection udpConn;
                udpFileDescriptor = udpConn.udpAccept();
            }
			case 2 : {
				std::cout << '2';
			}
			case 3 : {
				break;
			}
			case 0 : {
				break;
			}
			default : {
				sleep(400);
			}
		}
	
	}
	close(this->descriptor);
	
}
/*
 * Send message to client and check if there is a problem
 *
 */
void Connection::sendMessage(std::string s){
	int i = write(this->descriptor,&s,sizeof(s));
	if(i == -1){
		std::cout<<"Error sending\n";
		Logger::addLog("Error while sending message");
		close(this->descriptor);
	}
	
}

char* Connection::receiveMessage(int count){
	char* messagebuffer;
	int j = read(this->descriptor, messagebuffer, count );
	if(j == -1){
		Logger::addLog("Error while receiving Message");
		std::cout<<"Error receiving\n";
		close(this->descriptor);
	}
	std::cout<<"Client send: "<<messagebuffer<<std::endl;
	SimpleMessage tempmsg(messagebuffer);
	this->MessageList.push_back(tempmsg);
	return messagebuffer;
}




