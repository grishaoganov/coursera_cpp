#include <iostream>
#include <string>
using namespace std;

class ReversibleString{
public:
    ReversibleString(const string& a){
        s = a;
    }
    ReversibleString(){};
    void Reverse(){
        for (int i = 0; i < s.size() / 2; ++i) {
            char tmp = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = tmp;
        }
    }
    string ToString() const {
        return s;
    }
private:
    string s;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}