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
    this->descriptor= fd;
    
    this->runner = std::thread(&Connection::StartConnection,this);
}

Connection::Connection(const Connection& orig) {
}

Connection::~Connection() {
    this->runner.join();
	
}

void Connection::StartConnection(){
    this->receiveData();
    while(true){
        switch(2) {
            case 1 : {

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

std::string Connection::receiveData(){
	char* messagebuffer;
        // Maybe change it to two part reading a)message size 2)message data
	int j = read(this->descriptor, messagebuffer,1000);
	if(j == -1){
		Logger::addLog("Error while receiving Message");
		std::cout<<"Error receiving\n";
		close(this->descriptor);
	}
	std::cout<<"Client send: "<<messagebuffer<<std::endl;
	
	return messagebuffer;
	
}


/*
 * Send message to client and check if there is a problem
 *
 */
void Connection::sendData(std::string data){
	int i = write(this->descriptor,&data,sizeof(data));
	if(i == -1){
		std::cout<<"Error sending\n";
		Logger::addLog("Error while sending message");
                // remove before flight
		close(this->descriptor);
	}
}



