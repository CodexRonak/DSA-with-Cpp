#include <iostream>
using namespace std;
int revNum(int n1){
    int n2 = 0;
    int rev = 0;
    while (n1>0)
    {
        n2 = n1 % 10;
        rev = rev * 10 + n2;
        n1 /= 10;
    }
    cout << rev;
    return 0;
}
int main(){
    revNum(1212);
    return 0;
}