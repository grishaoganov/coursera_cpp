#include <vector>
#include <string>
using namespace std;

bool IsPalindrom(string s){
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != s[s.size() - 1 - i])
            return false;
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength){
    vector<string> res;
    for (auto w : words) {
        if (w.size() >= minLength && IsPalindrom(w)){
            res.push_back(w);
        }
    }
    return res;
}