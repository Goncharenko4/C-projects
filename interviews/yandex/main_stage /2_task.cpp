#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    int n;
    int cur_len1 = 0, cur_len2 = 0;
    int answ = 0;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;

        if (tmp) {
            cur_len1++;
        } else {
            if (answ < (cur_len1 + cur_len2)) {
                answ = cur_len1 + cur_len2;
            }
            cur_len2 = cur_len1;
            cur_len1 = 0;
        }
    }

    if (answ < (cur_len1 + cur_len2)) {
        answ = cur_len1 + cur_len2;
    }

    std::cout << answ << std::endl;
    return 0;
}
