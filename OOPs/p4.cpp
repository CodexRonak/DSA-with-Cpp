#include <iostream>
using namespace std;

class Hero{
public:

    Hero(){
        cout << endl <<"Constructor is called" << endl;
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
    Hero a; // Constructor called here
    a.setLev('S');
    a.health = 100;
    cout << endl;
    cout << "static allocation health " << a.health << endl;
    cout << "static allocation level " << a.getLev() << endl;
    
    // dynamic allocation
    Hero *p = new Hero; // Constructor called here
    (*p).setLev('A');
    (*p).health = 120;
    cout << endl;
    cout << "dynamic allocation health " << p->health << endl;
    cout << "dynamic allocation level " << p->getLev() << endl; 
    cout << endl;
}