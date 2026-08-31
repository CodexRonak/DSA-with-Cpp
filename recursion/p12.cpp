#include <iostream>
using namespace std;

int sumLoop(int arr[], int n, int sum){
    if(n == 0){
        return sum;
    }

    sum += arr[n - 1];

    return sumLoop(arr, n - 1, sum);
}

bool isPossible(int arr[], int n, int k, int mid, int i = 0, int painter = 1, int time = 0){
    if(painter > k || arr[i] > mid){
        return false;
    }

    if(i == n){
        return true;
    }

    if(time + arr[i] <= mid){
        return isPossible(arr, n, k, mid, i + 1, painter, time + arr[i]);
    }
    else{
        return isPossible(arr, n, k, mid, i, painter + 1, 0);
    }
}

int painterAlloc(int arr[], int n, int k, int s, int e, int ans){
    int mid = s + (e - s) / 2;

    if(s>e){
        return ans;
    }

    if(isPossible(arr, n, k, mid)){
        return painterAlloc(arr, n, k, s, mid - 1, mid);
    }
    else{
        return painterAlloc(arr, n, k, mid + 1, e, ans);
    }
}

int painter(int arr[], int n, int k){
    int s = 0;
    int e = sumLoop(arr, n, 0);
    int ans = -1;

    if(k > n){
        return ans;
    }

    return painterAlloc(arr, n, k, s, e, ans);
}

int main(){
    int arr[] = {5, 5, 5, 5};
    int n = 4;
    int k = 2;

    cout << painter(arr, n, k) << endl;
    return 0;
}