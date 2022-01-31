// What will the program print?

#include <stdio.h>

class A {
public:
    A() {
        init();
    }
    virtual void init(bool doInit = true) {
        if (doInit) {
            printf("A\n");
        }
    }
};
class B : public A {
public:
    B() {
    }
    virtual void init() {
        printf("B\n");
    }
};

int main() {
    B b;              // А
    A* ptr = &b;      //
    ptr->init();      // A
    ptr->init(true);  // A
    return 0;
}
