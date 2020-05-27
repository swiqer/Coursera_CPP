#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int N, M;
	int s;
	vector<vector<int>> nums;
	ifstream input("input.txt");
	if (input) {
		input >> N >> M;
		for(int i = 1; i <= N; i++) {
			vector<int> save;
			for(int z = 1; z <= M; z++){
				input >> s;
				save.push_back(s);
				input.ignore(1);
			}
			nums.push_back(save);
			save.clear();
			
		}
	}
	int n = N;
	for (const auto& x : nums) {
		int m = M;
		for (const auto& z : x) {
			cout << setw(10) << z;
			if (m > 1) {
				cout << " ";
			}
			m--;
		}
		if (n > 1) {
			cout << endl;
		}
		n--;
	}
	return 0;
}
