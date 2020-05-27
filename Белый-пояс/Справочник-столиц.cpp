#include <iostream>
#include <string>
#include <map>
using namespace std;

void ChangeCapital(const string& country, const string& newCapital, map<string, string>& countries) {
	if (countries.count(country) == 0) {
		cout << "Introduce new country " << country << " with capital " << newCapital << endl;
		countries[country] = newCapital;
	}
	else if (countries[country] == newCapital) cout << "Country " << country << " hasn't changed its capital" << endl;
	else if (countries[country] != newCapital) {
		cout << "Country " << country << " has changed its capital from " << countries[country] << " to " << newCapital << endl;
		countries[country] = newCapital;
	}
}

void Rename(const string& oldCountryName, const string& newCountryName, map<string, string>& countries) {
	if (oldCountryName == newCountryName || countries.count(oldCountryName) == 0 || countries.count(newCountryName) == 1) {
		cout << "Incorrect rename, skip" << endl;
	}
	else {
		string meaning = countries[oldCountryName];
		cout << "Country " << oldCountryName << " with capital " << countries[oldCountryName] << " has been renamed to " << newCountryName << endl;
		countries.erase(oldCountryName);
		countries[newCountryName] = meaning;
	}
}

void About(const string& country, map<string, string>& countries) {
	if (countries.count(country) == 0) cout << "Country " << country << " doesn't exist" << endl;
	else {
		cout << "Country " << country << " has capital " << countries[country] << endl;
	}
}

void Dump(const map<string, string>& countries) {
	if (countries.size() == 0) cout << "There are no countries in the world" << endl;
	else for (const auto& x : countries) cout << x.first << "/" << x.second << endl;
}

int main(){
	int rounds;
	cin >> rounds;

	string command;
	string optionOne;
	string optionTwo;

	map<string, string> countries;

	while (rounds--) {
		cin >> command;
		if (command == "CHANGE_CAPITAL") {
			cin >> optionOne >> optionTwo;
			ChangeCapital(optionOne, optionTwo, countries);
		}
		else if (command == "RENAME") {
			cin >> optionOne >> optionTwo;
			Rename(optionOne, optionTwo, countries);
		}
		else if (command == "ABOUT") {
			cin >> optionOne;
			About(optionOne, countries);
		}
		else if (command == "DUMP") {
			Dump(countries);
		}
	}
	return 0;
}
