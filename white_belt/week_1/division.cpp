#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a < b) {
        cout << 0;
    } else if (b == 0) {
        cout << "Impossible";
    } else {
        cout << a / b;
    }
    return 0;
}