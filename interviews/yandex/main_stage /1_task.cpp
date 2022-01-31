#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;

int main() {
    int n;
    std::cin >> n;
    int cur_sum = 0;
    bool first_find = false;
    int answ = 0;
    for (int i = 0; i < n; ++i) {
        int tmp_val;
        std::cin >> tmp_val;
        if (tmp_val) {
            if (!first_find) {
                if (cur_sum) {
                    answ = cur_sum;
                }
                first_find = true;
            }
            if ((cur_sum + cur_sum % 2) / 2 > answ) {
                answ = (cur_sum + cur_sum % 2) / 2;
            }
            cur_sum = 0;
        } else {
            cur_sum++;
        }
    }

    if (answ < cur_sum) {
        answ = cur_sum;
    }

    std::cout << answ << std::endl;
    return 0;
}
