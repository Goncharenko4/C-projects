#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool check(std::vector<std::pair<int, int>> v) {
    bool answ = true;
    std::unordered_map<int, std::unordered_map<int, int>> m;
    if (v.size() == 0) {
        return false;
    }
    if (v.size() == 1) {
        return true;
    }

    int min_x = v[0].first, max_x = v[0].first;
    for (auto item : v) {
        if (item.first < min_x) {
            min_x = item.first;
        }
        if (item.first > max_x) {
            max_x = item.first;
        }
    }

    int yrav = min_x + max_x;
    for (auto item : v) {
        m[item.first][item.second] = 1;
    }

    for (auto item : v) {
        if (m[item.first + (yrav - 2 * item.first)][item.second]) {
            answ = false;
            break;
        }
    }

    return answ;
}

int main() {
    std::vector<std::pair<int, int>> v = {std::make_pair(1, 2),
                                          std::make_pair(2, 1), std::make_pair(3, 1)};
    if (check(v)) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Incorrect" << std::endl;
    }

    return 0;
}
