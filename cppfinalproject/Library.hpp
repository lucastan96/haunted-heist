//
//  Library.hpp
//  cppfinalproject
//
//  Created by Lucas Tan on 12/10/17.
//  Copyright © 2017 Lucas Tan. All rights reserved.
//

#ifndef Library_hpp
#define Library_hpp

#pragma once
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include "Object.hpp"
#include "Character.hpp"
#include "Rooms.hpp"
#include "Hidden.hpp"
using namespace std;

int stringToInt(string s);
bool stringToBool(string s);
vector<int> stringToVectorInt(string s);
vector<string> stringToVectorString(string s);

static inline string &trim(string &s);
int searchObject(vector<Object*> o, string n);
vector<Rooms> importRooms(vector<Rooms> &r, vector<Object*> o);
vector<Object*> importObject(vector<Object*> o);

void intro(vector<Rooms> &r, Character &c);
void help();
void start();
void go(Character &c, vector<Rooms> &r, string action);
void look(vector<Rooms> &r, int room_id);
void open(Character &c, string action,vector<Object*> objects, vector<Rooms> &r);
void check(Character &c, string action, vector<Object*> objects, vector<Rooms> &r);
void take(Character &c, vector<Rooms> &r, string action);
void use(Character &c, string action, vector<Object*> objects, vector<Rooms> &r);
void ghost(Character &c, vector<Rooms> &r);
void ghostHelp();
void life(Character &c);
void map(Character &c);

void searchify(string &s);

#endif /* Library_hpp */
