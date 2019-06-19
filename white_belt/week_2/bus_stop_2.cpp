#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    int q;
    cin >> q;
    map<vector<string>, int> buses;
    for (int i = 0; i < q; ++i) {
        int n;
        cin >> n;
        vector<string> path;
        for (int j = 0; j < n; ++j) {
            string stop;
            cin >> stop;
            path.push_back(stop);
        }
        if (buses.count(path) == 0) {
            int size = buses.size();
            buses[path] = size + 1;
            cout << "New bus " << buses[path] << endl;
        } else {
            cout << "Already exists for " << buses[path] << endl;
        }
    }
    return 0;
}