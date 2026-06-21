#include<iostream>
using namespace std;

void isPower2(int n){
    int power = 1;
    while(power<=n){
        if (power == n){
            cout << "Yes";
            return;
        }
        power *= 2;
    }
    cout << "NO";
}

int main(){
    isPower2(128);
    return 0;
}









// #include<iostream>
// using namespace std;

// bool isPower2(int n){
//     return n > 0 && (n & (n - 1)) == 0;
// }

// int main(){
//     if(isPower2(113))
//         cout << "YES";
//     else
//         cout << "NO";
// }