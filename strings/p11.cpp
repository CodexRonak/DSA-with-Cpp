#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector <char> compress(vector<char> chars){
    vector<char> ans;
    int count = 1;
    for(int i = 0; i < chars.size(); i++){
        if(i+1 < chars.size() && chars[i] == chars[i+1]){
            count++;
        }
        if(count == 1 && chars[i] != chars[i+1]){
            
            ans.push_back(chars[i]);
            count = 1;
        }
        else if(chars[i] != chars[i+1]){
            ans.push_back(chars[i]);
            ans.push_back(count + '0');
            count = 1;
        }
    }
    return ans;
}

int main(){
    vector<char> str = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    vector<char> ans = compress(str);
    for(char i:ans){
        cout << i << " ";
    }
    return 0;
}