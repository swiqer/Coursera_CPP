#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <set>
using namespace std;

struct Block {
	uint64_t x = 0;
	uint64_t y = 0;
	uint64_t z = 0;
};

int main() {
	int i = 0;
	uint64_t mas = 0;

	cin >> i >> mas;
	uint64_t sum = 0;
	while (i != 0) {
		Block block;
		cin >> block.x >> block.y >> block.z;
		sum += block.x * block.y * block.z * mas;
		i--;
	}
	cout << sum << endl;
	return 0;
}
