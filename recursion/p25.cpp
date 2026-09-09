#include <iostream>
#include <vector>
using namespace std;

void subString(string str, size_t index, string output, vector<string>& ans){
    if(index >= str.length()){
        if(output.length() > 0){
            ans.push_back(output);
        }
        return;
    }
    //  exclude
    subString(str, index + 1, output, ans);
    
    // include
    char elem = str[index];
    output.push_back(elem);
    subString(str, index + 1, output, ans);
}


int main(){
    string str = "abc";
    int index = 0;
    vector<string> ans;
    string output = "";

    subString(str, index, output, ans);

    for(const auto& i : ans){
        cout << "[";
        cout << i;
        cout << "] ";
    }
    return 0;
}