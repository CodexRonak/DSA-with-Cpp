//  Majority elements
#include<iostream>
#include<vector>
using namespace std;

vector<int> majorityElements(vector<int> &vec){
    int count = 0, ans = 0;
    vector<int> res;
    for (int i = 0; i < vec.size(); i++){
        if (count == 0){
            ans = vec[i];
        }
        if (ans == vec[i]){
            count++;
        } else {
            count--;
        }
    }
    res.push_back(ans);
    return res;
}

int main(){
    vector<int> vec = {6,5,5};
    vector<int> res = majorityElements(vec);
    for(int i:res){
        cout << i << " ";
    }
}