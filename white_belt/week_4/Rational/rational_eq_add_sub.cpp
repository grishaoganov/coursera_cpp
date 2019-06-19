#include <iostream>
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

bool operator ==(const Rational& lhv, const Rational& rhv){
    return lhv.Denominator() == rhv.Denominator() && lhv.Numerator() == rhv.Numerator();
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

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
