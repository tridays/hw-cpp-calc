#include<iostream>
#include <math.h>

using namespace std;

int Iintlen(const int ip) {
    int n = 0;
    while(ip - pow(10, ++n) >= 0) ;
    return n;
}

char* Iitoa(const int ip) {
    int isnag = (ip < 0) ? 1 : 0;
    int val = (isnag == 1) ? -ip : ip;
    int t;
    
    int n = Iintlen(val);
    char* str = new char[n + isnag + 1];
    str[n + isnag] = '\0';
    if(isnag == 1) str[0] = '-';
    
    for(int i = isnag; i < (n + isnag); i++) {
        t = (int)pow(10, n-i);
        str[i] = (val / t) + '0';
        val %= t;
    }
    
    return str;
}

int main() {
    cout<<Iitoa(-255)<<endl;
    return 0;
}