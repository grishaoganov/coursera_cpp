#include <iostream>
#include <sstream>
#include <string>
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
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
