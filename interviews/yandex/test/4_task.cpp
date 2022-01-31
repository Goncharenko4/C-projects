#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void bracket(int count, std::string str = "", int left = 0, int right = 0) {
    if (left == count && right == count) {
        cout << str << endl;
    } else {
        if (left < count) {
            bracket(count, str + "(", left + 1, right);
        }
        if (right < left) {
            bracket(count, str + ")", left, right + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    bracket(n);
    return 0;
}
