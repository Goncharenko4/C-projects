#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    long long n;
    cin >> n;
    if (n <= 0) return 0;
    long long pred_elem, cur_elem;
    cin >> pred_elem;
    cur_elem = pred_elem;

    for (long long i = 0; i < n - 1; ++i) {
        cin >> cur_elem;
        if (pred_elem != cur_elem) {
            cout << pred_elem << endl;
        }
        pred_elem = cur_elem;
    }

    cout << cur_elem << endl;

    return 0;
}
