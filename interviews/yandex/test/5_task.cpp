#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    std::string str1, str2;
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);

    if (str1.size() != str2.size()) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int answ = 1;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (int i = 0; i < str1.size(); ++i) {
        if (str1[i] != str2[i]) {
            answ = 0;
        }
    }

    std::cout << answ << std::endl;
    return 0;
}
