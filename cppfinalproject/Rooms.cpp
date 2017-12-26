
//
//  Room.cpp
//  cppfinalproject
//
//  Created by Lucas Tan on 12/10/17.
//  Copyright © 2017 Lucas Tan. All rights reserved.
//

//#include "stdafx.h"
#include "Rooms.hpp"


Rooms::Rooms() {
    
}

Rooms::Rooms(int id, string desc, vector<int> dir, bool lock, string key, bool ghost, vector<Object*> hasO) {
    room_id = id;
    description = desc;
    direction = dir;
    isLocked = lock;
    keyName = key;
    hasGhost = ghost;
    hasObject = hasO;
}

int Rooms::getRoom_id() {
    return room_id;
}

string Rooms::getDescription() {
    return description;
}

vector<int> Rooms::getDirection() {
    return direction;
}

bool Rooms::getIsLocked() {
    return isLocked;
}

string Rooms::getKeyName() {
    return keyName;
}

bool Rooms::getHasGhost() {
    return hasGhost;
}

vector<Object*> Rooms::getHasObject() {
    return hasObject;
}

void Rooms::setRoom_id(int id) {
    room_id = id;
}

void Rooms::setDescription(string desc) {
    description = desc;
}

void Rooms::setDirection(vector<int> dir) {
    direction = dir;
}

void Rooms::setIsLocked(bool lock) {
    isLocked = lock;
}

void Rooms::setKeyName(string key) {
    keyName = key;
}

void Rooms::setHasGhost(bool ghost) {
    hasGhost = ghost;
}

void Rooms::setHasObject(vector<Object*> hasO) {
    hasObject = hasO;
}

int Rooms::getNorth() {
    return direction[0];
}

int Rooms::getSouth() {
    return direction[1];
}

int Rooms::getEast() {
    return direction[2];
}

int Rooms::getWest() {
    return direction[3];
}

int Rooms::getUp() {
    return direction[4];
}

int Rooms::getDown() {
    return direction[5];
}

void Rooms::addObject(Object* o) {
    hasObject.push_back(o);
}

void Rooms::removeObject(Object* o) {
    vector<Object*>::iterator iter = find_if(hasObject.begin(), hasObject.end(), [o](const Object * o1) {return o1->getName() == o->getName(); });
    
    if (iter != hasObject.end()) {
        hasObject.erase(iter);
    }
}

ostream& operator<<(ostream& out, Rooms& r) {
    out << r.room_id << "\\" << r.description << "\\" << r.isLocked << "\\" << r.keyName << "\\" << r.hasGhost;
    return out;
}

istream& operator>>(istream& in, Rooms& r) {
    return in;
}

void Rooms::printObject() {
    string object_str;
    
    if (hasObject.size() != 0) {
        for (int i = 0; i < hasObject.size()-1 ; i++) {
            object_str = object_str + hasObject[i]->getName() + ", ";
        }
        object_str = object_str + hasObject[hasObject.size() - 1]->getName();
        
        cout << object_str << endl;
    }
}

void Rooms::print() {
    
}

Rooms::~Rooms() {
    
}
