#include <iostream>
#include <exception>
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
    friend Rational operator/(const Rational& first, const Rational& second) {
        if (second.Numerator() == 0) throw domain_error("domain_error");
        return Rational(first.numerator * second.denominator, first.denominator * second.numerator);
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
