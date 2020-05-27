#include <iostream>
#include <exception>
#include <sstream>
using namespace std;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return GCD(b, a % b);
    }
}

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    friend  bool operator==(const Rational& first, const Rational& second) {
        return first.Numerator() == second.Numerator() && first.Denominator() == second.Denominator();
    }
    friend Rational operator+(const Rational& first, const Rational& second) {
        int p = (first.Numerator() * second.Denominator()) + (second.Numerator() * first.Denominator());
        int q = first.Denominator() * second.Denominator();
        return { p, q };
    }
    friend  Rational operator-(const Rational& first, const Rational& second) {
        int p = (first.Numerator() * second.Denominator()) - (second.Numerator() * first.Denominator());
        int q = first.Denominator() * second.Denominator();
        return { p, q };
    }

    friend  Rational operator*(const Rational& first, const Rational& second) {
        return Rational(first.Numerator() * second.Numerator(), first.Denominator() * second.Denominator());
    }

    friend Rational operator/(const Rational& first, const Rational& second) {
        if (second.Numerator() == 0) throw domain_error("Division by zero");
        return Rational(first.Numerator() * second.Denominator(), first.Denominator() * second.Numerator());
    }

    friend ostream& operator<<(ostream& stream, const Rational& rational) {
        return stream << rational.numerator << "/" << rational.denominator;

    }
    friend istream& operator>>(istream& stream, Rational& r) {
        int n, d;
        char c;
        stream >> n >> c >> d;
        if (stream && c == '/') {
            r = Rational(n, d);
        }
        return stream;
    }

    Rational(int new_numerator, int new_denominator) {
        if (new_denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
        const int gcd = GCD(new_numerator, new_denominator);
        numerator = new_numerator / gcd;
        denominator = new_denominator / gcd;
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

int main() {
    try {
        string input;
        cin >> input;
        istringstream iss(input, istringstream::in);
        Rational r1;
        iss >> r1;
    

        string omen;
        cin >> omen;

        string input2;
        cin >> input2;
        istringstream iss2(input2, istringstream::in);
        Rational r2;
        iss2 >> r2;
        if (omen == "/") {
            cout << r1 / r2;
        }
        else if (omen == "*") {
            cout << r1 * r2;
        }
        else if (omen == "+") {
            cout << r1 + r2;
        }
        else if (omen == "-") {
            cout << r1 - r2;
        }
    }
    catch (exception& ex) {
        cout << ex.what();
    }
    return 0;
}
