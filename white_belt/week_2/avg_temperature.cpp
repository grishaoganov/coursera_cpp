#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int sum = 0;
    cin >> n;
    vector<int> temperatures(n);
    int temperature;
    for (int i = 0; i < n; ++i){
        cin >> temperature;
        temperatures[i] = temperature;
        sum += temperature;
    }
    int mean = sum / n;
    vector<int> indexes;
    int count;
    for (int i = 0; i < n; ++i) {
        if (temperatures[i] > mean){
            ++count;
            indexes.push_back(i);
        }
    }

    cout << count << endl;
    for (auto item : indexes){
        cout << item << ' ';
    }
    return 0;
}