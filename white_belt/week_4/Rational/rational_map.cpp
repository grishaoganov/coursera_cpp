#include <iostream>
#include <map>
#include <set>
#include <vector>
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

bool operator <(const Rational& lhv, const Rational& rhv){
    if (lhv.Denominator() == rhv.Denominator()) {
        return lhv.Numerator() < rhv.Numerator();
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
        return lhv.Numerator() * (k / lhv.Denominator()) < rhv.Numerator() * (k / rhv.Denominator());
    }
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
