/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kiriazis
 *
 * Created on September 28, 2018, 10:08 PM
 */

#include <cstdlib>
#include "ConnectionManager.h"
#include "Logger.h"
#include <thread>
using namespace std;

int main(int argc, char** argv) {

    
    ConnectionManager connMan;
    Logger::initLogger();
    Logger::addLog("~~~~~ STARTING SERVER ~~~~~");
    

	
    return 0;
}
