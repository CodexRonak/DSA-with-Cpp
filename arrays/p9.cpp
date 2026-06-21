// Kadane's Algo

#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int n = 7;
    int res = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
        res = max(res, sum);
        // if 3 + -4 =-1 < 0
        if(sum<0){
            sum = 0;
        }
    }
    cout << res;
    return 0;
}