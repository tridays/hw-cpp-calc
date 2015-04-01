
#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

enum TokenList {
    VARIABLE, NUMBER, END,
    PLUS='+', MINUS='-', MUL='*', DIV='/',
    SEPARATOR=';', ASSIGN='=', LP='(', RP=')',
    // EQUAL='==', INEQUAL='!=', LT='<', GT='>', LE='<=', GE='>=',
};
TokenList curr_tok = SEPARATOR;

double expr(bool get);
double term(bool get);
double prim(bool get);
TokenList getToken();
double error(const string& s);

map<string, double> table;

double expr(bool get) {
    double left = term(get);
    for(;;) {
        switch(curr_tok) {
            case PLUS:
                left += term(true);
                cout<<"+ )";
                break;
            case MINUS:
                left -= term(true);
                cout<<"- )";
                break;
            default:
                return left;
        }
    }
}

double term(bool get) {
    double left = prim(get);
    for(;;) {
        switch(curr_tok) {
            case MUL:
                left *= prim(true);
                cout<<"* )";
                break;
            case DIV:
                if(double d = prim(true)) {
                    left /= d;
                    cout<<"/ )";
                    break;
                } else {
                    return error("divide by 0");
                }
            default:
                return left;
        }
    }
}

double number_value;
string string_value;

double prim(bool get) {
    if(get) getToken();
    switch(curr_tok) {
        case NUMBER: {
            double v = number_value;
            getToken();
            cout<<"("<<v;
            return v;
        }
        case VARIABLE: {
            double &v = table[string_value];
            if(getToken() == ASSIGN) v = expr(true);
            return v;
        }
        case MINUS:
            return -prim(true);
        case LP: {
            double e = expr(true);
            if(curr_tok != RP) return error(") expected");
            getToken();
            return e;
        }
        default:
            return error("primary expected");
    }
}

TokenList getToken() {
    char ch = 0;
    cin>>ch;
    switch(ch) {
        case 0:
            return curr_tok=END;
        case ';':
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
            return curr_tok=TokenList(ch);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            cin.putback(ch);
            cin>>number_value;
            return curr_tok=NUMBER;
        default:
            if(isalpha(ch)) {
                cin.putback(ch);
                cin>>string_value;
                return curr_tok=VARIABLE;
            }
            error("bad token");
            return curr_tok=SEPARATOR;
    }
}

int error_count;

double error(const string& s) {
    error_count++;
    cerr<<"error: "<<s<<endl;
    return 1;
}

int main(int argc, const char * argv[]) {
    table["pi"] = 355.0/113.0;
    table["e"] = 2.71828182845904523536;
    
    while(cin) {
        getToken();
        if(curr_tok == END) break;
        if(curr_tok == SEPARATOR) continue;
        cout<<"="<<expr(false)<<'\n';
    }
    
    return 0;
}
