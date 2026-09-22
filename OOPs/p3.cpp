#include <iostream>
using namespace std;

class Hero{
public:
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
    Hero a;
    a.setLev('S');
    a.health = 100;
    cout << endl;
    cout << "static allocation health " << a.health << endl;
    cout << "static allocation level " << a.getLev() << endl;
    
    // dynamic allocation
    Hero *p = new Hero;
    (*p).setLev('A');
    (*p).health = 120;
    cout << endl;
    cout << "dynamic allocation health " << (*p).health << endl; // "p->health" will give the same result
    cout << "dynamic allocation level " << (*p).getLev() << endl; // "p->getlev()" will give same 
    cout << endl;
}