#include <iostream>
#include <cstring>
using namespace std;

// SHALLOW COPY

class Hero{

private:
        int health;
        char level;
        char *name;

public:

    //  Simple constructor
    Hero(){
        cout << endl <<"Constructor is called" << endl;
        name = new char[100];
    }
    
    //  Parameterised constructor
    Hero(char* name, int health, char level){
        this -> name = name; 
        this -> health = health; 
        this -> level = level;

    }
    
    // Copy Constructor
    Hero(Hero& temp){
        cout << endl <<"Copy Constructor is called" << endl;
        this->health = temp.health;
        this->level = temp.level;
        this->name = temp.name;
    }


    char getLev(){
        return this->level;
    }

    void setLev(char l){
        this->level = l;
    }

    int getHealth(){
        return this->health;
    }

    void setHealth(int h){
        this->health = h;
    }

    char* getName(){
        return this->name;
    }

    void setName(char n[]){
        strcpy(this->name, n);
        return;
    }

    void print(){
        cout << "[Name: " << this->name << ", ";
        cout << "Health: " << this->health << ", ";
        cout << "Level: " << this->level << "]" << endl;
        return; 
    }
};

int main(){
    Hero h1;
    h1.setHealth(100);
    h1.setLev('S');
    char name[6] = "Ronak";
    h1.setName(name);
    h1.print();

    Hero h2(h1); // Hero h2 = h1;
    h2.setName("Joy");
    h2.print();
    h1.print();
    return 0;
}