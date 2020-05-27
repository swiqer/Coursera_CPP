#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool BuildCharCounters(const string& str1, const string& str2) {
	map<char, int> first;
	map<char, int> second;
	for (const char& x : str1) ++first[x];
	for (const char& x : str2) ++second[x];
	if (second == first) return true;
	return false;
}

int main(){
	int rounds;
	cin >> rounds;

	string first;
	string second;
	bool result;
	while (rounds--) {
		cin >> first >> second;
		result = BuildCharCounters(first, second);
		if (result == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
