#include <iostream>
using namespace std;

class Hero{
public:

    //  Simple constructor
    Hero(){
        cout << endl <<"Constructor is called" << endl;
    }
    
    //  Parameterised constructor
    Hero(int health, char level){
        this -> health = health; // this contains the address of the current object
        this -> level = level;
    }
    
    // Copy Constructor
    Hero(Hero& temp){
        cout << endl <<"Copy Constructor is called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    int health;
    
private:
    char level;

public:
    char getLev(){
        return level;
    }

    void setLev(char l){
        level = l;
    }
};

int main(){
    // static allocation
    Hero a(44, 'E'); // Constructor called here
    cout << endl;
    cout << "static allocation health " << a.health << endl;
    cout << "static allocation level " << a.getLev() << endl;
    
    // dynamic allocation
    Hero *p = new Hero(71, 'C'); // Constructor called here
    cout << endl;
    cout << "dynamic allocation health " << p->health << endl;
    cout << "dynamic allocation level " << p->getLev() << endl; 
    cout << endl;

    // copying constructor
    Hero b(a);
    cout << "static allocation health " << b.health << endl;
    cout << "static allocation level " << b.getLev() << endl;
    
    //  Value assigning to b didnt affect the values of a
    b.setLev('B');
    cout << endl;
    cout << b.getLev() << endl;
    cout << a.getLev() << endl;
}