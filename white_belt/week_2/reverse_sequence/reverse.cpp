#include <vector>
using namespace std;

void swap(int& first, int& second){
    int tmp = first;
    first = second;
    second = tmp;
}

void Reverse(vector<int>& v){
    for (int i = 0; i < v.size() / 2; ++i) {
        swap(v[i], v[v.size() - 1 - i]);
    }
}