#include <iostream>
#include <exception>
using namespace std;

class Rational {
public:
    Rational() {
        _numerator = 0;
        _denominator = 1;
    }

    Rational(int numerator, int denominator) {
        if (numerator == 0) {
            _numerator = 0;
            _denominator = 1;
        } else if (denominator == 0) {
            throw invalid_argument("Invalid argument");
        } else {
            int a = numerator > 0 ? numerator : -1 * numerator;
            int b = denominator > 0 ? denominator : -1 * denominator;
            while (a > 0 && b > 0) {
                if (a > b) {
                    a %= b;
                } else {
                    b %= a;
                }
            }
            int d = a + b;
            numerator /= d;
            denominator /= d;
            if ((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0)){
                _numerator = -1 * numerator;
                _denominator = -1 * denominator;
            } else {
                _numerator = numerator;
                _denominator = denominator;
            }
        }
    }

    int Numerator() const {
        return _numerator;
    }

    int Denominator() const {
        return _denominator;
    }

private:
    int _numerator;
    int _denominator;
};

Rational operator /(const Rational& lhv, const Rational& rhv){
    if (rhv.Numerator() == 0)
        throw domain_error("Division by zero");
    return {lhv.Numerator() * rhv.Denominator(), lhv.Denominator() * rhv.Numerator()};
}

bool operator ==(const Rational& lhv, const Rational& rhv){
    return lhv.Denominator() == rhv.Denominator() && lhv.Numerator() == rhv.Numerator();
}

Rational operator *(const Rational& lhv, const Rational& rhv){
    return {lhv.Numerator() * rhv.Numerator(), lhv.Denominator() * rhv.Denominator()};
}

Rational operator +(const Rational& lhv, const Rational& rhv){
    if (lhv.Denominator() == rhv.Denominator()) {
        return {lhv.Numerator() + rhv.Numerator(), lhv.Denominator()};
    } else {
        int a = lhv.Denominator();
        int b = rhv.Denominator();
        while (a > 0 && b > 0) {
            if (a > b) {
                a %= b;
            } else {
                b %= a;
            }
        }
        int d = a + b;
        int k = (lhv.Denominator() * rhv.Denominator()) / d;
        return {lhv.Numerator() * (k / lhv.Denominator()) + rhv.Numerator() * (k / rhv.Denominator()), k};
    }
}

Rational operator -(const Rational& lhv, const Rational& rhv) {
    if (lhv.Denominator() == rhv.Denominator()) {
        return {lhv.Numerator() - rhv.Numerator(), lhv.Denominator()};
    } else {
        int a = lhv.Denominator();
        int b = rhv.Denominator();
        while (a > 0 && b > 0) {
            if (a > b) {
                a %= b;
            } else {
                b %= a;
            }
        }
        int d = a + b;
        int k = (lhv.Denominator() * rhv.Denominator()) / d;
        return {lhv.Numerator() * (k / lhv.Denominator()) - rhv.Numerator() * (k / rhv.Denominator()), k};
    }
}

ostream& operator <<(ostream& stream, const Rational& rhv){
    return stream << rhv.Numerator() << "/" << rhv.Denominator();
}

istream& operator >>(istream& stream, Rational& rhv){
    int n, d;
    char c;
    stream >> n >> c >> d;
    if (stream && c == '/') {
        rhv = Rational(n, d);
    }
    return stream;
}

int main() {
    Rational r1, r2;
    char operation;
    try {
        cin >> r1 >> operation >> r2;
        if (operation == '+'){
            cout << r1 + r2;
        } else if (operation == '-') {
            cout << r1 - r2;
        } else if (operation == '*') {
            cout << r1 * r2;
        } else if (operation == '/') {
            cout << r1 / r2;
        }
    } catch (invalid_argument& ex) {
        cout << ex.what();
    } catch (domain_error& ex) {
        cout << ex.what();
    }
    return 0;
}