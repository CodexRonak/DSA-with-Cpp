#include <iostream>
using namespace std;

// Hybrid Inheritence

class Bird{
    public:
    int wings;

    void chrip(){
        cout << "Chripss!" << endl;
    }
};

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
    
    void meow(){
        cout << "Meow!" << endl; 
    }
};

class Animals:public Dogs, public Cats{
    public:
    int tails;
};

class Beast: public Animals, public Bird{
    public:

};

int main(){
    Beast dog;
    dog.bark();
    Beast cat;
    cat.meow();
    Beast bird;
    bird.chrip();
    return 0;
}