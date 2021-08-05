/*библиотека*/

class Foo {
public:
    Foo(int j) {
        i = new int[j];
        length = j;
    }
    virtual ~Foo() { delete i; }
    Foo& operator=(const Foo& f) {
        delete i;
        i = new int[f.length];
        for (int tmp = 0; tmp < f.length; ++tmp) {
            i[tmp] = f.i[tmp];
        }
        return *this;
    }

private:
    int* i;
    int length;
};

class Bar : public Foo {
public:
    Bar(int j) : Foo(j) { i = new char[j]; }
    ~Bar() { delete i; }

private:
    char* i;
};

/*приложение*/

int main() {
    Foo* f = new Foo(100);
    Foo* b = new Bar(200);
    *f = *b;
    delete f;
    delete b;
    return 0;
}