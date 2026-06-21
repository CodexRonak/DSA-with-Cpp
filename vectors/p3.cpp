// pair sum
#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> &vec, int target){
    int end = vec.size()-1;
    int start = 0;
    vector<int> ans;
    vector<int> indices;
    while(start < end){

        if((vec[start]+vec[end])>target){
            end--;
        }
        else if((vec[start]+vec[end])<target){
            start++;
        }
        else{
            cout << "indices: " << start << "," << end << endl;
            ans.push_back(vec[start]);
            ans.push_back(vec[end]);
            return ans;
        }
        
    }
    return {};
}

int main(){
    vector<int> vec = {2, 3, 11, 15};
    int target = 13;

    vector<int> ans = pairSum(vec, target);
    cout  << "values: "<< ans[0] << ","<< ans[1];
    return 0;
}