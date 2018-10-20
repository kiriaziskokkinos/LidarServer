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
#include <mutex>
#include <cstring>
#include <memory>

/*
 * This class implements the Singleton Design Pattern.
 * Logger is resonsible for loggin important. Every class should include this header and use static method of Class Logger

 */    
    class Logger { 
    public:
        static void addLog(std::string log);
        /*
         * initLogger should be called once. In case of a second call the method will just return 
         */
        static void initLogger();
        static void initLogger(std::string& filename);
    private:
        Logger(){}; //must be left empty
        //Logger(string fp){};
        Logger(const Logger& orig){}; //must be left empty
        ~Logger() {}; //must be left empty
        static std::time_t result;
        static std::string file_path;
        static std::fstream file;
        static std::mutex filelock;
    };
#endif /* LOGGER_H */

