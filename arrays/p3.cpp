#include<iostream>
using namespace std;

void minSwapMax(int arr[], int size){
    int Min = 0;
    int Max = 0;
    for (int i = 0; i < size; i++){
        if(arr[i] < arr[Min]){
            Min = i;
        }
        if(arr[i] > arr[Max]){
            Max = i;
        }
    }
    swap(arr[Min], arr[Max]);

}

int main(){
    int arr[] = {7, 12,22, -3, 4, 15,-2,-7};
    int size = sizeof(arr)/4;
    minSwapMax(arr, size);
    for (int i = 0; i < size; i++){
    cout << arr[i] << " ";
    }
    return 0;
}
