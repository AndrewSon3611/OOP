#include "std_lib_facilities.h"
#include "date.h"


int main(){
    int u_day;
    int u_month;
    int u_year;
    Date today(2018,7,29);
    Date sample_date(2019,7,29);
    string option = "";

	cout << "Press d to increment day, m to increment month, y to increment year. '\n' Press c to compare a date with today's date, or press q to quit. '\n' ";
    while(option != "q"){
        cin >> option;
        if (option == "d"){
            today.add_day(0);
        }
        else if(option == "m"){
            today.add_month();
        }
        else if(option == "y"){
            today.add_year();
        }
        else if(option == "c"){
            cout << "Comparing today's date: " << today << "with sample date: " << sample_date;
            if (today == sample_date){
                cout << "Matching result '\n' ";
            }
        
            else{
                cout << "Dates do not match '\n'";
            }
        }
        }
	return 0;
}
