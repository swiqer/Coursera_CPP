#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	ifstream input("input.txt");
	string s;
	cout << fixed << setprecision(3);
	if (input) {
		while (getline(input, s)) {
			cout << atof(s.c_str()) << endl;
		}
	}
	return 0;
}


////////////////////////////////////////////////////////
///////////////////////// OR ///////////////////////////
////////////////////////////////////////////////////////


int main() {
	ifstream input("input.txt");
	double s;
	cout << fixed << setprecision(3);
	if (input) {
		while (input >> s) {
			cout << s << endl;
		}
	}
	return 0;
}
