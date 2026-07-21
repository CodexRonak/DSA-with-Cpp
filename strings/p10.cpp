#include <iostream>
#include <string>
using namespace std;

string removeDup(string str){
    int n = str.length();
    string ans = "";
    for (int i = 0; i < n; i++){
        if(ans.back() == str[i] && ans.length() > 0){
            // int times = 2;
            ans.pop_back();
        }else{
            ans.push_back(str[i]);
        }
    }
    return ans;
}

int main(){
    string str = "abbccba";
    cout << removeDup(str) << endl;
    return 0;
}