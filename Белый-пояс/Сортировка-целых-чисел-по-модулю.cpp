#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int rounds, num;
    cin >> rounds;
    vector<int> v;
    while(rounds--){cin >> num; v.push_back(num);}
    sort(begin(v), end(v), [](const int& x, const int& y) {return abs(x) < abs(y);});
    for (const auto& i : v) cout << i << " ";
    return 0;
}
