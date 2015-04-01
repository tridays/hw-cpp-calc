#include <iostream>

int LeapYear(int y) {
    return ((y%4==0) && (y%100 != 0)) || (y%400 == 0) ? 1 : 0;
}

int DateDiff(int y, int m, int d) {
    int n = -1;
    for(int i=1970;i<y;i++) {
        n += 365 + LeapYear(i);
    }
    int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=1;i<m;i++) {
        n += month[i];
        if(i == 2 && LeapYear(y)) ++n;
    }
    n += d;
    return n;
}

int main() {
    std::cout<<DateDiff(2014, 10, 28);
    return 0;
}