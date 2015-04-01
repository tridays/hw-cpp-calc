#include <iostream>
#include <string>

using namespace std;

class Tnode {
    Tnode* parent = NULL;
    Tnode* prev = NULL;
    Tnode* next = NULL;
    Tnode* son  = NULL;
    string val  = "";
public:
    Tnode(string = "", Tnode* = NULL);
    ~Tnode();
};

Tnode::Tnode(string value, Tnode* parent) {
    if(parent) {
        Tnode* t = parent->son;
        if(t) {
            while(t->next) {
                t = t->next;
            }
            t->next = this;
            this->prev = t;
        } else {
            parent->son = this;
        }
        this->parent = parent;
    }
    this->val = value;
    cout<<"Tnode "<<this->val<<" is constructed."<<endl;
}

Tnode::~Tnode() {
    if(this->prev) {
        this->prev->next = this->next;
    } else if(this->parent) {
        this->parent->son = this->next;
    }
    
    if(this->next) {
        this->next->prev = this->prev;
    }
    
    Tnode* t = this->son;
    if(t) {
        while(t->next) {
            t = t->next;
            delete(t->prev);
        }
        delete(t);
    }
    cout<<"Tnode "<<this->val<<" is destructed."<<endl;
}

int main() {
    Tnode* root = new Tnode("root");
    Tnode* first = new Tnode("first", root);
    Tnode* second = new Tnode("second", root);
    Tnode* third = new Tnode("third", first);
    delete(first);
    delete(root);
    return 0;
}