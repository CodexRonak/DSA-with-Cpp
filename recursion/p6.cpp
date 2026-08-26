#include <iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int k){

    if(s>e) return -1;
    
    int m = s + (e - s) / 2;

    if(arr[m] == arr[k]){
        cout << m << endl;
    }
    
    if(arr[m] > arr[k]){
        return binarySearch(arr, s, m - 1, k);
    }
    else{
        return binarySearch(arr, m + 1, e, k);
    }
}

int main(){
    int arr[] = {12, 13, 15, 19, 20};
    int k = 19;
    int s = 0;
    int e = 4;

    if(binarySearch(arr, s, e, k)){
        cout << "present" << endl;
    }
    else{
        cout << "not present" << endl;
    }
    return 0;
}