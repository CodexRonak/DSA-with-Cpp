#include<iostream>
using namespace std;
// int DecToBin(int n){
//     int res = 0;
//     int power = 1;
//     int newRes = 0;
//     while (n>0)
//     {
//         res = n % 2;
//         newRes += (res * power);
//         n = n / 2;
//         power *= 10;
//     }
//     return newRes;
// }
// int main(){
//     cout<<DecToBin(10);
//     return 0;
// }



int BinToDec(int n){
    int res = 0;
    int power = 1;
    int newRes = 0;
    while(n>0){
        res = n % 10;
        newRes += (res * power);
        n /= 10;
        power *= 2;
    }
    return newRes;
}

int main(){
    cout<<BinToDec(1010);
    return 0;
}