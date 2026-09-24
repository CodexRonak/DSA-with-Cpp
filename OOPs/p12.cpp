#include <iostream>
using namespace std;

class Hero{
public:
    // static members
    static int timeToComplete;
    static int r;

    // static function can call only static members 
    static int random(){
        return r;
    }
};

int Hero::timeToComplete = 5;
int Hero::r = 20;

int main(){

    cout << Hero::timeToComplete << endl;

    Hero a;
    cout << a.timeToComplete << endl;
    Hero b;
    b.timeToComplete = 10;
    cout << b.timeToComplete << endl;
    cout << a.timeToComplete << endl;

    cout << Hero::random() << endl;
    return 0;
}