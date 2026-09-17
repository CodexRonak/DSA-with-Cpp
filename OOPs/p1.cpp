#include <iostream>
using namespace std;

class Hero{
public:
    int health;
    char rank;
};

int main(){

    Hero ronak;
    ronak.health = 100;
    ronak.rank = 'S';

    cout << ronak.health << endl;
    cout << ronak.rank << endl;
    return 0;
}
