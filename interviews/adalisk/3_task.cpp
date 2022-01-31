// What will the program print?

#include <iostream>
#include <vector>
using namespace std;
int copies = 0;
int moves = 0;

struct Heavy {
    Heavy() {}
    Heavy(int) {}
    Heavy(const Heavy& other) {
        ++copies;
    }
    Heavy(Heavy&& other) {
        ++moves;
    }
};

int main() {
    auto load = vector<Heavy>();
    load.reserve(20);
    Heavy prototype;
    cout << copies << ' ' << moves << endl;  // 0 0

    for (int i = 0; i < 5; ++i)
        load.push_back(prototype);
    cout << copies << ' ' << moves << endl;  // 5 0

    for (int i = 0; i < 5; ++i)
        load.push_back(Heavy());
    cout << copies << ' ' << moves << endl;  // 5 5

    for (int i = 0; i < 5; ++i)
        load.push_back(42);
    cout << copies << ' ' << moves << endl;  // 5 10

    for (int i = 0; i < 5; ++i)
        load.emplace_back(42);
    cout << copies << ' ' << moves << endl;  // 5 10

    auto moreLoad = load;
    cout << copies << ' ' << moves << endl;  // 25 10

    auto moreLoadDecl = move(load);
    cout << copies << ' ' << moves << endl;  // 25 10

    auto getReference = [](const vector<Heavy>& x) {
        return x;
    };
    vector<Heavy> moreLoadRef = getReference(load);
    cout << copies << ' ' << moves << endl;  // 45 10

    auto evenMoreLoad = move(load);
    cout << copies << ' ' << moves << endl;  // 45 10
    return 0;
}
