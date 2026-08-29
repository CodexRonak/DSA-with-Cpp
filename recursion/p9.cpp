#include <iostream>
using namespace std;

int pivot(int arr[], int s, int e){
    int m = s + (e - s) / 2;

    if(s<e){
        return m;
    }


    if(arr[m]>=arr[0]){
        return pivot(arr, m + 1, e);
    }
    else{
        return pivot(arr, s, m);
    }
    

    return -1;
}

int main(){
    int arr[] = {7, 9, 1, 3, 4};
    // int arr[] = {3, 2, 1, 4, 5};
    int n = 5;
    int s = 0;
    int e = n - 1;

    cout << pivot(arr, s, e) << endl;
    return 0;
}