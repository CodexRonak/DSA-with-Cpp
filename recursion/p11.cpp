#include <iostream>
using namespace std;

bool ifPossible(int arr[], int n, int m, int mid, int i = 0, int student = 1, int totalPage = 0){
    if (student > m) return false;
    if (i == n) return true;

    if (arr[i] > mid) return false; 

    if (totalPage + arr[i] <= mid) {
        return ifPossible(arr, n, m, mid, i + 1, student, totalPage + arr[i]);
    } else {
        return ifPossible(arr, n, m, mid, i, student + 1, 0);
    }
}


int sumLoop(int arr[], int n, int sum = 0){
    if(n==0){
        return sum;
    }

    sum = sum + arr[n - 1];
    return sumLoop(arr, n-1, sum);
}


int bookAlloc(int arr[], int n, int m, int s, int e, int ans){
    int mid = s + (e - s) / 2;

    if(s>e){
        return ans;
    }

    if(ifPossible(arr, n, m, mid)){
        return bookAlloc(arr, n, m, s, mid - 1, mid);
    }
    else{
        return bookAlloc(arr, n, m, mid + 1, e, ans);
    }
}

int book(int arr[], int n, int m){
    int s = 0;
    int e = sumLoop(arr, n);
    int ans = -1;

    if (m > n) return ans;
    
    return bookAlloc(arr, n, m, s, e, ans);
}

int main(){
    int arr[] = {10, 20, 30, 40};
    int n = 4;
    int m = 2;

    cout << book(arr, n, m) << endl;
    return 0;
}