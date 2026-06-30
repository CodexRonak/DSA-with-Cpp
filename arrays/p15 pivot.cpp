#include<iostream>
using namespace std;

int pivot(int arr[], int n){
    int s = 0, e = n - 1;

    int m = s + (e - s) / 2;
    while(s < e){
        if(arr[m]>=arr[0]){
            s = m + 1;
        }
        else if(arr[m]<=arr[0]){
            e = m; // e = m , for finding smallest element that is 1.... e = m - 1 , for largest value which is 9 , arr[]=[7,9,1,2,3]
        }
        m = s + (e - s) / 2;
    }
    return m;
}


int main(){
    int arr[] = {7, 9, 1, 2, 3};
    cout << "Pivot is : " << pivot(arr, 5) << endl;
    return 0;
}