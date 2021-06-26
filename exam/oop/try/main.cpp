#include <iostream>
using namespace std;
class Base
{
public:
    int x;
    // default constructor
    Base()
    {
        cout << "Base default constructor\n";
    }
    virtual void say() {
        cout << "in base";
    }
};

class Derived : public Base
{
public:

    int y;
    // default constructor
    Derived()
    {
        cout << "Derived default constructor\n";
    }
    void say() {
        cout << "in derived";
    }
};

class Third : public Derived
{

public:
    // default constructor
    Third()
    {
        this->x = 2;
        cout << "Third default constructor\n";
    }
    void say() {
        cout << "in third";
    }
};

int main()
{
    Base* d1 = new Third();
    d1->say();
}