#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int count = 0;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'f') {
            ++count;
            if (count == 2) {
                cout << i;
                break;
            }
        }
    }
    if (count == 1) {
        cout << -1;
    } else if (count == 0) {
        cout << -2;
    }
    return 0;
}