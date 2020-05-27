#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;


int main() {
	int rounds;
	cin >> rounds;	
	string first_word, second_word;
	string command;
	map<string, set<string>> synonyms;

	while (rounds--) {
		cin >> command;

		if (command == "ADD") {
			cin >> first_word >> second_word;
			synonyms[second_word].insert(first_word);
			synonyms[first_word].insert(second_word);
		}
		else if (command == "COUNT") {
			cin >> first_word;
			cout << synonyms[first_word].size() << endl;
		}
		else if (command == "CHECK") {
			cin >> first_word >> second_word;
			if (synonyms[first_word].count(second_word) == 1) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
