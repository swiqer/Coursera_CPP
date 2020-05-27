#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

class Rational {
public:
    Rational() {
        firstNum = 0;
        secondNum = 1;
    }

    friend  bool operator==(const Rational& first, const Rational& second){
        return first.firstNum == second.firstNum && first.secondNum == second.secondNum;
    }
    friend Rational operator+(const Rational& first, const Rational& second){
        if(first.secondNum == second.secondNum)
            return Rational(first.firstNum + second.firstNum, first.secondNum);
        return Rational(first.firstNum + second.firstNum, first.secondNum + second.secondNum);
    }
    friend  Rational operator-(const Rational& first, const Rational& second){
        if(first.secondNum == second.secondNum)
            return Rational(first.firstNum - second.firstNum, second.firstNum);
        return Rational((first.firstNum * second.secondNum) - (second.firstNum * first.secondNum), (first.secondNum * second.secondNum));
    }
    friend  Rational operator*(const Rational& first, const Rational& second){
        return Rational(first.firstNum * second.firstNum, first.secondNum * second.secondNum);
    }
    friend Rational operator/(const Rational& first, const Rational& second){
        return Rational(first.firstNum * second.secondNum, first.secondNum * second.firstNum);
    }
    friend ostream& operator<<(ostream& stream, const Rational& rational){
        return stream << rational.firstNum << "/" << rational.secondNum;

    }
    friend istream& operator>>(istream & stream, Rational& r){
        int n, d;
        char c;
        stream >> n >> c >> d;
        if (stream && c == '/') {
            r = Rational(n, d);
        }
        return stream;
    }

    Rational(int numerator, int denominator) {
        int flag = 0;
        if (numerator < 0 && denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        else if (denominator < 0 && numerator > 0) {
            denominator *= -1;
            flag = 1;
        }
        else if (denominator > 0 && numerator < 0) {
            numerator *= -1;
            flag = 1;
        }
        else if (numerator == 0){
            denominator = 1;
        }

        int i = numerator;
        while (i > 0) {
            if (numerator % i == 0 && denominator % i == 0) {
                numerator /= i;
                denominator /= i;
                break;
            }
            i--;
        }
        if (flag == 1) firstNum = numerator * -1;
        else firstNum = numerator;
        secondNum = denominator;
    }

    int Numerator() const {
        return firstNum;
    }

    int Denominator() const {
        return secondNum;
    }

private:
    int firstNum ;
    int secondNum;
};
