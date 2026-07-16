//  Move zeros
// [1, 0. 2, 0, 3, 4] to [1, 2, 3, 4, 0 ,0]

#include<iostream>
using namespace std;


void move0s(int arr[], int n){
    int s = 0;
    int e = 0;
    while(e < n){
        if(arr[e] != 0) {
            swap(arr[s], arr[e]);
            s++;
        }
        e++;
    }
}


int main(){
    int arr[] = {1, 0, 2, 0, 3, 4};
    int n = 6;
    move0s(arr, n);
    for (int i = 0; i < n; i++){
        cout << arr[i] <<" ";
    }
    return 0;
}