#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){

    for (int i = 0; i < n; i++){
        
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++){

            if(arr[j]>arr[j + 1]){
                isSwap = true;
                swap(arr[j], arr[j + 1]);
            }

        }
        if(isSwap==false){
            break;
        }
    }
}


int main(){
    int arr[] = {10, 6, 7, 14, 9};
    int n = 5;
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++){
        cout << arr[i] <<" ";
    }
    return 0;
}