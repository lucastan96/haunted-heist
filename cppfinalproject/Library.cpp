//
//  Library.cpp
//  cppfinalproject
//
//  Created by Lucas Tan on 12/10/17.
//  Copyright © 2017 Lucas Tan. All rights reserved.
//

//#include "stdafx.h"
#include "Library.hpp"

int stringToInt(string s) {
    int i = atoi(s.c_str());
    return i;
}

bool stringToBool(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    istringstream is(s);
    bool b;
    is >> boolalpha >> b;
    
    return b;
}

vector<int> stringToVectorInt(string s) {
    stringstream stream(s);
    vector<int> v;
    int n;
    
    while(stream >> n) {
        v.push_back(n);
    }
    
    return v;
}

vector<string> stringToVectorString(string s) {
    istringstream ss(s);
    string token;
    vector<string> v;
    
    while(getline(ss, token, ',')) {
        v.push_back(token);
    }
    
    return v;
}

static inline string &trim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

int searchObject(vector<Object*> o, string n) {
    int ans = -1;
    for (int i = 0; i <  o.size(); i++) {
        string name = o[i]->getName();
        name = trim(name);
        
        if (name == n) {
            ans = i;
        }
    }
    
    return ans;
}

vector<Rooms> importRooms(vector<Rooms> &r, vector<Object*> o) {
    ifstream fis;
    fis.open("/Users/lucastan96/Documents/Computing/Computing Level 8 Year 3/C++/Projects/cppfinalproject/cppfinalproject/Room.txt");
    
    if (fis) {
        while (!fis.eof()) {
            Rooms b;
            string room_id, description, direction, isLocked, keyName, hasGhost, hasObject;
            getline(fis, room_id);
            b.setRoom_id(stringToInt(room_id));
            getline(fis, description);
            b.setDescription(description);
            getline(fis, direction);
            b.setDirection(stringToVectorInt(direction));
            getline(fis, isLocked);
            b.setIsLocked(stringToBool(isLocked));
            getline(fis, keyName);
            b.setKeyName(keyName);
            getline(fis, hasGhost);
            b.setHasGhost(stringToBool(hasGhost));
            getline(fis, hasObject);
            
            vector<string> objects_name = stringToVectorString(hasObject);
            vector<Object*> objects;
            for (int i = 0; i < objects_name.size(); i++) {
                int position = searchObject(o, objects_name[i]);
                objects.push_back(o[position]);
            }
            b.setHasObject(objects);
            r.push_back(b);
        }
    } else {
        cout << "Error Opening file" << endl;
    }
    
    fis.close();
    return r;
}

vector<Object*> importObject(vector<Object*> o) {
    ifstream fis;
    fis.open("/Users/lucastan96/Documents/Computing/Computing Level 8 Year 3/C++/Projects/cppfinalproject/cppfinalproject/Object.txt");
    
    if (fis) {
        while (!fis.eof()) {
            
            string type;
            getline(fis,type);
            if(type=="Object"){
                Object* b=new Object();
                string name,description;
                getline(fis,name);
                name = trim(name);
                b->setName(name);
                getline(fis,description);
                b->setDescription(description);
                o.push_back(b);
            }else if(type=="Hidden"){
                Hidden * h= new Hidden();
                string name,description;
                string temp;
                bool isChecked;
                string keyName;
                getline(fis,name);
                name = trim(name);
                h->setName(name);
                getline(fis,description);
                h->setDescription(description);
                getline(fis,temp);
                isChecked = stringToBool(temp);
                h->setIsChecked(isChecked);
                getline(fis,temp);
                h->setKeyName(temp);
                o.push_back(h);
            }
            
        }
    } else {
        cout << "Error Opening file" << endl;
    }
    
    fis.close();
    return o;
}

