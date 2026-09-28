#include <iostream>
using namespace std;

// Polymorphism

// Compile Time Polymorphosim
// function overloading

class A{
public:
    int a;
    int b;

    void sayHello(){
        cout << "Hello World" << endl;
    }
    
    void sayHello(string s){
        cout << "Hello " << s << endl;
    }
    
    int sayHello(string s, int n){
        cout << "Hello " << s << n << endl;
        return n;
    }

// Operator overlading

    void operator+(A &obj){
        int value1 = this->a;
        int value2 = obj.a;
        cout << "output: " << value2 - value1 << endl;
    }
};

int main() {
    A obj;

    obj.sayHello();             // Calls void sayHello()
    obj.sayHello("Ronak");        // Calls void sayHello(string s)
    obj.sayHello("Ronak", 2);          // Calls int sayHello(string s, int n)

    A num1, num2;
    num1.a = 3;
    num2.a = 8;
    num1 + num2;

    return 0;
}