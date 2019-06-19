#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    sort(begin(numbers), end(numbers), [](int a, int b){
        return abs(a) < abs(b);
    });
    for (const auto& i : numbers) {
        cout << i << ' ';
    }
    return 0;
}