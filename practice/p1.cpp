#include<iostream>
using namespace std;

void revArr(int arr[], int n){
    int s = 0, e = n - 1;
    while(s<=e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    revArr(arr, n);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}