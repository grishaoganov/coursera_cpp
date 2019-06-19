#include <string>
#include <map>
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
    };
private:
    map<int, string> first_names;
    map<int, string> last_names;
};