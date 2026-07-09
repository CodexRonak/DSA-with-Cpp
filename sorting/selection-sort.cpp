#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        int mini = arr[i];
        for (int j = i + 1; j < n; j++){
            mini = min(arr[i], arr[j]);
            if(arr[i]>mini){
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main(){
    int arr[] = {22, 14, 81, 5};
    int n = 4;
    selectionSort(arr, n);
    for (int i = 0; i < n; i++){
        cout << arr[i] <<" ";
    }
        return 0;
}