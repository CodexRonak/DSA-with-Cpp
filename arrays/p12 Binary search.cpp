// Binary Search

#include<iostream>
using namespace std;

int binarySearch(int arr[], int size , int key){
    int start = 0, end = size - 1;
    while(start<=end){
        int mid = start + (end - start) / 2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[start]<key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main(){
    int even[] = {1, 2, 3, 4, 5, 6};
    int odd[] = {5, 6, 7, 8, 9};

    int evenBS = binarySearch(even, 6, 5);
    int oddBS = binarySearch(odd, 5, 7);
    cout << evenBS << endl;
    cout << oddBS << endl;

    return 0;
}