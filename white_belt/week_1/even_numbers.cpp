#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a % 2 == 0) {
        while (a <= b) {
            cout << a;
            cout << ' ';
            a += 2;
        }
    } else {
        ++a;
        while (a <= b) {
            cout << a;
            cout << ' ';
            a += 2;
        }
    }
    return 0;
}