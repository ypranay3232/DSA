// Friend is a keyword in c++ used to share information of a class that was hidden. The friend is a non member function that is allowed to access the private and protected members of a class. 

#include <iostream>
using namespace std;

class B; // forward declaration

class A {
private:
    int x;

public:
    A(int val) { x = val; }

    friend int sum(A, B); // friend function
};

class B {
private:
    int y;

public:
    B(int val) { y = val; }

    friend int sum(A, B); // same friend
};

int sum(A a, B b) {
    return a.x + b.y; // accessing both private members
}

int main() {
    A obj1(10);
    B obj2(20);

    cout << sum(obj1, obj2);
}

// So why dont we use member functions ? they work only on one class obj, friend func can work on multiple classes simultaneously 