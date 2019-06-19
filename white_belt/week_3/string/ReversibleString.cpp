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