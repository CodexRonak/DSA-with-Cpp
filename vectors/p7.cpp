#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v = {2, 3, 4, 1, 6, 2}, ans;
    sort(v.begin(), v.end());
    int tar = 12;
    int n = v.size() - 1;
    for (int i = 0; i < n; i++){
        int newTar = tar - v[i];
        int start = 0, end = v.size() - 1;
        
        while(start<end){
            if (v[start] + v[end] == newTar){
                ans.push_back(v[i]);
                ans.push_back(v[start]);
                ans.push_back(v[end]);
                start++;
                end--;
                break;
            }
            else if(v[start] + v[end] > newTar){
                end--;
            }
            else{
                start++;
            }
        }
        if(!ans.empty()) {
            break;
        }
    }
    
    if(ans.size()!=0){
        for (int i : ans){
            cout << i << " ";
        }
    }
    else{
        cout << -1;
    }

        return 0;
}