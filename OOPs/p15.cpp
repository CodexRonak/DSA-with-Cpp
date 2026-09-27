#include <iostream>
using namespace std;

// Hierarchical Inheritence
class Animals{
    public:
    int paws;
    int tails;

    void say(){
        cout << "I am an animal!" << endl;
    }
};

class Dogs: public Animals{
    public:
    bool loyalty;

    void bark(){
        cout << "Bhoww!" << endl;
    }
};

class Cats:public Animals{
    public:

    void meow(){
       cout << "Meow!" << endl; 
    }
};

int main(){
    Dogs d;
    d.bark();
    Cats c;
    c.meow();
    return 0;
}