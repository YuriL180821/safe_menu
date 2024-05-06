#include <limits>
#include <iostream>
using namespace std;

template <class T>
bool safe_input(T& v) {
	bool result = (cin >> v) && (cin.get() == '\n');
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return result;
}

int main() {
	static auto item1_handler = []() {
		cout << "Menu item1 pressed" << endl;
		};
	static auto item2_handler = []() {
		cout << "Menu item2 pressed" << endl;
		};
	size_t user_coice = -1;
	while (user_coice != 0) {
		cout << "\tMENU" << endl;
		cout << "1 - Item1" << endl;
		cout << "2 - Item2" << endl;
		cout << "0 - Exit" << endl;
		if (cout << "Enter your choice: ", !safe_input(user_coice))
			user_coice = -1, cerr << "Incorrect user input" << endl;
		else
		{
			switch (user_coice) {
			case 1: item1_handler(); break;
			case 2: item2_handler(); break;
			case 0:
				cout << "Exiting" << endl;
				break;
			default:
				cerr << "Unsupported menu key" << endl;
			}
		}
	}
	return 0;
}