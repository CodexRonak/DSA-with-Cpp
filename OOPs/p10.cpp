#include <iostream>
using namespace std;

// Intialization list

class Hero{
    int health;
    char rank;

    Hero(){
        cout << "constructor called" << endl;
    }

    // Normal Assignment
    // Hero(int health, char rank){
    //     this->health = health;
    //     this->rank = rank;
    // }
public:
    Hero(int health, char rank): health(health), rank(rank){
        cout << this->health << endl;
        cout << this->rank << endl;
    }
};

int main(){
    Hero h1(100, 'A');
    return 0;
}

// Normal Assignment se Better Kyun Hai?
// Performance Optimization: Normal assignment mein pehle data members memory mein default construct hote hain, phir unhein new value assignment di jaati hai (Double overhead). Initializer List mein object creation ke time hi direct value place hoti hai.

// Mandatory Cases: Constant (const) variables, Reference variables (&), aur aisi sub-classes jinke parent class mein default constructor nahi hota — unhein sirf Initialization List se hi initialize kiya ja sakta hai.