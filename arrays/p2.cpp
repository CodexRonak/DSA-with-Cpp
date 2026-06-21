#include<iostream>
using namespace std;

void revArray(int arr[], int size){
    int start = 0;
    int end = size - 1;
    // while (start < end)
    // {
    //     swap(arr[start], arr[end]);
    //     start++;
    //     end--;
    // }

    for (int i = 0; i < size; i++){
        if(start < end){
            swap(arr[start], arr[end]);
        }
        start++;
        end--;
    }
}

int main(){
    int arr[] = {2, 34, 2, 6, 85};
    int size = 5;
    revArray(arr, size);
    for (int i = 0; i < size; i++){
        cout << arr[i] <<" ";
    }
        return 0;
}