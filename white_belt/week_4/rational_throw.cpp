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
            throw invalid_argument("Error!");
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
        throw domain_error("Error!");
    return {lhv.Numerator() * rhv.Denominator(), lhv.Denominator() * rhv.Numerator()};
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
