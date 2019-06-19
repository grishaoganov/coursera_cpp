#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }
    string GetFullName(int year) {
        string name;
        for (const auto& i : first_names) {
            if (i.first > year)
                break;
            else
                name = i.second;
        }
        string surname;
        for (const auto& i : last_names) {
            if (i.first > year)
                break;
            else
                surname = i.second;
        }
        if (name.empty() && surname.empty()) {
            return "Incognito";
        } else if (name.empty() && !surname.empty()) {
            return surname + " with unknown first name";
        } else if (!name.empty() && surname.empty()) {
            return name + " with unknown last name";
        }
        return name + " " + surname;
    }
    string GetFullNameWithHistory(int year) {
        vector<string> prev_name;
        string name;
        for (const auto& i : first_names) {
            if (i.first > year)
                break;
            else {
                if (name != i.second)
                    prev_name.push_back(i.second);
                name = i.second;
            }
        }
        if (!prev_name.empty())
            prev_name.pop_back();
        vector<string> prev_sur;
        string surname;
        for (const auto& i : last_names) {
            if (i.first > year)
                break;
            else {
                if (surname != i.second)
                    prev_sur.push_back(i.second);
                surname = i.second;
            }
        }
        if (!prev_sur.empty())
            prev_sur.pop_back();
        if (prev_name.empty() && prev_sur.empty()) {
            if (name.empty() && surname.empty()) {
                return "Incognito";
            } else if (name.empty() && !surname.empty()) {
                return surname + " with unknown first name";
            } else if (!name.empty() && surname.empty()) {
                return name + " with unknown last name";
            }
            return name + " " + surname;
        } else if (!prev_name.empty() && prev_sur.empty()) {
            string res_name;
            res_name += " (";
            for (int i = prev_name.size() - 1; i >= 0; --i) {
                if (i != 0)
                    res_name += prev_name[i] + ", ";
                else
                    res_name += prev_name[i] + ")";
            }
            if (!name.empty() && surname.empty()) {
                return name + res_name + " with unknown last name";
            }
            return name + res_name + " " + surname;
        } else if (prev_name.empty() && !prev_sur.empty()) {
            string res_sur;
            res_sur += " (";
            for (int i = prev_sur.size() - 1; i >= 0; --i) {
                if (i != 0)
                    res_sur += prev_sur[i] + ", ";
                else
                    res_sur += prev_sur[i] + ")";
            }
            if (name.empty() && !surname.empty()) {
                return surname + res_sur + " with unknown first name";
            }
            return name + " " + surname + res_sur;
        }
        string res_name;
        res_name += " (";
        for (int i = prev_name.size() - 1; i >= 0; --i) {
            if (i != 0)
                res_name += prev_name[i] + ", ";
            else
                res_name += prev_name[i] + ")";
        }
        string res_sur;
        res_sur += " (";
        for (int i = prev_sur.size() - 1; i >= 0; --i) {
            if (i != 0)
                res_sur += prev_sur[i] + ", ";
            else
                res_sur += prev_sur[i] + ")";
        }
        return name + res_name + " " + surname + res_sur;
    };
private:
    map<int, string> first_names;
    map<int, string> last_names;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}