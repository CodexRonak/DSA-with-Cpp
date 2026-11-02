#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool know(vector<vector<int>>& mat, int a, int b){
        return mat[a][b] == 1;
    }

    int celebrity(vector<vector<int>>& mat) {
        stack<int> s;
        int n = mat.size();

        for(int i = 0; i < n; i++){
            s.push(i);
        }

        while(s.size() > 1){
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if(know(mat, a, b)){
                s.push(b);   // a celebrity nahi ho sakta
            }
            else{
                s.push(a);   // b celebrity nahi ho sakta
            }
        }

        int ans = s.top();

        // row check: celebrity kisi ko nahi jaanta (diagonal bhi 0)
        int zeroCount = 0;
        for(int i = 0; i < n; i++){
            if(mat[ans][i] == 0){
                zeroCount++;
            }
        }
        if(zeroCount != n){
            return -1;
        }

        // column check: baaki sab celebrity ko jaante hain
        int oneCount = 0;
        for(int i = 0; i < n; i++){
            if(mat[i][ans] == 1){
                oneCount++;
            }
        }
        if(oneCount != n - 1){
            return -1;
        }

        return ans;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> m1 = {{0,1,0},
                              {0,0,0},
                              {0,1,0}};
    vector<vector<int>> m2 = {{0,1},
                              {1,0}};
    vector<vector<int>> m3 = {{0}};

    cout << sol.celebrity(m1) << endl;  // 1
    cout << sol.celebrity(m2) << endl;  // -1
    cout << sol.celebrity(m3) << endl;  // 0

    return 0;
}