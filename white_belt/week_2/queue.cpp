#include <iostream>
#include <vector>
#include <string>
using namespace std;

void worry(vector<bool>& queue, int index){
    queue[index] = true;
}

void quiet(vector<bool>& queue, int index){
    queue[index] = false;
}

void come(vector<bool>& queue, int quant){
    if (quant > 0) {
        for (int i = 0; i < quant; ++i){
            queue.push_back(false);
        }
    } else {
        quant *= -1;
        for (int i = 0; i < quant; ++i){
            queue.pop_back();
        }
    }
}

void worry_count(const vector<bool>& queue){
    int count = 0;
    for (auto item : queue){
        if (item)
            ++count;
    }
    cout << count << endl;
}

int main() {
    int q;
    cin >> q;
    string cmd;
    int param;
    vector<bool> queue;
    for (int i = 0; i < q; ++i) {
        cin >> cmd;
        if (cmd != "WORRY_COUNT")
            cin >> param;
        if (cmd == "WORRY") {
            worry(queue, param);
        } else if (cmd == "QUIET") {
            quiet(queue, param);
        } else if (cmd == "COME") {
            come(queue, param);
        } else if (cmd == "WORRY_COUNT") {
            worry_count(queue);
        }
    }
    return 0;
}