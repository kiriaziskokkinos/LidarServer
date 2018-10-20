/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LidarMessage.h
 * Author: kiriazis
 *
 * Created on September 30, 2018, 6:47 PM
 */


#ifndef LIDARMESSAGE_H
#define LIDARMESSAGE_H
#include "Message.h"
class LidarMessage : public Message {
public:
    LidarMessage();
    LidarMessage(const LidarMessage& orig);
    virtual ~LidarMessage();
private:

};

#endif /* LIDARMESSAGE_H */

