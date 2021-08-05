#include <iostream>
#include <stack>

bool valid_pair(char prev, char cur) {
    return (
        (prev == '(' && cur == ')') || 
        (prev == '{' && cur == '}') || 
        (prev == '[' && cur == ']')
    );
}

bool check(std::string &s) {
    std::stack<char> st;

    for (char c : s) {
        if (c == '{' || c == '[' || c == '(') {
            st.push(c);
        } else {
            if (st.size() && valid_pair(st.top(), c)) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    return (st.size() == 0);
}

int main() {
    std::string s;
    while (std::cin >> s) {
        std::cout << check(s) << std::endl;
    }
    return 0;
}