void intro(vector<Rooms> &r, Character &c) {
    cout << "Welcome to Haunted Heist!" << endl;
    cout << "Designed by Alvin & Lucas" << endl;
    cout << "\n------------------------------------------------------------------\n" << endl;
    cout << "                         /\\" << endl;
    cout << "                      ////\\\\\\\\" << endl;
    cout << "                   ///////\\\\\\\\\\\\\\" << endl;
    cout << "                //////////\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << "             /////////////\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << "          ////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << "       ///////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << "    //////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << " /////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << "//////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << "|                                                  |" << endl;
    cout << "|  _________                                       |" << endl;
    cout << "|  |   |   |        ___________     _____________  |" << endl;
    cout << "|  |   |   |        | MAILBOX |     |           |  |" << endl;
    cout << "|  |   |   |        |---------|     |           |  |" << endl;
    cout << "|  |___|___|        |  | | |  |     |           |  |" << endl;
    cout << "|  |   |   |        |  | |_|  |     |           |  |" << endl;
    cout << "|  |   |   |        |  |   |  |     |       (@) |  |" << endl;
    cout << "|  |   |   |        |_________|     |           |  |" << endl;
    cout << "|  |___|___|                        |           |  |" << endl;
    cout << "|                                   |           |  |" << endl;
    cout << "|___________________________________|___________|__|" << endl;
    cout << "                                     ___________" << endl;
    cout << "                                    |           |" << endl;
    cout << "                                    |    MAT    |" << endl;
    cout << "                                    |___________|" << endl;
    cout << "\nYou are standing outside a dark & creepy house that's rumored to be haunted.\nYour goal is to navigate the house and steal the treasure hidden in the house, probably protected by ghosts?" << endl;
    cout << "\nDo not be afraid, as you came prepared! You have your very own specially designed vacuum machine and some batteries to protect yourself, along with a backpack to store stuff!" << endl;
    help();
    cout << "\n------------------------------------------------------------------" << endl;
    cout << "Your adventure begins now. May the luck (maybe skills) be with you!" << endl;
    life(c);
    cout << "\n------------------------------------------------------------------" << endl;
    cout << r[0].getDescription() << endl;
    cout << "Objects\t\t\t: ";
    r[0].printObject();
    cout << "Items in bag\t: ";
    c.printBag();
}

void help() {
    cout << "\n------------------------------------------------------------------" << endl;
    cout << "Valid commands:" << endl;
    cout << "\n1. go - go in that direction (north, south, east, west, up, down)" << endl;
    cout << "2. look - observe your surroundings" << endl;
    cout << "3. check - check objects" << endl;
    cout << "4. open - open objects ('open bag' to view inventory)" << endl;
    cout << "5. take - pick up items" << endl;
    cout << "6. use - use items in your bag" << endl;
    cout << "7. map - opens up the house map (if you have one!)" << endl;
    cout << "8. life - show your current life level" << endl;
    cout << "9. quit/exit - exit the game" << endl;
}

void start() {
    vector<Object*> object;
    object = importObject(object);
    vector<Rooms> rooms;
    rooms = importRooms(rooms, object);
    Character c;
    c.addBag(object[2]);
//    c.addBag(object[3]);
//    c.addBag(object[3]);
    bool exit = false;
    
    intro(rooms, c);
    
    while (!exit) {
        string input, command, action;
        
        cout << "\n> ";
        getline(cin, input);
        
        command = input.substr(0, input.find(" "));
        action = input.substr(input.find(" ") + 1, input.size());
        
        if (command == "go") {
            go(c, rooms, action);
        } else if (command == "look") {
            look(rooms, c.getCurrentRoom());
        } else if (command == "check") {
            check(c, action, object, rooms);
        } else if (command == "open") {
            open(c, action, object, rooms);
        } else if (command == "take") {
            take(c, rooms, action);
        } else if (command == "use") {
            use(c, action, object, rooms);
        } else if (command == "life") {
            life(c);
        } else if (command == "map") {
            map(c);
        } else if (command == "quit" || command == "exit") {
            exit = true;
        } else {
            cout << "Invalid command... If you are stuck, simply type 'help'!" << endl;
        }
    }
}

