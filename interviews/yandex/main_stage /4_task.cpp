#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void remove(std::vector<int>& v, int val) {
    // Solution via iterators:
    std::vector<int>::iterator it;
    size_t cur_pos = 0;
    for (it = v.begin(); it != v.end(); it++, cur_pos++) {
        if (*it != val) {
            v[cur_pos] = *it;
        } else {
            cur_pos--;
        }
    }
    v.resize(cur_pos);

    // Classic solution:
    /*
    size_t cur_pos = 0;
    for (auto elem : v) {
        if (elem != val) {
            v[cur_pos] = elem;
            cur_pos++;
        }
    }
    v.resize(cur_pos);
    */

    std::cout << "After: { ";
    for (auto item : v) {
        std::cout << item << "; ";
    }
    std::cout << "}" << std::endl;
}

int main() {
    std::vector<int> v = {5, 4, 3, 5, 8, 2, 5};
    int val = 5;
    remove(v, val);
    return 0;
}
