#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char, int> BuildCharCounters(const string& s){
    map<char, int> result;
    for (const char& c : s) {
        ++result[c];
    }
    return result;
}

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
       string a, b;
       cin >> a >> b;
       if (BuildCharCounters(a) == BuildCharCounters(b))
           cout << "YES" << endl;
       else
           cout << "NO" << endl;
    }
    return 0;
}