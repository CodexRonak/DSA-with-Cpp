#include<iostream>
#include<algorithm>
using namespace std;

bool isPossible(int arr[], int n, int k, int m, int i, int cowCount, int lastPosition){
    if(cowCount == k){
        return true;
    }
    if(i == n){
        return false;
    }
    
    if(arr[i] - lastPosition >= m){
        return isPossible(arr, n, k, m, i + 1, cowCount + 1, arr[i]);
    }

    return isPossible(arr, n, k, m, i + 1, cowCount, lastPosition);
}

int aggressiveCows(int arr[], int n, int k, int s, int e, int ans){
    int m = s + (e - s) / 2;

    if(k >= n){
        return -1;
    }
    if(s>e){
        return ans;
    }

    if(isPossible(arr, n, k, m, 0, 1, arr[0])){
        ans = m;
        return aggressiveCows(arr, n, k, m + 1, e, ans);
    }
    else{
        return aggressiveCows(arr, n, k, s, m - 1, ans);
    }
    
}

int main(){

    int n = 6;
    int k = 4;
    int arr[n] = {0, 3, 4, 7, 10, 9};
    sort(arr, arr + n);

    int s = arr[0];
    int e = arr[n - 1] - s;

    cout << aggressiveCows(arr, n, k, s, e, -1) << endl;
    return 0;
}