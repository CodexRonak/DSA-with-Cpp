#include <iostream>
using namespace std;

int main(){
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rowSum = 0;
    int maxi = INT8_MIN;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            rowSum += arr[i][j];
        }
        if(maxi<rowSum){
            maxi = rowSum;
        }
    }
    cout << "Max row sum value is " << maxi << endl;
    return 0;
}