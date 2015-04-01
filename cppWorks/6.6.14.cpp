#include<iostream>

using namespace std;

int Istrlen(const char* ip) {
    int n = -1;
    while(ip[++n] != '\0') ;
    return n;
}

char* rev(char* ip) {
    int n = Istrlen(ip);
    char *ret = new char[n+1];
    ret[n] = '\0';
    for(int i = 0; i < n; i++) {
        ret[i] = ip[n-i-1];
    }
    return ret;
}

int main() {
    cout<<rev("abcdefghi");
    return 0;
}