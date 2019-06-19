#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
    } else {
        vector<int> res;
        while (n > 1) {
            res.push_back(n % 2);
            n /= 2;
        }
        res.push_back(1);
        for (int i = res.size() - 1; i >= 0; --i) {
            cout << res[i];
        }
    }
    return 0;
}