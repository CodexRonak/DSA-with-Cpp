#include <iostream>
using namespace std;

// Abstraction
class CoffeeMachine {
private:
    // Internal complex working (Hidden from user)
    void boilWater() {
        cout << "Water boiling..." << endl;
    }
    void mixMilkAndCoffee() {
        cout << "Mixing milk and coffee..." << endl;
    }

public:
    // Simple interface provided to user
    void makeCoffee() {
        boilWater();
        mixMilkAndCoffee();
        cout << "Coffee ready!" << endl;
    }
};

int main() {
    CoffeeMachine machine;
    
    // User ko sirf ek simple command chalani hai
    machine.makeCoffee();

    return 0;
}