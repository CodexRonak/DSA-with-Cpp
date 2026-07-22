#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> matrix, int n, int m){
        vector<int> ans;
        // int n = matrix.size();
        // int m = matrix[0].size();

        int rowStart = 0, rowEnd = n - 1;
        int colStart = 0, colEnd = m - 1;

        while(rowStart <= rowEnd && colStart <= colEnd){
            
            // row-> left to right
            for(int i = colStart; i <= colEnd; i++){
                ans.push_back(matrix[rowStart][i]);
            }
            rowStart++;

            // col-> top to bottom
            for (int i = rowStart; i <= rowEnd; i++){
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            
            //row-> right to left
            if(rowStart <= rowEnd){
                for(int i = colEnd; i >= colStart; i--){
                    ans.push_back(matrix[rowEnd][i]);
                }
                rowEnd--;
            }

            // col-> bottom to top
            if(colStart <= colEnd){
                for(int i = rowEnd; i >= rowStart; i--){
                    ans.push_back(matrix[i][colStart]);
                }
                colStart++;
            }
        }
        return ans;
}

int main(){
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 3;
    int m = 3;
    vector<int> ans = spiralMatrix(arr, n, m);
    for (int val : ans){
        cout << val << " ";
    }
    return 0;
}