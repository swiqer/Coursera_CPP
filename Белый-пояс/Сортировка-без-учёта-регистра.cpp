#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string ToLower(string s) {
    string lowerString;
    for (auto& z : s) lowerString += tolower(z);
    return lowerString;
}
int main() {
    int rounds;
    string simbls;
    cin >> rounds;
    vector<string> v;
    while(rounds--){cin >> simbls; v.push_back(simbls);}
    sort(begin(v), end(v), [](const string& x, const string& y) {return ToLower(x) < ToLower(y); });
    for (const auto& i : v) cout << i << " ";
    return 0;
}
