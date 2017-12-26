//
//  Hidden.hpp
//  cppfinalproject
//
//  Created by Lucas Tan on 12/11/17.
//  Copyright © 2017 Lucas Tan. All rights reserved.
//

#ifndef Hidden_hpp
#define Hidden_hpp

#include <stdio.h>
#include "Object.hpp"

class Hidden:public Object {
private:
    
    bool isChecked;
    string keyName;
public:
    Hidden();
    Hidden(string n, string desc, bool check,string keyName);
    
    bool getIsChecked() const;
    void setIsChecked(bool check);
    string getKeyName() const;
    void setKeyName(string name);
    ~Hidden();
};
#endif /* Hidden_hpp */
