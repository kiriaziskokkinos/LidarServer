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
#include <string.h>

Logger::Logger() {
    std::string filepath ("Log.txt");
    file.open(filepath,  std::fstream::in | std::fstream::out | std::fstream::app);
    if (!file.is_open())
    {
        std::perror("File opening failed");
    }   
    result = std::time(nullptr);
    
    
}

Logger::Logger(std::string fp) {
    std::string filepath (fp);
    file.open(filepath, std::fstream::in | std::fstream::out | std::fstream::app);
    if (!file.is_open())
    {
        std::perror("File opening failed");
    }
    result = std::time(nullptr);
}


Logger::Logger(const Logger& orig) {
}

Logger::~Logger() {
    this->file.close();
}

void Logger::addLog(std::string log){
    this->result = time(NULL);
    char* now;
    char later[19];
    now = ctime(&result);
    strncpy( later, now, strlen(now) - 1 );
    file << later << " : " << log << std::endl;
    file.flush();
}
