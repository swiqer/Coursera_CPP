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
        /*stringstream iss(date);
        string save;
        iss >> Year;
        if (iss.peek() != '-') {
            throw invalid_argument("Wrong date format: " + date);
        }
        iss.ignore(1);
        iss >> Month;
        /*if (Month > 12 || Month < 1) {
            throw invalid_argument("Month value is invalid: " + to_string(Month));
        }
        if (iss.peek() != '-') {
            throw invalid_argument("Wrong date format: " + date);
        }
        iss.ignore(1);
        iss >> Day;
        
        if (!iss.eof()) {
            string s;
            iss >> s;
            throw invalid_argument("Wrong date format: " + date);
        }
        if (Month > 12 || Month < 1) {
            throw invalid_argument("Month value is invalid: " + to_string(Month));
        }
        if (Day > 31 || Day < 1) {
            throw invalid_argument("Day value is invalid: " + to_string(Day));
        }*/
        istringstream date_stream(date);
        bool flag = true;

        int year;
        flag = flag && (date_stream >> year);
        flag = flag && (date_stream.peek() == '-');
        date_stream.ignore(1);

        int month;
        flag = flag && (date_stream >> month);
        flag = flag && (date_stream.peek() == '-');
        date_stream.ignore(1);

        int day;
        flag = flag && (date_stream >> day);
        flag = flag && date_stream.eof();

        if (!flag)
        {
            throw logic_error("Wrong date format: " + date);
        }
        if (month > 12 || month < 1) {
            throw invalid_argument("Month value is invalid: " + to_string(month));
        }
        if (day > 31 || day < 1) {
            throw invalid_argument("Day value is invalid: " + to_string(day));
        }
        Year = year;
        Month = month;
        Day = day;
    }

    Date() {
        Year = 0;
        Month = 0;
        Day = 0;
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
    if (first.GetYear() != second.GetYear()) {
        return (first.GetYear() - second.GetYear()) < 0;
    }
    else if (first.GetDay() == second.GetDay() && first.GetMonth() != second.GetMonth()) {
        return (first.GetMonth() - second.GetMonth()) < 0;
    }
    else {
        return (first.GetDay() - second.GetDay()) < 0;
    }
}

class Database {
public:

    void AddEvent(const Date& date, const string& event) {
        dateEvent[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (dateEvent.count(date)) {
            if (dateEvent[date].count(event)) {
                dateEvent[date].erase(event);
                return true;
            }
        }
        return false;
    }
    int  DeleteDate(const Date& date) {
        if (dateEvent.count(date)) {
            int size = dateEvent[date].size();
            dateEvent.erase(date);
            return size;
        }
        return 0;
    }

    void Find(const Date& date) const {
        if (dateEvent.count(date) > 0) {
            for (const auto& event : dateEvent.at(date)) {
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

private:
    map<Date, set<string>> dateEvent;
};

int main() {
    Database db;

    string command;
    try {
        while (getline(cin, command)) {
            string com;
            stringstream stream(command);
            string event;
            Date d;
            string date;
            if (stream >> com) {
                if (com == "Add") {
                    try {
                        stream >> date;
                        d = date;
                        stream >> event;
                        db.AddEvent(d, event);
                    }
                    catch (exception& ia) {
                        cout << ia.what() << endl;
                        return 0;
                    }

                }
                else if (com == "Del") {
                    if (stream >> date) {
                        try {
                            d = date;
                        }
                        catch (exception& ia) {
                            cout << ia.what() << endl;
                            return 0;
                        }
                        if (stream >> event) {
                            if (db.DeleteEvent(d, event)) {
                                cout << "Deleted successfully" << endl;
                            }
                            else {
                                cout << "Event not found" << endl;
                            }
                        }
                        else {
                            cout << "Deleted " << db.DeleteDate(d) << " events" << endl;
                        }
                    }
                }
                else if (com == "Find") {
                    stream >> date;
                    try {
                        d = date;
                    }
                    catch (exception& ia) {
                        cout << ia.what() << endl;
                        return 0;
                    }
                    db.Find(d);

                }
                else if (com == "Print") {
                    db.Print();
                }
                /*else if (com == "cls") {
                    system("cls");
                }
                else if (com == "exit") {
                    return 0;
                }*/
                else {
                    cout << "Unknown command: " + command;
                    return 0;
                }
            }
        }
    }
    catch (exception& ex) {
        cout << ex.what();
        return 0;
    }
    return 0;
}
