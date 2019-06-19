#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    if ((a != 0 && b == 0 && c == 0) || (a == 0 && b != 0 && c == 0)){
        cout << 0;
    } else if (b != 0 && a == 0 && c != 0) {
        cout << -c / b;
    } else if (b != 0 && a != 0 && c == 0) {
        cout << 0 << ' ' << -b / a;
    } else if ((b == 0 && a > 0 && c < 0) || (b == 0 && a < 0 && c > 0)) {
        cout << sqrt(-c / a) << ' ' << -1 * sqrt(-c / a);
    } else if (b != 0 && a != 0 && c != 0) {
        double d = sqrt(b * b - 4 * a * c);
        if (d > 0){
            cout << (-b + d) / (2 * a) << ' ' << (-b - d) / (2 * a);
        } else if (d == 0) {
            cout << -b / (2 * a);
        }
    }
    return 0;
}