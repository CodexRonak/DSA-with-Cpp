// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

 

// Example 1:

// Input: arr = [0,1,0]

// Output: 1

// Example 2:

// Input: arr = [0,2,1,0]

// Output: 1

// Example 3:

// Input: arr = [0,10,5,2]

// Output: 1

 

// Constraints:

// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// arr is guaranteed to be a mountain array.


#include<iostream>
using namespace std;

int peakOfArr(int arr[], int n){
        int s = 1, e = n - 2;
        while(s<=e){
            int m = s + (e - s) / 2;
            if (arr[m - 1] < arr[m] && arr[m] > arr[m + 1]){
                return m;
            }
            else if (arr[m - 1] > arr[m]){
                e = m - 1;
            }
            else{
                s = m + 1;
            }
            m = s + (e - s) / 2;
        }
        return -1;
}

int main (){
    int even[] = {0, 2, 3, 0};
    int odd[] = {2, 4, 2, 3, 0};

    cout << peakOfArr(even, 4) << endl;
    cout << peakOfArr(odd, 5) << endl;
    return 0;
}