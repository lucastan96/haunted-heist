//
//  Object.cpp
//  cppfinalproject
//
//  Created by Lucas Tan on 12/10/17.
//  Copyright © 2017 Lucas Tan. All rights reserved.
//

//#include "stdafx.h"
#include "Object.hpp"

Object::Object() {
    
}

Object::Object(string n, string desc) {
    name = n;
    description = desc;
}

string Object::getName() const{
    return name;
}

string Object::getDescription() {
    return description;
}

void Object::setName(string n) {
    name = n;
}

void Object::setDescription(string desc) {
    description = desc;
}

ostream& operator<<(ostream& out, Object& o) {

    return out;
}

istream& operator>>(istream& in, Object& o) {
    return in;
}

void Object::print() {
    
}

Object::~Object() {
    
}
