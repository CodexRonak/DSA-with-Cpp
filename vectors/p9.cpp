#include<iostream>
#include <vector>
using namespace std;

vector<int> rotateArr(vector<int> arr, int k){
    int n = arr.size();
    vector<int> temp(n);
    for (int i = 0; i < n; i++){
        temp[(i + k) % n] = arr[i];
    }
    return arr = temp;
}

int main(){
    vector<int> vec = {1, 2, 3, 4, 5};
    int k = 2;
    vec = rotateArr(vec, k);
        for (int i = 0; i < vec.size(); i++){
        cout << vec[i] <<" ";
    }
    return 0;
}