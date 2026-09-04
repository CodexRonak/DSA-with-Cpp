#include<iostream>
using namespace std;


void bubbleSort(int *arr, int n, int i){

    if(n <= 0){
        return;
    }

    if(i == n - 1){
        return bubbleSort(arr, n - 1, 0);
    }

    if(arr[i] > arr[i + 1]){
        swap(arr[i], arr[i + 1]);
    }
    return bubbleSort(arr, n, i + 1);
}

int main(){
    int arr[] = {4, 7, 2, 6, 1};
    int n = 5;

    bubbleSort(arr, n, 0);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}