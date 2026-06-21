#include<iostream>
using namespace std;
void uniqueArr(int arr[], int size){
    for (int i = 0; i < size; i++){
        int count = 0;
        for (int j = 0; j < size; j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if (count < 2){
            cout << arr[i] << " ";
        }
    }
}

int main(){
    int arr[] = {11, 2, 3, 4, 2, 3,-2};
    int size = 7;
    uniqueArr(arr, size);
    return 0;
}