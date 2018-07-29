#include "std_lib_facilities.h"
#include "date.h"

Date::Date(int yy, int mm, int dd)
		:y{yy}, m{mm}, d{dd}
		{
            if(!is_valid())
                   throw Invalid{};


		}

ostream& operator <<(ostream& os, const Date& d){
    return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';}

bool operator == (const Date& d1, const Date d2){
    if(d1.day() == d2.day() && d1.month() == d2.month() && d1.year() == d2.year())
        return true;
    else
        return false;
}
bool operator != (const Date& d1, const Date d2){
    if(d1.day() != d2.day() && d1.month() != d2.month() && d1.year() != d2.year())
        return false;

    else
        return true;
}



bool Date::leap_year(){
    if ((y % 4) == 0)
        return true;
    else
        return false;
}


void Date::add_day(int n)
        {
            switch(m){
             case 12:
            {
                if(d==31){
                    y++;
                    m = 1;
                    d = 1;
                    return;
                }
                else{
                    d++;
                    return;
                }
            }
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            {
                if(d==31){
                    m++;
                    d = 1;
                    return;
                }
                else{
                    d++;
                    return;
                }
            }
            case 4:
            case 6:
            case 9:
            case 11:
            {
                if (d == 30){
                    m++;
                    d = 1;
                    return;
                }
                else{
                    d++;
                    return;
                }
            }
            case 2:
            {
                if(leap_year())
                    if(d == 29){
                        m++;
                        d = 1;
                        return;
                    }
                    else{
                        d++;
                        return;
                    }

                else{
                    if(d ==28){
                        m++;
                        d = 1;
                        return;
                    }
                    else{
                        d++;
                        return;
                    }
                }
            }
        }
    }





bool Date::is_valid()
        {
            if(int(m) < 1 || int(m) > 12);
                return false;
            return true;

            switch(m){
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    if(d < 1 || d > 31){
                        return false;}
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    if (d < 1 || d > 31)
                        return false;
                    break;
                case 2:
                    if (leap_year()) {
                        if (d < 1 || d > 29)
                            return false;
                        break;
                    }
                    else if(d < 1 || d>28)
                        return false;
                    break;
            }
            return true;
        }


void Date::add_month(){
    switch(m){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            {
                m++;
                return;
            }
        case 12:
            {
                y++;
                m = 1;
                return;
            }
        }
}

void Date::add_year()
{
    y++;
    return;
}

int Date::month(){
    return m;
}

int Date::day(){
    return d;
}

int Date::year(){
    return y;
}




