/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LidarConnection.h
 * Author: kiriazis
 *
 * Created on September 30, 2018, 6:47 PM
 */


#ifndef LIDARCONNECTION_H
#define LIDARCONNECTION_H
#include "Connection.h"
class LidarConnection : public Connection {
public:
    LidarConnection();
    LidarConnection(const LidarConnection& orig);
    virtual ~LidarConnection();
private:

};

#endif /* LIDARCONNECTION_H */

