#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElement(vector<int> &arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; i--){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        int area = 0;
        for(int i = 0; i < n; i++){
            if(next[i] == -1){
                next[i] = n;
            }
            int width = next[i] - prev[i] - 1;
            area = max(area, heights[i] * width);
        }
        return area;
    }
};

int main(){
    Solution sol;

    vector<int> h1 = {2, 1, 5, 6, 2, 3};
    vector<int> h2 = {2, 4};
    vector<int> h3 = {1};
    vector<int> h4 = {6, 2, 5, 4, 5, 1, 6};

    cout << sol.largestRectangleArea(h1) << endl;  // 10
    cout << sol.largestRectangleArea(h2) << endl;  // 4
    cout << sol.largestRectangleArea(h3) << endl;  // 1
    cout << sol.largestRectangleArea(h4) << endl;  // 12

    return 0;
}