/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimpleMessage.h
 * Author: kiriazis
 *
 * Created on September 30, 2018, 6:47 PM
 */

#ifndef SIMPLEMESSAGE_H
#define SIMPLEMESSAGE_H
#include "Message.h"
class SimpleMessage : public Message {
public:
    SimpleMessage();
    SimpleMessage(const SimpleMessage& orig);
    virtual ~SimpleMessage();
private:

};

#endif /* SIMPLEMESSAGE_H */

