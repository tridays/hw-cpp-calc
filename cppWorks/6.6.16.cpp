#include<iostream>
#include<math.h>

using namespace std;

int Istrlen(const char* ip) {
    int n = -1;
    while(ip[++n] != '\0') ;
    return n;
}

int Iatoi(const char* ip) {
    int n = Istrlen(ip);
    int t, v = 0;
    if(ip[0] == '0') {
        if(ip[1] == 'x') {
            for(int i = 2; i < n; i++) {
                if(ip[i] <= '9') {
                    t = ip[i] - '0';
                } else if(ip[i] <= 'F') {
                    t = ip[i] - 'A' + 10;
                } else {
                    t = ip[i] - 'a' + 10;
                }
                v += t * pow(16, n-i-1);
            }
        } else {
            for(int i = 1; i < n; i++) {
                v += (ip[i]-'0') * pow(8, n-i-1);
            }
        }
    } else {
        for(int i = 0; i < n; i++) {
            v += (ip[i]-'0') * pow(10, n-i-1);
        }
    }
    return v;
}

int main() {
    cout<<Iatoi("255")<<endl;
    cout<<Iatoi("0377")<<endl;
    cout<<Iatoi("0xFF")<<endl;
    const char* str = "255";
    cout<<Iatoi(str)<<endl;
    return 0;
}