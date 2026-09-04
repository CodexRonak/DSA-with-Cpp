#include<iostream>
using namespace std;

void mergeSort(int *arr, int *temp, int n, int s, int e){
    if(s >= e){
        return;
    }

    int m = s + (e - s) / 2;

    mergeSort(arr, temp, n, s, m);
    mergeSort(arr, temp, n, m + 1, e);

    // merge
    int idx1 = 0;
    int idx2 = 0;
    int mainIdx = 0;

    int len1 = m - s + 1;
    int len2 = e - m;

    mainIdx = s;
    while(idx1 < len1 && idx2 < len2){
        if(arr[idx1] <= arr[idx2]){
            temp[mainIdx++] = arr[idx1++];
        }
        else{
            temp[mainIdx++] = arr[idx2++];
        }
    }
    while(idx1 < len1){
        temp[mainIdx++] = arr[idx1++];
    }
    while(idx2 < len2){
        temp[mainIdx++] = arr[idx2++];
    }

    for (int i = 0; i < n; i++){
        arr[i] = temp[i];
    }
}

int main(){
    int arr[] = {4, 7, 2, 6, 1};
    int n = 5;
    int temp[n];

    mergeSort(arr, temp, n, 0, n - 1);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}


// DYNAMIC MEMORY ALLOCATION 

// void merge(int *arr, int s, int e){
//     int m = s + (e - s) / 2;
//     int len1 = m - s + 1;
//     int len2 = e - m;

//     int *left = new int[len1];
//     int *right = new int[len2];

//     int mainIdx = s;
//     for (int i = 0; i < len1; i++){
//         left[i] = arr[mainIdx++];
//     }

//     mainIdx = m + 1;
//     for (int i = 0; i < len2; i++){
//         right[i] = arr[mainIdx++];
//     }

//     // merge

//     int idx1 = 0;
//     int idx2 = 0;
//     mainIdx = s;

//     while(idx1 < len1 && idx2 < len2){
//         if(left[idx1] < right[idx2]){
//             arr[mainIdx++] = left[idx1++];
//         }
//         else{
//             arr[mainIdx++] = right[idx2++];
//         }
//     }
//     while(idx1 < len1){
//         arr[mainIdx++] = left[idx1++];
//     }
//     while(idx2 < len2){
//         arr[mainIdx++] = right[idx2++];
//     }

//     delete[] left;
//     delete[] right;
// }

// void mergeSort(int *arr, int n, int s, int e){
//     if(s>=e){
//         return;
//     }

//     int m = s + (e - s) / 2;

//     // left part
//     mergeSort(arr, n, s, m);
//     // right part
//     mergeSort(arr, n,  m + 1, e);

//     merge(arr, s, e);
// }

// int main(){
//     int arr[] = {4, 7, 2, 6, 1};
//     int n = 5;

//     mergeSort(arr, n, 0 , n - 1);

//     for (int i = 0; i < n; i++){
//         cout << arr[i] << " ";
//     }

//     return 0;
// }