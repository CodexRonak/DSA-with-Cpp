#include<iostream>
using namespace std;

void arrIntersect(int arr1[], int size1, int arr2[], int size2){
    for (int i = 0; i < size1; i++){
        for (int j = 0; j < size2; j++){
            if(arr1[i]==arr2[j] && size1>size2){
                cout << arr1[i] << " ";
            }
            // else{
            //     cout << arr1[i] << " ";
            // }
        }
        
    }
}

int main(){
    int arr1[] = {2, 6, 3, 8, 2};
    int arr2[] = {5, 2, 7, 8};
    int size1 = 5;
    int size2 = 4;
    arrIntersect(arr1, size1, arr2, size2);
    return 0;
}