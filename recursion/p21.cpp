#include<iostream>
using namespace std;

int inversionCount(int *arr, int *temp, int n, int s, int e){
    if(s>=e){
        return 0;
    }
    int count = 0;
    int m = s + (e - s) / 2;

    count += inversionCount(arr, temp, n, s, m);
    count += inversionCount(arr, temp, n, m + 1, e);

    int idx1 = s;
    int idx2 = m + 1;
    int mainIdx = s;

    while(idx1 <= m && idx2 <= e){
        if(arr[idx1] <= arr[idx2]){
            temp[mainIdx++] = arr[idx1++];
        }
        else{
            temp[mainIdx++] = arr[idx2++];
            count += (m - idx1 + 1);
        }
    }
    
    while(idx1 <= m){
        temp[mainIdx++] = arr[idx1++];
    }
    
    while(idx2 <= e){
        temp[mainIdx++] = arr[idx2++];
    }

    for (int i = 0; i < n; i++){
        arr[i] = temp[i];
    }
    return count;
}

int main(){
    int arr[] = {4, 3, 2, 1};
    int n = 5;
    int temp[n];

    cout << inversionCount(arr, temp, n, 0, n - 1) << endl;
    return 0;
}