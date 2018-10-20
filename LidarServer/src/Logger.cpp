/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Logger.cpp
 * Author: kiriazis
 * 
 * Created on September 30, 2018, 6:46 PM
 */

#include "Logger.h"


std::mutex Logger::filelock;
std::fstream Logger::file;
std::string Logger::file_path ="";



void Logger::initLogger() {
    if (Logger::file_path == "") {
        Logger::file_path="Log.txt";
        Logger::file.open(file_path,  std::fstream::in | std::fstream::out | std::fstream::app);
        if (!Logger::file.is_open()) {
            std::perror("File opening failed");
        }   
    }
}

void Logger::initLogger(std::string& filename) {
    Logger::file_path = filename;
    Logger::file.open(file_path,  std::fstream::in | std::fstream::out | std::fstream::app);
    if (!Logger::file.is_open()) {
        std::perror("File opening failed");
    }   
}

void Logger::addLog(std::string log){
    Logger::filelock.lock();
    time_t result = time(0);
    char* now;

    now = ctime(&result);    
    now[strlen(now)-1] = '\0';     
#ifdef DEBUG
    std::cout<<"Debug Message: print time now {"<<now<<"}"
    <<std::endl;
#endif    
    Logger::file << now << " : " << log << std::endl;
    Logger::file.flush();
    Logger::filelock.unlock();
}
