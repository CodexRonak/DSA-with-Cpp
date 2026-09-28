#include <iostream>
using namespace std;

// Runtime Polymorphism
// method overloading
class Animal{
public:

    void say(){
    cout << "I am an animal" << endl;
    }
};

class Dogs:public Animal{
public:
    void say(){
        cout << "Bhoww!" << endl;
    }
};

int main(){
    Dogs d;
    d.say(); // Bhoww
    return 0;
}