void go(Character &c, vector<Rooms> &r, string action) {
    int curr_room = c.getCurrentRoom();
    vector<int> direction;
    int get_room = 0, index = -1;
    
    for (int i = 0; i < r.size(); i++) {
        if (r[i].getRoom_id() == curr_room) {
            index = i;
        }
    }
    
    if (action == "north" || action == "straight") {
        get_room = r[index].getNorth();
    } else if (action == "south") {
        get_room = r[index].getSouth();
    } else if (action == "east") {
        get_room = r[index].getEast();
    } else if (action == "west") {
        get_room = r[index].getWest();
    } else if (action == "up") {
        get_room = r[index].getUp();
    } else if (action == "down") {
        get_room = r[index].getDown();
    }
    
    if (get_room != 0) {
        if (r[get_room - 1].getIsLocked() == false) {
            c.setCurrentRoom(get_room);
            if (r[c.getCurrentRoom() - 1].getHasGhost() == true) {
                ghost(c, r);
            }
            look(r, get_room);
        } else {
            cout << "The door is locked! You need a key to unlock it..." << endl;
        }
    } else {
        cout << "It's not possible to go " << action << "..." << endl;
    }
}

void look(vector<Rooms> &r, int room_id) {
    cout << "\n------------------------------------------------------------------" << endl;
    cout << r[room_id - 1].getDescription() << endl;
    cout << "Objects\t\t\t: ";
    if (r[room_id - 1].getHasObject().size() != 0) {
        r[room_id - 1].printObject();
    } else {
        cout << "-" << endl;
    }
}

void open(Character &c, string action, vector<Object*> objects, vector<Rooms> &r) {
    if (action == "bag") {
        cout << "\n------------------------------------------------------------------" << endl;
        cout << "Items in bag\t: ";
        c.printBag();
    } else if (action == "mailbox") {
        vector<Object*> curr_room_objects = r[c.getCurrentRoom() - 1].getHasObject();
        searchify(action);
        bool isFound = false;
        
        for (int i = 0; i < curr_room_objects.size(); i++) {
            string object_name = curr_room_objects[i]->getName();
            object_name = trim(object_name);
            
            if (object_name == action || object_name.find(action) != string::npos) {
                int pos = searchObject(objects, action);
                isFound = true;
                
                if (Hidden * m = static_cast<Hidden*>(objects[pos])) {
                    if (m->getIsChecked() == true) {
                        cout << "The " << action << " is already opened..." << endl;
                    } else {
                        m->setIsChecked(true);
                        int pos2 = searchObject(objects, m->getKeyName());
                        r[c.getCurrentRoom() - 1].addObject(objects[pos2]);
                        cout << "You opened the " << action << "... Inside is a " << m->getKeyName() << "!" << endl;
                    }
                }
            }
        }
        
        if (isFound == false) {
            cout << "There is no " << action << " here..." << endl;
        }
    } else if (action == "chest") {
        vector<Object*> curr_room_objects = r[c.getCurrentRoom() - 1].getHasObject();
        searchify(action);
        bool isFound = false;
        
        for (int i = 0; i < curr_room_objects.size(); i++) {
            string object_name = curr_room_objects[i]->getName();
            object_name = trim(object_name);
            
            if (object_name == action) {
                isFound = true;
                
                int pos = searchObject(objects, action);
                cout << "\n" << objects[pos]->getDescription() << endl;
                
                int pin;
                cout << "But what's the pin number: ";
                cin >> pin;
                
                if (pin == 2468) {
                    cout << "\nThe pin was correct. The chest opens! You stole the treasure and ran out of the house, never intending to return again.\nCongratulations, you won!\n" << endl;
                    exit(0);
                } else {
                    cout << "\nThe pin was incorrect, try again... Try exploring the house more for clues!" << endl;
                }
            }
        }
        
        cin.clear();
        cin.ignore(100, '\n');
        
        if (isFound == false) {
            cout << "There is no " << action << " here..." << endl;
        }
    } else if (action == "map") {
        map(c);
    } else if (action == "open") {
        cout << "What do you want to open? (Type 'open ??')" << endl;
    } else {
        cout << "It's not possible to open " << action << "..." << endl;
    }
}

