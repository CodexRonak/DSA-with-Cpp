#include <iostream>
#include <vector>
using namespace std;

void subset(vector<int> arr, int index, vector<int> output, vector<vector<int>>& ans){
    if(index >= arr.size()){
        ans.push_back(output);
        return ;
    }

    // exclude
    subset(arr, index + 1, output, ans);
    
    //  include
    int element = arr[index];
    output.push_back(element);
    subset(arr, index + 1, output, ans);

}

int main(){

    vector<int> arr = {1, 2, 3};
    int index = 0;
    vector<vector<int>> ans;
    vector<int> output;
    subset(arr, index, output, ans);

    for(const auto& i:ans){
        cout <<"[";
        for(int j:i){
            cout << j << "";
        }
        cout <<"]";
        cout << " ";
    }

    return 0;
}