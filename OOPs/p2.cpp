#include <iostream>
using namespace std;

class Hero{
public:
    int health;
    
        char L_Getter(){
            return level;
        }
    
        void L_Setter(char l){
            level = l;
        }

private:
    char level;
};

int main(){
    Hero ronak;
    ronak.health = 120;
    ronak.L_Setter('B');

    cout << ronak.health << endl;
    cout << ronak.L_Getter() << endl;

    // the output would be 8 because of padding and alignment
    // Alignment means assigning the memory block of the datatypes in meaningfull or sensible manner and padding is unused space between two aligned datatypes
    // memory block: 0   1   2   3   4   5   6   7
    // Alignment:  char  p   p   p   -----int-----
    //                  --padding--

    //  instead of int if we used double it would have aligned from index 8 memory block instead of 1

    cout << sizeof(ronak) << endl;

    return 0;
}