#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int operations;
	cin >> operations;

	const vector<int> daysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int nowMonth = 0;
	int nextMonth = 1;
	vector<vector<string>> month(daysInMonth[nowMonth]);

	vector<string> reserveDay;
	int save = 0;

	string command;
	int i;
	string to_do;
	int fin;


	while (operations--) {
		cin >> command;
		if (command == "ADD") {
			cin >> i >> to_do;
			month[i - 1].push_back(to_do);
		}
		else if (command == "DUMP") {
			cin >> i;
			cout << month[i - 1].size() << " ";
			for (string x : month[i - 1]) {
				cout << x << " ";
				
			}
			cout << endl;
		}
		else if (command == "NEXT") {
			if (nowMonth == 11) {
				nextMonth = 0;
			}
			if (daysInMonth[nowMonth] > daysInMonth[nextMonth]) {
				save = daysInMonth[nextMonth];
				while (save <= daysInMonth[nowMonth] - 1) {
					for (string x : month[save]) {
						reserveDay.push_back(x);
					}
					save++;
				}
				save = 1;
			}
			nowMonth = nextMonth;
			nextMonth += 1;
			month.resize(daysInMonth[nowMonth]);
			if (save == 1) { 
				for (string x : reserveDay) {
					month[daysInMonth[nowMonth] - 1].push_back(x); 
				}
				save = 0;
				reserveDay.clear();
			}
		}
	}
	return 0;
}
