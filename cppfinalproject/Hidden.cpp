//
//  Hidden.cpp
//  cppfinalproject
//
//  Created by Lucas Tan on 12/11/17.
//  Copyright © 2017 Lucas Tan. All rights reserved.
//

#include "Hidden.hpp"

Hidden::Hidden() : Object() {
    isChecked = false;
}

Hidden::Hidden(string n, string desc, bool check,string name) : Object(n, desc) {
    isChecked = check;
    keyName = name;
}

bool Hidden::getIsChecked() const {
    return isChecked;
}

string Hidden::getKeyName() const {
    return keyName;
}

void Hidden::setIsChecked(bool check) {
    isChecked = check;
}

void Hidden::setKeyName(string name) {
     keyName = name;
}

Hidden::~Hidden() {
    
}
