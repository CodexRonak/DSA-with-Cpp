#include <iostream>
using namespace std;

class Hero {
private:
    const int id; // Constant Data Member

public:
    Hero(int hero_id) : id(hero_id) {
        // id = hero_id; //  ERROR! Constructor body mein assignment allowed nahi hai
    }

    // Const function read-only access deta hai
    void print() const {
        cout << "ID: " << id << endl;
    }
};

int main() {
    Hero h1(101);
    h1.print();

    const Hero h2(102); // Const Object
    h2.print(); // Allowed because print() is a const function

    return 0;
}