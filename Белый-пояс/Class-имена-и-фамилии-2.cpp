#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Person {
public:

    void ChangeFirstName(int year, const string& first_name) {
        if (dude.count(year) == 0) {
            dude[year] = { first_name, "0" };
        }
        else {
            dude[year].firstname = first_name;
        }

    }

    void ChangeLastName(int year, const string& last_name) {
        if (dude.count(year) == 0) {
            dude[year] = { "0", last_name };
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

    string GetFullNameWithHistory(int year) {
        string ret;
        first = "0";
        last = "0";
        vector<string> changedFist;
        vector<string> changedSecond;

        for (auto& x : dude) {
            if (x.first <= year && x.second.firstname != "0") {
                first = x.second.firstname;
                if (x.first != year) {
                    changedFist.emplace(changedFist.begin(), first);
                }
            }
            if (x.first <= year && x.second.secondname != "0") {
                last = x.second.secondname;
                if (x.first != year) {
                    changedSecond.emplace(changedSecond.begin(), last);
                }
            }
        }

        if (!changedFist.empty()) {
            changedFist.erase(unique(changedFist.begin(), changedFist.end()), changedFist.end());
        }
        if (!changedFist.empty() && first == changedFist[0]) {
            changedFist.erase(changedFist.begin());
        }

        if (!changedSecond.empty()) {
            changedSecond.erase(unique(changedSecond.begin(), changedSecond.end()), changedSecond.end());
        }
        if (!changedSecond.empty() && last == changedSecond[0]) {
            changedSecond.erase(changedSecond.begin());
        }

        int changedFirstSize = changedFist.size();
        int changedSecondSize = changedSecond.size();
        if (first != "0" && last == "0") {
            if (changedFirstSize != 0) {
                int s = changedFirstSize;
                ret = first + " (";
                for (const auto& x : changedFist) {
                    ret += x;
                    s--;
                    if (s != 0) {
                        ret += ", ";
                    }
                    else {
                        ret += ") ";
                    }
                }
                ret += "with unknown last name";
                return ret;
            }
            return first + " with unknown last name";
        }
        else if (last != "0" && first == "0") {
            int flag = 0;
            if (changedSecondSize > 0) {
                int s = changedSecondSize;
                ret = last + " (";
                for (const auto& x : changedSecond) {
                    ret += x;
                    s--;
                    if (s != 0) {
                        ret += ", ";
                    }
                    else {
                        ret += ") ";
                    }
                }
                ret += "with unknown first name";
                return ret;
            }
            return last + " with unknown first name";
        }
        else if (first != "0" && last != "0") {
            if (changedFirstSize > 0 || changedSecondSize > 0) {
                ret = first;
                if (changedFirstSize != 0) {
                    int s = changedFirstSize;
                    ret += " (";
                    for (const auto& x : changedFist) {
                        ret += x;
                        s--;
                        if (s != 0) {
                            ret += ", ";
                        }
                        else {
                            ret += ")";
                        }
                    }
                    ret += " ";
                }
                else {
                    ret += " ";
                }
                ret += last;
                if (changedSecondSize != 0) {
                    int s = changedSecondSize;
                    ret += " (";
                    for (const auto& x : changedSecond) {
                        ret += x;
                        s--;
                        if (s != 0) {
                            ret += ", ";
                        }
                        else {
                            ret += ")";
                        }
                    }
                }
                return ret;
            }
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
    string saveFirst;
    string saveSecond;
};
