#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	ifstream input("input.txt");
	string s;
	if (input) {
		while (getline(input, s)) {
			cout << s << endl;
		}
	}
	return 0;
}
