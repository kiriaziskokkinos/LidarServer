/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Logger.h
 * Author: kiriazis
 *
 * Created on September 30, 2018, 6:46 PM
 */

#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <ctime>    
#include <iostream>
#include <fstream>
namespace t 
{
    using namespace std;
    class Logger {
    public:
        Logger();
        Logger(string fp);
        Logger(const Logger& orig);
        virtual ~Logger();
        void addLog(std::string log);

    private:
        std::time_t result;
        std::string filePath;
        std::fstream file;
    };
}
#endif /* LOGGER_H */

