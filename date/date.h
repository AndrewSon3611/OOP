#include "std_lib_facilities.h"

class Date{
	public:
		Date(int y, int m, int d);
		void add_day(int n);
        void add_month();
        void add_year();
        int month();
        int day();
        int year();
		int month() const{return m;}
        int year() const{return y;}
        int day() const{return d;}
        class Invalid{};
        bool is_valid();


	private:
		int y, m, d;
        bool leap_year();
};


ostream& operator << (ostream& os, const Date& d);
bool operator == (const Date& d1, const Date d2);
bool operator != (const Date& d1, const Date d2);