void check(Character &c, string action, vector<Object*> objects, vector<Rooms> &r) {
    if (action == "bag") {
        cout << "Items in bag\t: ";
        c.printBag();
    } else if (action == "life") {
        life(c);
    } else if (action == "mailbox") {
        vector<Object*> curr_room_objects = r[c.getCurrentRoom() - 1].getHasObject();
        searchify(action);
        bool isFound = false;
        
        for (int i = 0; i < curr_room_objects.size(); i++) {
            string object_name = curr_room_objects[i]->getName();
            object_name = trim(object_name);
            
            if (object_name == action || object_name.find(action) != string::npos) {
                int pos = searchObject(objects, action);
                isFound = true;
                
                if (Hidden * m = static_cast<Hidden*>(objects[pos])) {
                    if (m->getIsChecked() == true) {
                        cout << "The " << action << " is already opened..." << endl;
                    } else {
                        m->setIsChecked(true);
                        int pos2 = searchObject(objects, m->getKeyName());
                        r[c.getCurrentRoom() - 1].addObject(objects[pos2]);
                        cout << "You checked inside the " << action << ". There is a " << m->getKeyName() << " inside..." << endl;
                    }
                }
            }
        }
        
        if (isFound == false) {
            cout << "There is no " << action << " here..." << endl;
        }
    } else if (action == "phone") {
        vector<Object*> curr_room_objects = r[c.getCurrentRoom() - 1].getHasObject();
        searchify(action);
        bool isFound = false;
        
        for (int i = 0; i < curr_room_objects.size(); i++) {
            string object_name = curr_room_objects[i]->getName();
            object_name = trim(object_name);
            
            if (object_name == action || object_name.find(action) != string::npos) {
                
                isFound = true;
                
                int pos = searchObject(objects, action);
                cout << "\n" << objects[pos]->getDescription() << endl;
                
            }
        }
        
        if (isFound == false) {
            cout << "There is no " << action << " here..." << endl;
        }
    } else if (action == "chest") {
        vector<Object*> curr_room_objects = r[c.getCurrentRoom() - 1].getHasObject();
        searchify(action);
        bool isFound = false;
        
        for (int i = 0; i < curr_room_objects.size(); i++) {
            string object_name = curr_room_objects[i]->getName();
            object_name = trim(object_name);
            
            if (object_name == action) {
                isFound = true;
                
                int pos = searchObject(objects, action);
                cout << "\n" << objects[pos]->getDescription() << endl;
                
                int pin;
                cout << "But what's the pin number: ";
                cin >> pin;
                
                if (pin == 2468) {
                    cout << "\nThe pin was correct. The chest opens! You stole the treasure and ran out of the house, never intending to return again.\nCongratulations, you won!\n" << endl;
                    exit(0);
                } else {
                    cout << "\nThe pin was incorrect, try again... Try exploring the house more for clues!" << endl;
                }
            }
        }
        
        cin.clear();
        cin.ignore(1000, '\n');
        
        if (isFound == false) {
            cout << "There is no " << action << " here..." << endl;
        }
    } else if (action == "vacumm") {
        // count how many batteries in bag
    } else if (action == "tree") {
        vector<Object*> curr_room_objects = r[c.getCurrentRoom() - 1].getHasObject();
        searchify(action);
        bool isFound = false;
        
        for (int i = 0; i < curr_room_objects.size(); i++) {
            string object_name = curr_room_objects[i]->getName();
            object_name = trim(object_name);
            
            if (object_name == action || object_name.find(action) != string::npos) {
                int pos = searchObject(objects, action);
                isFound = true;
                
                if (Hidden * m = static_cast<Hidden*>(objects[pos])) {
                    if (m->getIsChecked() == true) {
                        cout << "The " << action << " is already checked..." << endl;
                    } else {
                        m->setIsChecked(true);
                        int pos2 = searchObject(objects, m->getKeyName());
                        r[c.getCurrentRoom() - 1].addObject(objects[pos2]);
                        cout << "You checked the " << action << "... There is a " << m->getKeyName() << " inside!" << endl;
                    }
                }
            }
        }
        
        if (isFound == false) {
            cout << "There is no " << action << " here..." << endl;
        }
    } else if (action == "red-colored mat" || action == "yellow-colored mat" || action == "blue-colored mat" || action == "green-colored mat" || action == "mat") {
        vector<Object*> curr_room_objects = r[c.getCurrentRoom() - 1].getHasObject();
        searchify(action);
        bool isFound = false;
        
        for (int i = 0; i < curr_room_objects.size(); i++) {
            string object_name = curr_room_objects[i]->getName();
            object_name = trim(object_name);
            int number = 0;
            
            if (action == "mat" && object_name == "red-colored mat") {
                action = "red-colored mat";
                number = 2;
            } else if (action == "mat" && object_name == "yellow-colored mat") {
                action = "yellow-colored mat";
                number = 4;
            } else if (action == "mat" && object_name == "blue-colored mat") {
                action = "blue-colored mat";
                number = 6;
            } else if (action == "mat" && object_name == "green-colored mat") {
                action = "green-colored mat";
                number = 8;
            }
            
            if (object_name == action) {
                int pos = searchObject(objects, action);
                isFound = true;

                if (Hidden * m = static_cast<Hidden*>(objects[pos])) {
                    if (m->getIsChecked() == true) {
                        cout << "You checked underneath the " << action << ". A number " << number << " is printed on the mat..." << endl;
                    } else {
                        m->setIsChecked(true);
                        if (action == "red-colored mat") {
                            int pos2 = searchObject(objects, m->getKeyName());
                            r[c.getCurrentRoom() - 1].addObject(objects[pos2]);
                            cout << "You checked underneath the " << action << ". A number " << number << " is printed on the mat... There's also a " << m->getKeyName() << "!" << endl;
                        } else {
                            cout << "You checked underneath the " << action << ". A number " << number << " is printed on the mat..." << endl;
                        }
                    }
                }
            }
        }
        
        if (isFound == false) {
            cout << "There is no " << action << " here..." << endl;
        }
    } else if (action == "map") {
        map(c);
    } else if (action == "check") {
        cout << "What do you want to check? (Type 'check ??')" << endl;
    } else {
        cout << "It's not possible to check " << action << "..." << endl;
    }
}

