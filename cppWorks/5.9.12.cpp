#include<iostream>
#include<string>

using namespace std;

int TimesInStr(string subject, string search) {
    int cnt = 0;
    for (size_t i=0; (i=subject.find(search, i)) != std::string::npos; cnt++, i++);
    return cnt;
}

int TimesInStrC(char* subject, char* search) {
    int i = 0, j, flag, cnt = 0;
    while(subject[i] != '\0') {
        j = 0; flag = 1;
        while(search[j] != '\0') {
            if(subject[i++] != search[j++]) {
                flag = 0; --j;
                break;
            }
        }
        if(flag == 1) {
            cnt++;
        } else {
            i -= j;
        }
    }
    return cnt;
}

int main() {
    cout<<TimesInStr("xabaacbaxabb", "ab")<<endl;
    cout<<TimesInStrC("xabaacbaxabb", "ab")<<endl;
    return 0;
}
