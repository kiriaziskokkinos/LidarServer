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
#include "../Eigen/Core"
using namespace std;

int main(int argc, char** argv) {

    //testing Eigen included library
    Eigen::MatrixXd m(2,2);

    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;
    //end of test

    ConnectionManager connMan;
    Logger::initLogger();
    Logger::addLog("~~~~~ STARTING SERVER ~~~~~");
    connMan.start();

	
    return 0;
}
