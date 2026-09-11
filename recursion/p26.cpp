#include <iostream>
#include <vector>
using namespace std;

void phoneKey(string digit, vector<string> str, int index, string output, vector<string> &ans){
    if(index >= digit.length()){
        ans.push_back(output);
        return;
    }
    
    int num = digit[index] - '0';
    string value = str[num];
    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        phoneKey(digit, str, index + 1, output, ans);
        output.pop_back();
    }
}

int main(){
    vector<string> str = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int index = 0;
    string output;
    string digit = "22";
    vector<string> ans;

    phoneKey(digit, str, index, output, ans);

    for(string s : ans) {
        cout << s << " ";
    }
    return 0;
}