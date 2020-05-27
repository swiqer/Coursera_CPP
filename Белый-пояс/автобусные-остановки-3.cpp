#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;


int main() {
	int rounds;
	cin >> rounds;	
	int x = 1;
	map<int, set<string>> buses;
	set<string> save;
	int flag = 0;

	while (rounds--) {
		int i;
		flag = 0;
		cin >> i;
		string stop;
		while (i--) {
			cin >> stop;
			save.insert(stop);
		}
		for(auto& x : buses){
			if (x.second == save) {
				cout << "Already exists for " << x.first << endl;
				flag = 1;
			}
		}
		if (flag == 0) {
			buses[x] = save;
			cout << "New bus " << x << endl;
			x++;
		}
		save.clear();
	}
	return 0;
}
