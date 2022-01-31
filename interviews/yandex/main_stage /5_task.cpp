#include <algorithm>
#include <exception>
#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Stack {
    std::stack<int> vals;
    std::stack<int> max_vals;

public:
    void push(int val);
    void pop();
    int max();
};

void Stack::push(int val) {
    if (vals.empty() || max_vals.top() < val) {
        max_vals.push(val);
    }
    vals.push(val);
}

void Stack::pop() {
    if (vals.empty()) {
        throw std::runtime_error("Stack is empty()");
    }
    if (vals.top() == max_vals.top()) {
        max_vals.pop();
    }
    vals.pop();
}

int Stack::max() {
    if (vals.empty()) {
        throw std::runtime_error("Stack is empty()");
    }
    return max_vals.top();
}

int main() {
    Stack st;
    st.push(5);
    std::cout << "Current max value:" << st.max() << std::endl;  // stack: 5
    st.push(3);
    std::cout << "Current max value:" << st.max() << std::endl;  // stack: 5 3
    st.push(7);
    std::cout << "Current max value:" << st.max() << std::endl;  // stack: 5 3 7
    st.push(10);
    std::cout << "Current max value:" << st.max() << std::endl;  // stack: 5 3 7 10
    st.pop();
    std::cout << "Current max value:" << st.max() << std::endl;  // stack: 5 3 7
    st.pop();
    std::cout << "Current max value:" << st.max() << std::endl;  // stack: 5 3
    st.pop();
    std::cout << "Current max value:" << st.max() << std::endl;  // stack: 5
    st.pop();
    return 0;
}
