#include<iostream>
using namespace std;

bool palindrome(int arr[], int n){
    int s = 0, e = n - 1;
    while(s<=e){
        if(arr[s]!=arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int main(){
    int arr[] = {1, 2, 3, 2, 1};
    int n = 5;
    cout << "Is array a palindrome? " << palindrome(arr, n);
    return 0;
}