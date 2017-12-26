//
//  Character.hpp
//  cppfinalproject
//
//  Created by Lucas Tan on 12/10/17.
//  Copyright © 2017 Lucas Tan. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "Object.hpp"

using namespace std;

class Character {
private:
    vector<Object*> bag;
    int numOfLife;
    int currentRoom;
    bool hasTorch;
public:
    Character();
    Character(vector<Object*> b, int life, int room);
    
    vector<Object*> getBag();
    int getNumOfLife();
    int getCurrentRoom();
    
    void setBag(vector<Object*> b);
    void setNumOfLife(int life);
    void setCurrentRoom(int room);
    
    void addBag(Object* o);
    void removeBag(Object* o);
    
    bool getHasTorch();
    void setHasTorch();
    
    bool compare(Object& o);
    
    void printBag();
    void print();
    
    ~Character();
};

#endif /* Character_hpp */
