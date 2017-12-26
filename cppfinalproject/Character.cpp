//
//  Character.cpp
//  cppfinalproject
//
//  Created by Lucas Tan on 12/10/17.
//  Copyright © 2017 Lucas Tan. All rights reserved.
//

//#include "stdafx.h"
#include "Character.hpp"

Character::Character() {
    bag = {};
    numOfLife = 3;
    currentRoom = 1;
    hasTorch = false;
}

Character::Character(vector<Object*> b, int life, int room) {
    bag = b;
    numOfLife = life;
    currentRoom = room;
    hasTorch = false;
}

vector<Object*> Character::getBag() {
    return bag;
}

int Character::getNumOfLife() {
    return numOfLife;
}

int Character::getCurrentRoom() {
    return currentRoom;
}

void Character::setBag(vector<Object*> b) {
    bag = b;
}

void Character::setNumOfLife(int life) {
    numOfLife = life;
}

void Character::setCurrentRoom(int room) {
    currentRoom = room;
}

void Character::addBag(Object* o) {
    bag.push_back(o);
}

//
//bool Character::compare(Object& o) {
//    return o.getName == name;
//}

void Character::removeBag(Object* o) {
    vector<Object*>::iterator iter = find_if(bag.begin(), bag.end(), [o](const Object * o1) {return o1->getName() == o->getName();});
    
    if (iter != bag.end()) {
        bag.erase(iter);
    }
}

bool Character::getHasTorch() {
    return hasTorch;
}

void Character::setHasTorch() {
    hasTorch = true;
}

void Character::printBag() {
    string bag_str;
    int battery_count = 0;
    
    if (bag.size() != 0) {
        for (int i = 0; i < bag.size(); i++) {
            if (bag[i]->getName() == "battery") {
                battery_count = battery_count + 1;
            } else {
                bag_str = bag_str + bag[i]->getName() + ", ";
            }
        }
        
        cout << bag_str << "battery x" << battery_count << endl;
    } else {
        cout << "- (take items in your area using 'take ??')" << endl;
    }
}

void Character::print() {
    
}

Character::~Character() {
    
}
