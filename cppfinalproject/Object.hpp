//
//  Object.hpp
//  cppfinalproject
//
//  Created by Lucas Tan on 12/10/17.
//  Copyright © 2017 Lucas Tan. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Object {
private:
    string name;
    string description;
public:
    Object();
    Object(string n, string desc);
    
    string getName() const;
    string getDescription();
    
    void setName(string n);
    void setDescription(string desc);
    
    friend ostream& operator<<(ostream& out, Object& o);
    friend istream& operator>>(istream& in, Object& o);
    
    void print();
    ~Object();
};

#endif /* Object_hpp */
