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
#include <exception>
/*
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
*/

//static member of class Logger
// ~~~
std::mutex Logger::filelock;
std::fstream Logger::file;
std::string Logger::file_path ="";
std::time_t Logger::result;
// ~~~


    void Logger::initLogger()
    {
        if (Logger::file_path != "")
        {
            Logger::file_path="Log.txt";
            Logger::file.open(file_path,  std::fstream::in | std::fstream::out | std::fstream::app);
            if (!Logger::file.is_open())
            {
                std::perror("File opening failed");
            }   
            Logger::result = std::time(nullptr);    
        }
        else
        {
            return;
        }
    }

    void Logger::initLogger(std::string& filename)
    {
        if (Logger::file_path != "")
        {
            Logger::file_path=filename;
            Logger::file.open(file_path,  std::fstream::in | std::fstream::out | std::fstream::app);
            if (!Logger::file.is_open())
            {
                std::perror("File opening failed");
            }   
            Logger::result = std::time(nullptr);    
        }
        else
        {
            return;
        }
    }

void Logger::addLog(std::string log){
    Logger::filelock.lock();
        Logger::result = time(NULL);
        char* now;
        char later[19];
        now = ctime(&result);
        strncpy( later, now, strlen(now) - 1 );
        Logger::file << later << " : " << log << std::endl;
        Logger::file.flush();
    Logger::filelock.unlock();
}
