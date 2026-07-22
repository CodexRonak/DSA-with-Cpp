#include <iostream>
using namespace std;

int main(){
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 3;
    int m = 3;
    for (int j = 0; j < m; j++){
        if(1&j){
            for (int i = n - 1; i >= 0; i--){
                cout << arr[i][j] << " ";
            }
        }
        else{
            for (int i = 0; i < n; i++){
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
        return 0;
}