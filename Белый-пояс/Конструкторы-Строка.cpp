#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class  ReversibleString {
public:
    ReversibleString() {};
    ReversibleString(const string& word){
        w = word;
    };

    void Reverse() {
        reverse(w.begin(), w.end());
    }
    string ToString() const{
        return w;
    }
private:
    string w;
};
