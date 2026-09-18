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
    return 0;
}