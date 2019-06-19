#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, string> capitals;
    for (int i = 0; i < n; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "CHANGE_CAPITAL") {
            string new_capital, country;
            cin >> country >> new_capital;
            if (capitals.count(country) == 0){
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
                capitals[country] = new_capital;
            } else if (capitals[country] == new_capital) {
                cout << "Country " << country << " hasn't changed its capital" << endl;
            } else {
                cout << "Country " << country << " has changed its capital from " << capitals[country] << " to " << new_capital << endl;
                capitals[country] = new_capital;
            }
        } else if (cmd == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (old_country_name == new_country_name || capitals.count(old_country_name) == 0 || capitals.count(new_country_name) != 0) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                cout << "Country " << old_country_name << " with capital " << capitals[old_country_name] << " has been renamed to " << new_country_name << endl;
                capitals[new_country_name] = capitals[old_country_name];
                capitals.erase(old_country_name);
            }
        } else if (cmd == "ABOUT") {
            string country;
            cin >> country;
            if (capitals.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
                capitals.erase(country);
            } else {
                cout << "Country " << country << " has capital " << capitals[country] << endl;
            }
        } else if (cmd == "DUMP") {
            if (capitals.size() == 0) {
                cout << "There are no countries in the world" << endl;
            } else {
                for (const auto& c : capitals) {
                    cout << c.first << "/" <<  c.second << ' ';
                }
            }
        }
    }
    return 0;
}