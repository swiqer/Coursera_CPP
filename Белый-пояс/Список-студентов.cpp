#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student{
	string name;
	string lastName;
	int day;
	int month;
	int year;
};

int main() {
	int rounds;
	cin >> rounds;
	int save = rounds;
	vector<Student> students;
	while (rounds--) {
		Student dude;
		cin >> dude.name >> dude.lastName >> dude.day >> dude.month >> dude.year;
		students.push_back(dude);
	}

	cin >> rounds;
	while (rounds--) {
		string command;
		int num;
		cin >> command >> num;
		if (command == "name" && (0 < num && num <= save)) {
			cout << students[num - 1].name << " " << students[num - 1].lastName << endl;
		}
		else if (command == "date" && (0 < num && num <= save)){
			cout << students[num - 1].day << "." << students[num - 1].month << "." << students[num - 1].year << endl;
		}
		else {
			cout << "bad request" << endl;
		}
	}
}
