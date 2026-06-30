#include<iostream>
using namespace std;

int binarySearch(int arr[], int key, int s, int e){
    while(s<=e){
        int m = s + (e - s) / 2;
        if(arr[m]==key){
            return m;
        }
        else if(arr[m]<key){
            s = m + 1;
        }
        else{
            e = m - 1;
        }
        m = s + (e - s) / 2;
    }
    return -1;
}

int keyInPivot(int arr[], int n){
    int s = 0, e = n - 1, m = s + (e - s) / 2;
    while(s<e){
        if(arr[m]>=arr[0]){
            s = m + 1;
        }
        else {
            e = m;
        }
        m = s + (e - s) / 2;
    }
    return m;
}

int findPos(int arr[], int n, int k ){
    int p = keyInPivot(arr, n);
    if(arr[p]<=k){
        return binarySearch(arr, k, p, n-1);
    }
    else{
        return binarySearch(arr, k, 0, p-1);
    }
    return -1;
}

int main(){
    int arr[] = {7, 8, 9, 1, 2, 3, 4};
    int n = 7, key = 3;

    cout << "The pos: " << findPos(arr, n, key) << endl;
    return 0;
}