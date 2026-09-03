#include<iostream>
using namespace std;

long long int power(long long int n, long long int exp){
    if(exp == 0){
        return 1;
    }
    if( exp == 1){
        return n;
    }

    long long int ans = power(n, exp / 2);

    if(n >> 1){
        return ans * ans;
    }
    else{
        return n * ans * ans;
    }
}

int main(){
    long long int n = 2;
    long long int exp = 4;
    cout << power(n, exp) << endl;
    return 0;
}