//
//  10.6.2.cpp
//  cppWorks
//
//  Created by 徐普 on 14-10-28.
//  Copyright (c) 2014年 xp. All rights reserved.
//

#include "Date.h"

Date

Date& Date::add_year(int n) {
    if(this->d == 29 && this->m == Month::feb && !leapyear(this->y+n)) {
        this->d = 1;
        this->m = 3;
    }
    return *this;
}

int main() {
    Date date(1, Date::Month::jan, 1970);
    date.day();
    
    return 0;
}