#include<iostream>
using namespace std;

// Dynamic Memory Allocation

int getSum(int *arr, int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Sum: " << getSum(arr, n);
    delete []arr;

    return 0;
}