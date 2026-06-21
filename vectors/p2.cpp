#include<iostream>
#include<vector>
using namespace std;
void revVec(vector <int> &vec){
    int start = 0;
    int end =  vec.size()-1;
    for(int i:vec){
        if(start<end){
            swap(vec[start], vec[end]);
        }
        start++;
        end--;
    }
    // for (int i = 0; i < end; i++){
    //     if(start<end){
    //         swap(vec[start], vec[end]);
    //     }
    //     start++;
    //     end--;
    // }
    // for(int i:vec){
    //     cout << i << " ";
    // }
}

int main(){
    vector<int> vec = {3, 21, 32, 1};
    revVec(vec);
    for(int i:vec){
        cout << i << " ";
    }
    return 0;
}