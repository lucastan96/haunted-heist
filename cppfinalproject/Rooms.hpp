//
//  Room.hpp
//  cppfinalproject
//
//  Created by Lucas Tan on 12/10/17.
//  Copyright © 2017 Lucas Tan. All rights reserved.
//

#ifndef Room_hpp
#define Room_hpp

#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include "Object.hpp"

using namespace std;

class Rooms {
private:
    int room_id;
    string description;
    vector<int> direction;
    bool isLocked;
    string keyName;
    bool hasGhost;
    vector<Object*> hasObject;
public:
    Rooms();
    Rooms(int id, string desc, vector<int> dir, bool lock, string key, bool ghost, vector<Object*> hasO);
    
    int getRoom_id();
    string getDescription();
    vector<int> getDirection();
    bool getIsLocked();
    string getKeyName();
    bool getHasGhost();
    vector<Object*> getHasObject();
    
    void setRoom_id(int id);
    void setDescription(string desc);
    void setDirection(vector<int> dir);
    void setIsLocked(bool lock);
    void setKeyName(string key);
    void setHasGhost(bool ghost);
    void setHasObject(vector<Object*> hasO);
    
    void addObject(Object* o);
    void removeObject(Object* o);
    
    int getNorth();
    int getSouth();
    int getEast();
    int getWest();
    int getUp();
    int getDown();
    
    friend ostream& operator<<(ostream& out, Rooms& r);
    friend istream& operator>>(istream& in, Rooms& r);
    
    void printObject();
    void print();
    
    ~Rooms();
};

#endif /* Room_hpp */
