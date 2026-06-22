#include<iostream>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / 4, i = 1;

    while ( i < size){
        swap(arr[i], arr[i - 1]);
        i = i + 2;
    }
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}