void use(Character &c, string action, vector<Object*> objects, vector<Rooms> &r) {
    if (action == "phone") {
        vector<Object*> curr_room_objects = r[c.getCurrentRoom() - 1].getHasObject();
        searchify(action);
        bool isFound = false;
        
        for (int i = 0; i < curr_room_objects.size(); i++) {
            string object_name = curr_room_objects[i]->getName();
            object_name = trim(object_name);
            
            if (object_name == action || object_name.find(action) != string::npos) {
                isFound = true;
                
                int pos = searchObject(objects, action);
                cout << "\n" << objects[pos]->getDescription() << endl;
            }
        }
        
        if (isFound == false) {
            cout << "There is no " << action << " here..." << endl;
        }
    } else if (action == "key" || action == "small key" || action == "big key") {
        int curr_room = c.getCurrentRoom();
        vector<int> direction;
        vector<Object*> bag = c.getBag();
        bool isFound = false;
        
        if (curr_room == 1) {
            for (int i = 0; i < bag.size(); i++) {
                if (bag[i]->getName() == "small key") {
                    isFound = true;
                    c.setCurrentRoom(2);
                    cout << "You unlocked the door with the key!" << endl;
                    if (r[c.getCurrentRoom() - 1].getHasGhost() == true) {
                        ghost(c, r);
                    }
                    look(r, 2);
                    r[1].setIsLocked(false);
                    c.removeBag(bag[i]);
                }
            }
        } else if (curr_room == 7) {
            for (int i = 0; i < bag.size(); i++) {
                if (bag[i]->getName() == "big key") {
                    isFound = true;
                    c.setCurrentRoom(9);
                    cout << "You unlocked the door with the key!" << endl;
                    if (r[c.getCurrentRoom() - 1].getHasGhost() == true) {
                        ghost(c, r);
                    }
                    look(r, 9);
                    r[8].setIsLocked(false);
                    c.removeBag(bag[i]);
                }
            }
        }
        
        if (isFound == false) {
            cout << "You don't have a key to unlock the door..." << endl;
        }
    } else if (action == "vacumm") {
        
    } else if (action == "torchlight" || action == "torch" || action == "map") {
        map(c);
    } else if (action == "use") {
        cout << "What do you want to use? (Type 'use ??', or type 'open bag' to check what you can use)" << endl;
    } else {
        cout << "It's not possible to use " << action << "..." << endl;
    }
}

