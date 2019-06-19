#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, set<string>> words;
    for (int i = 0; i < n; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            words[word1].insert(word2);
            words[word2].insert(word1);
        } else if (cmd == "COUNT") {
            string word;
            cin >> word;
            if (words.count(word) == 0) {
                cout << 0 << endl;
            } else {
                cout << words[word].size() << endl;
            }
        } else if (cmd == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            if (words.count(word1) != 0 && words[word1].count(word2) != 0) {
                cout << "YES" << endl;
            } else if (words.count(word2) != 0 && words[word2].count(word1) != 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}