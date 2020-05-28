#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
using namespace std;

struct Date {
	int Year;
	int Month;
	int Day;
};

bool operator<(const Date& one, const Date& two) {
	return tie(one.Year, one.Month, one.Day) < tie(two.Year, two.Month, two.Day);
}

int main() {
	Date one = { 2020, 05, 28 };
	Date two = { 2020, 06, 18 };
	cout << (one < two) << endl;
	
	tuple t("Kirill", "Kuzmin", 19);
	cout << "Name: " << get<0>(t) << endl;
	cout << "Surname: " << get<1>(t) << endl;
	cout << "Year: " << get<2>(t) << endl;

	map<int, string> digits = { {1, "one"}, {2, "two"} };
	for (const auto& [key, value] : digits) {
		cout << key << " : " << value << endl;
	}

	return 0;
}
