#include "std_lib_facilities.h"
int main() {
	cout << "Enter the name of the person you want to write to:\n";
	string first_name;
	cin >> first_name;
	cout << "Dear " << first_name << ",\n";
	cout << "I'm doing well myself, it's been a while since we last talked!\n";

	cout << "What's your friend's name?\n";
	string friend_name;
	cin >> friend_name;
	cout << "Have you seen " << friend_name << " lately?\n";

	cout <<  "What's your age?\n";
	int age;
	cin >> age;
	cout << "I hear you had a birthday and you're now " << age << " year's old!\n";

	if (age > 110 || age < 0)
		simple_error("Hey that's not possible!");
	if (age > 65)
		cout << "It's great to see senior students around campus!\n";
	if (age < 17)
		cout << "You're young to be at NYU!\n"; 
}
