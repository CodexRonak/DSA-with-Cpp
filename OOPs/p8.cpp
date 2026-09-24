#include <iostream>
using namespace std;

class Hero{
public:
    Hero(){
        cout << "constructor called" << endl;
    }
    ~Hero(){
        cout << "destructor called" << endl;
    }
};

int main(){
    
    Hero h1;
    Hero *h2 = new Hero;
    delete h2; // for dynamicaly destructor will be manually called
    return 0;
}
