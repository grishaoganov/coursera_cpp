#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("input.txt");
    if (input) {
        cout << fixed << setprecision(3);
        double number;
        while (input >> number) {
            cout << number << endl;
        }
    }
    return 0;
}