#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("input.txt");
    int n, m;
    if (input) {
        input >> n;
        input.ignore(1);
        input >> m;
        int item;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                input >> item;
                input.ignore(1);
                if (j != m - 1){
                    cout << setw(10);
                    cout << item << ' ';
                } else {
                    cout << setw(10);
                    cout << item << endl;
                }
            }
        }
    }
    return 0;
}