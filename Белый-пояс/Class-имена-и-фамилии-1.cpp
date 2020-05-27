#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        if (dude.count(year) == 0) {
            dude[year] = {first_name, "0"};
        }
        else {
            dude[year].firstname = first_name;
        }
       
    }
    void ChangeLastName(int year, const string& last_name) {
        if (dude.count(year) == 0) {
            dude[year] = {"0", last_name };
        }
        else {
            dude[year].secondname = last_name;
        }
    }
    string GetFullName(int year) {
        string ret;
        first = "0";
        last = "0";
        for (const auto& x : dude) {
            if (x.first <= year) {
                if (x.second.firstname != "0") {
                    first = x.second.firstname;
                }
                if (x.second.secondname != "0") {
                    last = x.second.secondname;
                }
            }       
        }
        if (first != "0" && last == "0") {
            return first + " with unknown last name";
        }
        else if (last != "0" && first == "0") {
            return last + " with unknown first name";
        }
        else if (first != "0" && last != "0") {
            return first + " " + last;
        }
        return "Incognito";
    }
private:
    struct Year {
        string firstname;
        string secondname;
    };

    map<int, Year> dude;
    string first;
    string last;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
