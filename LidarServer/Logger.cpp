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

t::Logger::Logger() {
    this->file.open("Log.txt");
    
}

t::Logger::Logger(const Logger& orig) {
}

t::Logger::~Logger() {
    this->file.close();
}

void t::Logger::addLog(std::string log){
    file << log;
    
}
