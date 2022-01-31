// What will the program print?

#include <iostream>
using namespace std;

template <typename T>
T divideBy2(const T& value) {
    return value / 2;
}

int main() {
    cout << divideBy2(2) << endl;    // 1
    cout << divideBy2(3) << endl;    // 1
    cout << divideBy2(3.4) << endl;  // 1,7
    return 0;
}
