#include <iostream>
using namespace std;

// Multiple Inheritence

class Dogs{
    public:
    bool loyalty;

    void bark(){
        cout << "Bhoww!" << endl;
    }
};

class Cats{
    public:
    int paws;
    int tails;

    void meow(){
       cout << "Meow!" << endl; 
    }
};

class Animals:public Dogs, public Cats{
    public:
};

int main(){
    Animals dog;
    dog.bark();
    Animals cat;
    cat.meow();
    return 0;
}