#include <iostream>
using namespace std;

// Multi-level Inheritence
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

class GermanShepherd:public Dogs{
    public:
};

int main(){
    GermanShepherd g;
    g.bark();
    return 0;
}