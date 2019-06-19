#include <iostream>
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

int main() {
    vector<string> words = {"weew", "bro", "code"};
    int minLength = 4;
    vector<string> res = PalindromFilter(words, minLength);
    for (auto w : res) {
        cout << w << ' ';
    }
    return 0;
}