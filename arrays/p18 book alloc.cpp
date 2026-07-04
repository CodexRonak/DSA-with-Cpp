//  Book Allocation Problem

#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int st, int m){

    int stCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++){
        if (pageSum + arr[i] <= m){

            pageSum += arr[i];

        }
        else{

            stCount++;

            if(stCount > st || arr[i] > m){
                return false;
            }

            pageSum = arr[i];

        }
    }

    return true;
}

int bookAlloc(int arr[],int n, int st){

    int s = 0;
    int sum = 0;
    int e;

    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    e = sum;

    int m = s + (e - s) / 2;
    int ans = -1;

    while(s<=e){
        if (isPossible( arr, n, st, m)){
            ans = m;
            e = m - 1;
        }
        else{
            s = m + 1;
        }
        m = s + (e - s) / 2;
    }
    return ans;
}


int main(){

    int arr[] = {10, 20, 30, 40}; // no. of books with pages
    int st = 2; // students
    int n = 4; //size of the array or no. of books

    cout << bookAlloc(arr, n, st) << endl;

    return 0;
}