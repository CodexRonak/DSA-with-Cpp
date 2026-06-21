// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: [3]
// Example 2:

// Input: nums = [1]
// Output: [1]
// Example 3:

// Input: nums = [1,2]
// Output: [1,2]

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> nums = {2, 2, 1, 1, 2};
    int freq1 = 0, ans1 = 0, freq2 = 0, ans2 = 0;
        for(int i:nums){
            if(ans1==i){
                freq1++;
            }else if(ans2==i){
                freq2++;
            }
            else if(freq1==0){
                ans1=i;
                freq1 = 1;
            }else if(freq2==0){
                ans2=i;
                freq2 = 1;
            }else{
                freq1--;
                freq2--;
            }
        }

        freq1 = 0;
        freq2 = 0;
        for(int i:nums){
            if(ans1==i){
                freq1++;
            }
            else if(ans2==i){
                freq2++;
            }
        }

        vector<int> ans;
        if (freq1 > nums.size() / 3) ans.push_back(ans1);
        if (freq2 > nums.size() / 3) ans.push_back(ans2);
        for (int i : ans)
        {
            cout << i << " ";
        }
        
    return 0;
}