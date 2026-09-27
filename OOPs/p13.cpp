#include <iostream>
using namespace std;

// Inheritence

class Human{
    public:
    int height;
    int weight;
    int age;

    public:

    void setWeight(int w){
        this->weight = w;
    }

};

class Male: public Human{
    public:
    string colour;

    void sleep(){
        cout << "Male sleeping" << endl;
    }
};

int main(){
    Male m1;

    cout << m1.age << endl;
    cout << m1.height << endl;
    cout << m1.weight << endl;
    cout << m1.colour << endl;

    m1.sleep();
    return 0;
}