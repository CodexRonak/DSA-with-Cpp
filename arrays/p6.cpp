#include<iostream>
using namespace std;
void targetSumValue(int arr[],int target){
    int size = sizeof(arr);
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if(arr[i]+arr[j]==target){
                cout << "indices:" << i << " " << j << endl;
                cout << "values:" <<  arr[i] << " " << arr[j];
            }
        }
    }
}

int main(){
    int arr[] = {23, 4, 21, 5, 3};
    targetSumValue(arr, 9);
    return 0;
}