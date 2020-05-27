#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <exception>
#include <sstream>
#include <algorithm>
using namespace std;

// Реализуйте функции и методы классов и при необходимости добавьте свои

string appendZero(const int& maxZero, const int& number, const int& flag) {
    int size = to_string(number).size();
    int i = maxZero - size;
    string result = "";
    if (i > 0) {
        while (i != 0) {
            result += "0";
            i--;
        }
    }
    result += to_string(number);
    if (flag == 1) {
        result += "-";
    }
    else {
        result += " ";
    }
    return result;
}

class Date {
public:
    Date(string date) {
        istringstream iss(date, istringstream::in);
        iss >> Year;
        iss.ignore(1);
        iss >> Month;
        if (Month > 12 || Month < 1) {
            throw invalid_argument("Month value is invalid : " + to_string(Month));
        }
        iss.ignore(1);
        iss >> Day;
        if(Day)
        if (Day > 31 || Day < 1) {
            throw invalid_argument("Day value is invalid: " + to_string(Day));
        }

    }

    Date(int y, int m, int d) {
        Year = y;
        Month = m;
        Day = d;
    }

    int GetYear() const {
        return Year;
    }
    int GetMonth() const {
        return Month;
    }
    int GetDay() const {
        return Day;
    }

private:
    int Year;
    int Month;
    int Day;
};


bool operator<(const Date& first, const Date& second) {
    if (first.GetDay() != second.GetDay()) {
        return (first.GetDay() - second.GetDay()) < 0;
    }
    else if (first.GetDay() == second.GetDay() && first.GetMonth() != second.GetMonth()) {
        return (first.GetMonth() - second.GetMonth()) < 0;
    }
    return (first.GetYear() - second.GetYear()) < 0;
}

class Database {
public:
    
    void AddEvent(const Date& date, const string& event) {
        dateEvent[date].push_back(event);
        sort(dateEvent[date].begin(), dateEvent[date].end());
        dateEvent[date].erase(unique(dateEvent[date].begin(), dateEvent[date].end()), dateEvent[date].end());
    }
    /*bool DeleteEvent(const Date& date, const string& event) {

    }*/
    //int  DeleteDate(const Date& date);*/

    void Find(const Date& date) const {
        if (dateEvent.count(date) > 0) {
            for(const auto& event : dateEvent.at(date)){
                cout << event << endl;
            }
        }
    }

    void Print() const {
        for (const auto& day : dateEvent) {
            string y = appendZero(4, day.first.GetYear(), 1);
            string m = appendZero(2, day.first.GetMonth(), 1);
            string d = appendZero(2, day.first.GetDay(), 0);
            for (const auto ev : day.second) {
                cout << y << m << d << ev << endl;
            }
        }
    }


    // не нужно включать в итоговый кдасс
    /*map<Date, vector<string>> returnDatabase() {
        return dateEvent;
    }*/

private:
    map<Date, vector<string>> dateEvent;
};

int main() {
    Database db;

    string command;
    //while (getline(cin, command)) {
    try {
        while (1) {
            cin >> command;

            if (command == "Add") {
                try {
                    string date;
                    cin >> date;
                    Date d = date;

                    string event;
                    cin >> event;
                    //cout << d.GetDay() << "." << d.GetMonth() << "." << d.GetYear() << " - " << event << endl;
                    db.AddEvent(d, event);
                    /*for (const auto day : db.returnDatabase()) {
                        cout << day.first.GetDay() << "." << day.first.GetMonth() << "." << day.first.GetYear() << " ";
                        for (const auto event : day.second) {
                            cout << event << " ";
                        }
                    }
                    cout << endl;*/
                }
                catch (exception& e) {
                    cout << e.what() << endl;
                    return 0;
                }

            }
            else if (command == "Del") {
                string date;
                cin >> date;
                Date d = date;

                string event;
            }
            else if (command == "Find") {
                string date;
                cin >> date;
                Date d = date;
                db.Find(d);

            }
            else if (command == "Print") {
                db.Print();
            }
            else {
                cout << "Unknown command: " + command;
                return 0;
            }
        }
    }
    catch (exception&) {
        cout << "Unknown signal 6";
        return 0;
    }
    return 0;
}
