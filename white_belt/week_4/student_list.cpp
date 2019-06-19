#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student{
    string name;
    string birth;
};

int main() {
    int n;
    cin >> n;
    vector<Student> students;
    for (int i = 0; i < n; ++i) {
        string name, surname, day, month, year;
        cin >> name >> surname >> day >> month >> year;
        students.push_back({name + " " + surname, day + "." + month + "." + year});
    }
    int q;
    cin >> q;
    string cmd;
    int index;
    for (int i = 0; i < q; ++i) {
        cin >> cmd >> index;
        --index;
        if (cmd == "name" && index >= 0 && index < students.size()) {
            cout << students[index].name << endl;
        } else if (cmd == "date" && index >= 0 && index < students.size()) {
            cout << students[index].birth << endl;
        } else {
            cout << "bad request" << endl;
        }
    }
    return 0;
}