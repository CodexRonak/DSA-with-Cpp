#include<iostream>
#include<climits>

using namespace std;

int main(){
    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int size = 8;
    int res = INT_MIN;
    
    for (int i = 0; i < size; i++){
        int sum = 0;
        for (int j = i; j < size; j++){
            sum += arr[j];
            res = max(sum, res);

            // for (int k = i; k <= j; k++){
            //     sum += arr[k];
            //     if(sum>res && k==j){
            //         res = sum;
            //     }
            // }
            // sum = 0;
        }
    }
    cout << res << endl;
    return 0;
}