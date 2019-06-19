#include <iostream>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> strings;
    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        strings.push_back(a);
    }

    /**
     * My solution
     **/

    sort(begin(strings), end(strings), [](string a, string b){
        if (a.size() == b.size()) {
            for (int i = 0; i < a.size(); ++i) {
                if (tolower(a[i]) > tolower(b[i])) {
                    return false;
                }
                else if (tolower(a[i]) < tolower(b[i])) {
                    return true;
                }
            }
            return false;
        } else {
            return a.size() < b.size();
        }
    });

    /**
     * Alternative solution
    sort(begin(strings), end(strings),
            // компаратор для сортировки — лямбда-функция, сравнивающая строки без учёта регистра
         [](const string& l, const string& r) {
             // сравниваем лексикографически...
             return lexicographical_compare(
                     // ... все символы строки l ...
                     begin(l), end(l),
                     // ... со всеми символами строки r ...
                     begin(r), end(r),
                     // ..., используя в качестве компаратора сравнение отдельных символов без учёта регистра
                     [](char cl, char cr) { return tolower(cl) < tolower(cr); }
             );
         }
    );
    **/

    for (const auto& i : strings) {
        cout << i << ' ';
    }
    return 0;
}