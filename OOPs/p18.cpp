#include<iostream>
using namespace std;

// Inheritence Ambiguity
class A{
    public:

    void say(){
        cout << "I'm A" << endl;
    }
};

class B{
    public:

    void say(){
        cout << "I'm B" << endl;
    }
};

class C: public A, public B{
    public:
};

int main(){
    C obj;

    obj.A::say();
    obj.B::say();

    return 0;
}