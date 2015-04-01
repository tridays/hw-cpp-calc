#ifndef cppWorks_Date_h
#define cppWorks_Date_h

#include <iostream>
#include <string>

using namespace std;

class Date {
public:
    enum Month { jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
    class Bad_data {};
    Date(int dd=0, Month mm=Month(0), int yy=0);
    
    int day() const;
    Month month() const;
    int year() const;
    string string_rep() const;
    void char_rep(char s[]) const;
    
    static void set_default(int, Month, int);
    
    Date& add_year(int n);
    Date& add_month(int n);
    Date& add_day(int n);
    
private:
    int d, m, y;
    static Date default_date;
    
    
};



#endif
