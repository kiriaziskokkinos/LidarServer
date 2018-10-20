/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UIConnection.h
 * Author: kiriazis
 *
 * Created on September 30, 2018, 6:47 PM
 */


#ifndef UICONNECTION_H
#define UICONNECTION_H
#include "Connection.h"
class UIConnection : public Connection {
public:
    UIConnection();
    UIConnection(const UIConnection& orig);
    virtual ~UIConnection();
private:

};

#endif /* UICONNECTION_H */

