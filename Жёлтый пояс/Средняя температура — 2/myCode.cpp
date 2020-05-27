#include <iostream>
#include <vector>
#include <string>
#include <limits>
//#include <cstdint>
using namespace std;

int main() {
	unsigned int i = 0;
	cin >> i;
	unsigned m = i;
	vector<int64_t> numbers;
	while (i != 0) {
		int num = 0;
		cin >> num;
		numbers.push_back(num);
		i--;
	}
	int64_t sum = 0;
	for (const auto i : numbers) {
		sum += i;
	}
	int64_t s = sum / m;
	int size = 0;
	vector<int64_t> newNumbers;
	for (const auto& i : numbers) {
		if (i > s) {
			size++;
		}
	}
	cout << size << endl;
	size = 0;
	for (const auto& i : numbers) {
		if (i > s) {
			cout << size << " ";
		}
		size++;
	}
	cout << endl;
	return 0;
}
