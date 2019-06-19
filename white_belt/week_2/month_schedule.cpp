#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;
    string cmd;
    int current_month = 0;
    vector<int> day_count = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> month (day_count[current_month]);

    for (int i = 0; i < q; ++i){
        cin >> cmd;
        if (cmd == "ADD") {
            int day;
            string task;
            cin >> day >> task;
            month[day - 1].push_back(task);
        } else if (cmd == "DUMP") {
            int day;
            cin >> day;
            if (month[day - 1].size() == 0) {
                cout << 0 << endl;
            } else {
                cout << month[day - 1].size() << ' ';
                for (int i = 0; i < month[day - 1].size(); ++i){
                    if (i != month[day - 1].size() - 1)
                        cout << month[day - 1][i] << ' ';
                    else
                        cout << month[day - 1][i] << endl;
                }
            }
        } else if (cmd == "NEXT") {
            int prev_month = current_month;
            if (current_month < 11) {
                ++current_month;
            } else {
                current_month = 0;
            }

            if (day_count[prev_month] > day_count[current_month]) {
                int dif = day_count[prev_month] - day_count[current_month];
                for (int i = month.size() - dif; i < month.size(); ++i) {
                    month[month.size() - 1 - dif].insert(end(month[month.size() - 1 - dif]), begin(month[i]), end(month[i]));
                }
                month.resize(day_count[current_month]);
            } else if (day_count[prev_month] < day_count[current_month]) {
                month.resize(day_count[current_month]);
            }
        }
    }
    return 0;
}