// Problem statement
// You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].

// Now, in the given array/list, 'M' numbers are present twice and one number is present only once.

// You need to find and return that number which is unique in the array/list.

//  Note:
// Unique element is always present in the array/list according to the given condition.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^3
// Time Limit: 1 sec
// Sample Input 1:
// 1
// 7
// 2 3 1 6 3 6 2
// Sample Output 1:
// 1
// Explanation: The array is [2, 3, 1, 6, 3, 6, 2]. Here, the numbers 2, 3, and 6 are present twice, and the number 1 is present only once. So, the unique number in this array is 1.
// Sample Input 2:
// 2
// 5
// 2 4 7 2 7
// 9
// 1 3 1 3 6 6 7 10 7
// Sample Output 2:
// 4
// Explanation: In the first test case, the array is [2, 4, 7, 2, 7]. Here, the numbers 2 and 7 are present twice, and the number 4 is present only once. So, the unique number in this array is 4.

// 10
// Explanation: In the second test case, the array is [1, 3, 1, 3, 6, 6, 7, 10, 7]. Here, the numbers 1, 3, 6, and 7 are present twice, and the number 10 is present only once. So, the unique number in this array is 10.


#include<iostream>
#include<algorithm>
using namespace std;

// int main(){
//     int arr[] = {2, 3, 2, 4, 5, 5};
//     int size = sizeof(arr) / 4;

//     sort(arr, arr + size - 1); // 2 2 3 4 5 5

//     // unique
//     for (int i = 1; i < size; i++){
//         if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1]){
//             cout << arr[i] << " ";
//         }
//     }
//     cout << endl;

//     // duplicate
//     for (int i = 1; i < size; i++){
//         if(arr[i]==arr[i-1]){
//             cout << arr[i] << " ";
//         }
//     }

//         return 0;
// }

// OPTIMIZED APPROACH

int main(){
    int arr[] = {3,1,4,1,3};
    int ans = 0;
    for (int i = 0; i < sizeof(arr) / 4; i++){
        ans = ans ^ arr[i];
    }
    cout<<ans;
    return 0;
}