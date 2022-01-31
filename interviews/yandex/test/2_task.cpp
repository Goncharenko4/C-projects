#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    int n;
    cin >> n;
    bool sequence = false;
    int max_len = 0;
    int cur_len = 0;

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp) {
            if (!sequence) {
                sequence = true;
            }
            cur_len++;
        } else {
            if (sequence) {
                if (cur_len > max_len) {
                    max_len = cur_len;
                }
                cur_len = 0;
                sequence = false;
            }
        }
    }

    if (cur_len > max_len) {
        max_len = cur_len;
    }

    cout << max_len << endl;
    return 0;
}
