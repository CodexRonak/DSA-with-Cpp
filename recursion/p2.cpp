#include <iostream>
using namespace std;

int fab(int n){

    //base case
    if(n==0)
        return 0;
    if(n==1)
        return 1;

    return fab(n - 1) + fab(n - 2);
}

int main(){
    int n;
    cin >> n;

    cout << fab(n) << endl;
    return 0;
}