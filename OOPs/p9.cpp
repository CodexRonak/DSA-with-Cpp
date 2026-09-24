#include <iostream>
using namespace std;

// constant functions

class Hero{
    int health;
    // health = 100; // here too we cant

public:
    int getHealth() const{
        // health = 100; // in this function, we cannot modify the class members, but in non const function we can change
        return health;
    }
};

int main(){
    Hero h1;
    cout << h1.getHealth();
}

// int main(){
//     const int a = 10;
//     // a = 20; cannot be changed
//     return 0;
// }