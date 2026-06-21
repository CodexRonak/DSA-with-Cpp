// smaller num in array


#include<iostream>
#include <climits>
using namespace std;
int main(){
    int arr[] = {12, -10, 13, 4, -5};
    int size = 5;
    int small = INT_MAX;
    for (int i = 0; i < size; i++){
        if(arr[i]<small){
            small = arr[i];
        }
    }
    cout << small<< endl;
    return 0;
}