void take(Character &c, vector<Rooms> &r, string action) {
    if (action != "take") {
        if (action == "mailbox" || action == "tree" || action == "red-colored mat" || action == "yellow-colored mat" || action == "blue-colored mat" || action == "green-colored mat" || action == "mat" || action == "chest" || action == "phone") {
            cout << "It's not possible to take " << action << "..." << endl;
        } else {
            vector<Object*> curr_room_objects = r[c.getCurrentRoom() - 1].getHasObject();
            searchify(action);
            bool isFound = false;
            
            if (action == "torch" || action == "light") {
                action = "torchlight";
            }
            
            for (int i = 0; i < curr_room_objects.size(); i++) {
                string object_name = curr_room_objects[i]->getName();
                object_name = trim(object_name);
                
                if (object_name == action || object_name.find(action) != string::npos) {
                    c.addBag(curr_room_objects[i]);
                    r[c.getCurrentRoom() - 1].removeObject(curr_room_objects[i]);
                    
                    if (action == "torchlight") {
                        c.setHasTorch();
                        cout << "You took the " << action << "... Oh wow, you can now access the house map by typing 'map'!" << endl;
                    } else {
                        cout << "You took the " << action << "..." << endl;
                    }
                    
                    isFound = true;
                }
            }
            
            if (!isFound) {
                cout << "No " << action << " is found in this room..." << endl;
            }
        }
    } else {
        cout << "What do you want to take? (Type 'take ??')" << endl;
    }
}

void ghost(Character &c, vector<Rooms> &r) {
    vector<Object*> bag = c.getBag();
    int battery_count = 0;
    int battery_pos = -1;
    
    for (int i = 0; i < bag.size(); i++) {
        if (bag[i]->getName() == "battery") {
            if (battery_pos == -1) {
                battery_pos = i;
            }
            battery_count++;
        }
    }
    
    cout << "\n------------------------------------------------------------------" << endl;
    if (c.getCurrentRoom() != 9) {
        cout << "As you enter this area, a ghost suddenly appears!! What will you do? ('use ??')" << endl;
    } else {
        cout << "As you enter the attic, a huge ghost suddenly appears!! What will you do? ('use ??')" << endl;
    }
    
    
    bool ghost_killed = false;
    int final_boss = 0;
    
    while (!ghost_killed) {
        string input, command, action;
        
        cout << "\n> ";
        getline(cin, input);
        
        command = input.substr(0, input.find(" "));
        action = input.substr(input.find(" ") + 1, input.size());
        
        if (command == "use") {
            if (action == "vacuum") {
                cout << "\nYou tried to use the vacumn machine to suck the ghost..." << endl;
                if (battery_count != 0) {
                    battery_count--;
                    c.removeBag(bag[battery_pos]);
                    if (c.getCurrentRoom() != 9 || final_boss == 1) {
                        ghost_killed = true;
                        r[c.getCurrentRoom() - 1].setHasGhost(false);
                        cout << "...and was successful! The ghost is trapped now..." << endl;
                    } else {
                        final_boss = 1;
                        cout << "...and you hurt the ghost a little! Do it again!!" << endl;
                    }
                } else {
                    c.setNumOfLife(c.getNumOfLife() - 1);
                    if (c.getNumOfLife() != 0) {
                        cout << "...only to realize you don't have a battery! The ghost hurt you! You have " << c.getNumOfLife() << " heart left!! The ghost suddenly dissapeared, so you are safe for now..." << endl;
                        life(c);
                    } else {
                        cout << "...only to realize you don't have a battery! The ghost hurt you! You died and you became a ghost too... Game over!\n" << endl;
                        exit(0);
                    }
                    ghost_killed = true;
                }
            } else if (action == "use") {
                cout << "What do you want to use? (Type 'use ??', or type 'open bag' to check what you can use)" << endl;
            } else {
                cout << "It's not possible to use " << action << "..." << endl;
            }
        } else if (command == "open" || command == "check") {
            if (action == "bag") {
                cout << "\n------------------------------------------------------------------" << endl;
                cout << "Items in bag\t: ";
                c.printBag();
            } else if (action == "open") {
                cout << "What do you want to open? (Type 'open ??')" << endl;
            } else if (command == "check" && action == "life") {
                life(c);
            } else {
                cout << "It's not possible to open " << action << "... You have a ghost to fight!!" << endl;
            }
        } else if (command == "life") {
            life(c);
        } else if (command == "help") {
            ghostHelp();
        } else if (command == "quit" || command == "exit") {
            exit(0);
        } else {
            cout << "You have to fight the ghost!" << endl;
        }
    }
}

