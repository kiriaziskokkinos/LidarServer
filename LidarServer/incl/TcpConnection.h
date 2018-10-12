/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TcpConnection.h
 * Author: kiriazis
 *
 * Created on October 5, 2018, 10:43 PM
 */

#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H
#include "Connection.h"
class TcpConnection : Connection{
public:
    TcpConnection();
    TcpConnection(const TcpConnection& orig);
    virtual ~TcpConnection();
private:

};

#endif /* TCPCONNECTION_H */

