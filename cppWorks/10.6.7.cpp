#include <iostream>
#include <string>
#include <map>

using namespace std;

class Table {
public:
    int set(string, string);
    string get(string);
private:
    map<string, string> table;
};

int Table::set(string name, string value) {
    table[name] = value;
    return 1;
}

string Table::get(string name) {
    return table[name];
}

int main() {
    Table table;
    table.set("a", "aaa");
    cout<<table.get("a");
    return 0;
}