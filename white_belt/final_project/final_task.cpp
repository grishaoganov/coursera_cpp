#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <set>
#include <exception>
#include <sstream>
using namespace std;

class Date {
public:
    Date() = default;
    Date(int new_year, int new_month, int new_day){
        if (new_month < 1 || new_month > 12)
            throw invalid_argument("Month value is invalid: " + to_string(new_month));
        if (new_day < 1 || new_day > 31)
            throw invalid_argument("Day value is invalid: " + to_string(new_day));
        year = new_year;
        month = new_month;
        day = new_day;
    }
    int Year() const{
        return year;
    }
    int Month() const{
        return month;
    }
    int Day() const{
        return day;
    }
private:
    int year;
    int month;
    int day;
};

istream& operator >>(istream& stream, Date& data){
    string line;
    stream >> line;
    stringstream tmp (line);
    int y, m, d;
    char c1, c2;
    if (tmp >> y >> c1 >> m >> c2 >> d && tmp.peek() == EOF && c1=='-' && c2=='-') {
        data = {y, m, d};
    } else {
        throw invalid_argument("Wrong date format: " + line);
    }
    return stream;
}

ostream& operator <<(ostream& stream, const Date& data){
    return stream << setw(4) << setfill('0') << data.Year()
    << "-" << setw(2) << setfill('0') << data.Month()
    << "-" << setw(2) << setfill('0') << data.Day();
}

bool operator <(const Date& lhv, const Date& rhv){
    if (lhv.Year() == rhv.Year()) {
        if (lhv.Month() == rhv.Month()) {
            return lhv.Day() < rhv.Day();
        } else {
            return lhv.Month() < rhv.Month();
        }
    } else {
        return lhv.Year() < rhv.Year();
    }
}

bool operator ==(const Date& lhv, const Date& rhv){
    return lhv.Year() == rhv.Year() && lhv.Month() == rhv.Month() && lhv.Day() == rhv.Day();
}

int main() {
    map<Date, set<string>> events;
    try {
        string line;
        while(getline(cin, line)){
            stringstream stream;
            if (line.empty())
                continue;
            stream << line;
            string cmd;
            stream >> cmd;
            if (cmd == "Add") {
                Date data;
                string event;
                stream >> data >> event;
                events[data].insert(event);
            } else if (cmd == "Del") {
                Date data;
                stream >> data;
                if (stream.peek() == EOF) {
                    if (events.count(data) == 0){
                        cout << "Deleted 0 events" << endl;
                    } else {
                        int count = events[data].size();
                        events.erase(data);
                        cout << "Deleted " << to_string(count) << " events" << endl;
                    }
                } else {
                    string event;
                    stream >> event;
                    if (events.count(data) == 0 || events[data].count(event) == 0) {
                        cout << "Event not found" << endl;
                    } else {
                        events[data].erase(event);
                        cout << "Deleted successfully" << endl;
                    }
                }
            } else if (cmd == "Find") {
                Date data;
                stream >> data;
                if (events.count(data) != 0) {
                    for (const string& item : events[data]) {
                        cout << item << endl;
                    }
                }
            } else if (cmd == "Print") {
                for (const auto& e : events) {
                    for (const string& item : e.second) {
                        cout << e.first << ' ' << item << endl;
                    }
                }
            } else {
                throw invalid_argument("Unknown command: " + cmd);
            }
        }
    } catch (invalid_argument& ex) {
        cout << ex.what();
    }
    return 0;
}