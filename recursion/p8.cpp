#include <iostream>
using namespace std;

int peakOfArr(int arr[], int s , int e){
    int m = s + (e - s) / 2;

    if(arr[m] > arr[m-1] && arr[m] > arr[m+1]){
        return m;
    }
    else if(arr[m] > arr[m-1]){
        return peakOfArr(arr, m + 1, e);
    }
    else if(arr[m] > arr[m+1]){
        return peakOfArr(arr, s, m);
    }
    return -1;
}

int main(){
    int arr[] = {1, 3, 5, 6, 7, 8, 4, 2};
    int n = 8;
    int s = 0, e = n - 1;

    cout << peakOfArr(arr, s, e) << endl;

    return 0;
}