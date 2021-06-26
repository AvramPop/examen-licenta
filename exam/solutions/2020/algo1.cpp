// 1. mean of all even numbers
// 2. 
// B()
// B()
// D()
// B.f
// Function h
// D.f 
#include <iostream>
using namespace std;
class B {
public:
B() { cout << "B() "; }
virtual void f() { cout << "B.f "; }
void g() { f(); }
virtual void h() { g(); }
};
class D : public B {
public:
D() { cout << "D() "; }
void f() { cout << "D.f "; }
void h() { cout << "Function h "; B::h(); }
};
int main() {
B b{}; D d{};
B& dd = d;

return 0;
}
// interviu 1: n^2 daca sirul e deja sortat
// interviu 2: apelarea constructorului din base class si de acolo in jos pe ierarhie