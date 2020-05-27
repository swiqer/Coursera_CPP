#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	ifstream input("input.txt");
	string s;
	ofstream output("output.txt");
	if (input && output) {
		while (getline(input, s)) {
			output << s << endl;
		}
	}
	return 0;
}
