#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int painter, int m){
    int painterCount = 1;
    int paintSum = 0;

    for (int i = 0; i < n; i++){
        if(paintSum + arr[i]<=m){
            paintSum += arr[i];
        }

        else{
            painterCount++;
            if(painterCount>painter || arr[i]>m){
                return false;
            }
            paintSum = arr[i];
        }
    }

    return true;
}


int minPaintTime(int arr[], int n, int painter){
    int s = 0, e;
    int ans = -1;
    int sum = 0;
    
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }

    e = sum;

    while (s <= e){
        int m = s + (e - s) / 2;
        if (isPossible(arr, n, painter, m)){
            ans = m;
            e = m - 1;
        }
        else{
            s = m + 1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {5, 5, 5, 5};
    int n = 4;
    int painter = 2;

    cout << minPaintTime(arr, n, painter) << endl;

    return 0;
}