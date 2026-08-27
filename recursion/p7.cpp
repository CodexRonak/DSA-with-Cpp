#include <iostream>
using namespace std;

int firstOcc(int arr[], int s, int e, int k){

    
    int m = s + (e - s) / 2;
    int ans = -1;
    if(s>e)
        return ans;

    if(arr[m] == k && arr[m - 1] != arr[m]){
        ans = m;
        return ans;
    }
    else if(arr[m] >= k){
        return firstOcc(arr, s , m - 1, k);
    }
    else{
        return firstOcc(arr, m + 1, e, k);
    }

    return ans;
}

int lastOcc(int arr[], int s, int e, int k){

    
    int m = s + (e - s) / 2;
    int ans = -1;
    if(s>e)
        return ans;

    if(arr[m] == k && arr[m + 1] != arr[m]){
        ans = m;
        return ans;
    }
    else if(arr[m] > k){
        return lastOcc(arr, s , m - 1, k);
    }
    else{
        return lastOcc(arr, m + 1, e, k);
    }

    return ans;
}

int totalOcc(int arr[], int s, int e, int k){
    int f = firstOcc(arr, s, e, k);
    int l = lastOcc(arr, s, e, k);

    return l - f + 1;
}

int main(){
    int arr[] = {1, 2, 2, 5, 5, 5};
    int n = 6;
    int s = 0, e = n - 1;
    int k;
    cin >> k;

    cout << firstOcc(arr, s, e, k)<< " " << lastOcc(arr, s, e, k) << endl;
    cout << totalOcc(arr, s, e, k) << endl;

    return 0;
}