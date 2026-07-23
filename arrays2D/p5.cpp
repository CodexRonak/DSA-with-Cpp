#include <iostream>
#include <vector>
using namespace std;

vector<int> rotateMatrix(vector<vector<int>> arr, int n, int m){
    vector<int> ans;
    for (int j = 0; j < m; j++){
        for (int i = n - 1; i >= 0; i--){
            ans.push_back(arr[i][j]);
        }
    }
    return ans;
}


int main(){
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = arr.size();
    int m = arr[0].size();
    vector<int> ans = rotateMatrix(arr, n, m);
    // n will m and m will be m
    for (int i = 0; i < n*m; i++){
        cout << ans[i] << " ";
        if((i + 1) % n == 0){
            cout << endl;
        }
    }
    return 0;
}