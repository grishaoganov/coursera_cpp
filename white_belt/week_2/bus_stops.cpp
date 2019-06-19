#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<string> stops_for_buses(map<string, vector<string>>& stops, const string& stop, const string& bus){
    vector<string> result;
    for (const auto& s : stops[stop]) {
        if (s != bus) {
            result.push_back(s);
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    map<string, vector<string>> buses;
    map<string, vector<string>> stops;
    for (int i = 0; i < n; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "NEW_BUS") {
            string bus;
            int stop_count;
            cin >> bus >> stop_count;
            for (int j = 0; j < stop_count; ++j) {
                string stop;
                cin >> stop;
                stops[stop].push_back(bus);
                buses[bus].push_back(stop);
            }
        } else if (cmd == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            if (stops.count(stop) != 0) {
                for (const auto& item : stops[stop]) {
                    cout << item << ' ';
                }
                cout << endl;
            } else {
                cout << "No stop" << endl;
            }
        } else if (cmd == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            if (buses.count(bus) != 0) {
                for (const auto& item : buses[bus]) {
                    if (!stops_for_buses(stops, item, bus).empty()) {
                        cout << "Stop " << item << ": ";
                        for (const auto& s : stops_for_buses(stops, item, bus)) {
                            cout << s << ' ';
                        }
                        cout << endl;
                    } else {
                        cout << "Stop " << item << ": no interchange" << endl;
                    }
                }
            } else {
                cout << "No bus" << endl;
            }
        } else if (cmd == "ALL_BUSES") {
            if (!buses.empty()) {
                for (const auto& item : buses) {
                    cout << "Bus " << item.first << ": ";
                    for (const string& s : item.second) {
                        cout << s << ' ';
                    }
                    cout << endl;
                }
            } else {
                cout << "No buses" << endl;
            }
        }
    }
    return 0;
}