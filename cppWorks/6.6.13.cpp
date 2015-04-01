#include<iostream>
#include<string>

using namespace std;

int Istrlen(const char* ip) {
    int n = -1;
    while(ip[++n] != '\0') ;
    return n;
}

int strcpy(char* from, char* to, int from_pos, int to_pos, int length) {
    for(int i = 0; i < length; i++) {
        to[to_pos + i] = from[from_pos + i];
    }
    return 0;
}

char* cat(char* a, char* b) {
    int an = Istrlen(a), bn = Istrlen(b);
    char* c = new char[an+bn+1];
    c[an+bn] = '\0';
    strcpy(a, c, 0, 0, an);
    strcpy(b, c, 0, an, bn);
    return c;
}

int main() {
    cout<<cat("abc", "defghi");
    return 0;
}