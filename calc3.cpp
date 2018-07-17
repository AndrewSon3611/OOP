#include "std_lib_facilities.h"

const char name = 'a';
const char number = '8';
const char quit = 'q';
const char print = ';';

const string prompt = "> ";
const string result = "= ";


class Token {
    public:
        char kind;
        double val;
};

class Token_stream{
    public:
        Token get();
        void putback(Token t);
        void ignore(char c);
    private:
        bool full = false;
        Token buffer;
};

void Token_stream::putback(Token t){
    buffer = t;
    full = true;
}

void Token_stream::ignore(char c){
    if (full && c == buffer.kind){
        full = false;
        return;
    }
    full = false;

    char ch = 0;
    while(cin >> ch)
        if (ch == c) return;
}
Token Token_stream::get(){
    if(full){
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;
    switch (ch){
        case print:
        case quit:
        case'(':
        case')':
        case'+':
        case'-':
        case'*':
        case'/':
        case'%':
            return Token{ch};
        case'.':
        case '0': case '1': case'2':case'3':case'4':case'5':case'6':case'7':case'8':case'9':{
            cin.putback(ch);
            double val;
            cin >> val;
            return Token{number,val};
        }
    }
}

Token_stream ts;
double expression();
double term();
double primary();

double expression(){
    double left = term();
    Token t = ts.get();

    while (true){
        switch(t.kind){
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;

        }
    }
}

double term(){
    double left = primary();
    Token t = ts.get();

    while(true){
        switch(t.kind){
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {
            double d = primary();
            if (d==0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;

            }
        case '%':{
            double d = primary();
            if (d==0) error("divide by zero");
            left = fmod(left,d);
            t = ts.get();
            break;
        }
        default:
        ts.putback(t);
        return left;

        }
    }
}

double primary(){
        Token t = ts.get();
    switch(t.kind){
    case '(':
        {
        double d = expression();
        t = ts.get();
        if (t.kind!= ')') error("')' expected");
            return d;
        }
    case number:
        return t.val;
    case '-':
        return -primary();
    case '+':
        return primary();
    default:
        error("Primary expected");

    }
}
void clean_up_mess(){
    ts.ignore(print);
    }


void calculate(){
    while (cin){
       try{
        cout << prompt;
        Token t = ts.get();
        cout << "in main(), got token: " << t.kind << " with val of "<< t.val << '\n';
        while (t.kind == print) t = ts.get();
       if (t.kind == quit) return;
       ts.putback(t);
      cout << result << expression()<< '\n';
    }
    catch(exception& e){
        cerr << e.what() << '\n';
        clean_up_mess();
        } 
    }   
}
int main(){
    cout << "Please enter an expression: " << endl;
    try{
        calculate();
        return 0;
    }
    catch(...){
        cerr << "Exception \n";
        return 2;
    }

}



