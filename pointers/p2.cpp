#include<iostream>
using namespace std;

int main(){

    int arr[5] = {10, 20, 30, 40, 50};
    // int *p1 = &arr[0];
    // int *p2 = p1 + 3;
    // cout << *p2;

    // cout << *arr << endl; // 10
    //cout << *arr + 1 << endl; // 10 + 1 = 11 
    //cout << *(arr) + 1 << endl; // 10 + 1 = 11 
    // cout << *(arr + 1) << endl; // 20

    int i = 4;
    // cout << i[arr] << endl; //50
    cout << *(i + arr) << endl; //50

    return 0;
}