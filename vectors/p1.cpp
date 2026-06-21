#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vec = {2, 3, 1, 4};
    int tar = 1;
    for (size_t i=0; i < vec.size(); i++){
        if(vec[i]==tar){
            cout << "index: " << i;
            break;
        }
    }
    return 0;
}