void ghostHelp() {
    cout << "\n------------------------------------------------------------------" << endl;
    cout << "Valid commands:" << endl;
    cout << "\n1. use - use items in your bag ('use vacuum' to kill ghost)" << endl;
    cout << "2. check - ('check bag' to view inventory)" << endl;
    cout << "3. open - ('open bag' to view inventory)" << endl;
    cout << "4. life - show your current life level" << endl;
    cout << "5. quit/exit - exit the game" << endl;
}

void life(Character &c) {
    cout << "Life\t\t\t: ";
    for (int i = 0; i < c.getNumOfLife(); i++) {
        cout << "\u2764 ";
    }
    cout << "(" << c.getNumOfLife() << " left)" << endl;
}

void map(Character &c) {
    if (c.getHasTorch() == true) {
        cout << "First Floor (@ = tree)" << endl;
        cout << " ___________________________________________________" << endl;
        cout << "| \\/ |                                            @@|" << endl;
        cout << "|_/\\_|              ______________________________@@|" << endl;
        cout << "|            |______|__DOOR__|     |__DOOR__| |__   |" << endl;
        cout << "|            |______|              |             |  |" << endl;
        cout << "|            |STAIR |        ______|             |  |" << endl;
        cout << "|            |______|        |     |_x__         |  |" << endl;
        cout << "|            |______|        |  B  |    |x       |  |" << endl;
        cout << "|            |______|        |     |    |x       |__|" << endl;
        cout << "|            _______|        |  E  |____|x          |" << endl;
        cout << "|            | MAT ||    ____|     | x              |" << endl;
        cout << "|  _________ |_____||   | \\/ |  D  |                |" << endl;
        cout << "|__| DOOR  |________|___|_/\\_|_____|________________|" << endl << endl << endl;
        
        cout << "Second Floor (@ = tree, Q = phone)" << endl;
        cout << " ___________________________________________________" << endl;
        cout << "| \\/ |         | <--|     _____________________     |" << endl;
        cout << "|_/\\_|         |_UP_|    |     S  O  F  A      |    |" << endl;
        cout << "|                   |    |_____________________|    |" << endl;
        cout << "|                   |                       _____   |" << endl;
        cout << "|                   |_      Q              |     |  |" << endl;
        cout << "|             _____ |D| _____              |  S  |  |" << endl;
        cout << "|            | MAT ||O|| MAT |             |  O  |  |" << endl;
        cout << "|            |_____||O||_____|             |  F  |  |" << endl;
        cout << "|_____              |R|                    |  A  |  |" << endl;
        cout << "|_U__|            @@|_|         @@         |     |  |" << endl;
        cout << "|_P__|            @@|           @@         |_____|  |" << endl;
        cout << "|____|______________|_______________________________|" << endl << endl << endl;
        
        cout << "Attic (&& = lock)" << endl;
        cout << " ___________________" << endl;
        cout << "|     ________      |" << endl;
        cout << "|     | GOLD |      |" << endl;
        cout << "|     |__&&__|      |" << endl;
        cout << "|                   |" << endl;
        cout << "|                   |" << endl;
        cout << "|                   |" << endl;
        cout << "|                   |" << endl;
        cout << "|                   |" << endl;
        cout << "|_____              |" << endl;
        cout << "| /|\\|              |" << endl;
        cout << "|  | |              |" << endl;
        cout << "|____|______________|" << endl;
        
        cout << "\n\nThe map is displayed above..." << endl;
    } else {
        cout << "There must be a map lying somewhere..." << endl;
    }
}

void searchify(string &s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}
