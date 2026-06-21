
#include<iostream>
using namespace std;
int main(){
    uint32_t n = 0b0000000010000010101;
    int f = 0;
    while (n>0){
        if(n&1){
            f++;
            n=n >> 1;
        }
        else{
            n = n >> 1;
        }
    }
    cout << f;

    return 0;
}