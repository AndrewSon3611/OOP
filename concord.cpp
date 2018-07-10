#include "std_lib_facilities.h"
int main() {
    cout << "Enter words: \n";
	vector <string> text;
    string  word;

	for (string word ; cin >> word;)
		text.push_back(word);
	sort(text);
	
    int index = 0;
    string prev = text[index];
    int count = 0;
    while (index < text.size()){
        if (text[index] == prev){
            count++;
        }
        else{
            cout << prev << ": " << count << endl;
            prev = text[index];
            count = 1;
        }
        index++;
    }
    cout << prev << ": " << count << endl;

    keep_window_open();
    return 0;



}

