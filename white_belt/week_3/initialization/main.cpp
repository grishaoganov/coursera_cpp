#include <iostream>

struct Incognizable{
    int a = 10;
    int b = 10;
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}