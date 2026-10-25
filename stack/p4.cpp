#include <iostream>
#include <stack>
using namespace std;

// reversing using string
int main(){
    string str = "ronak";
    stack<char> s;

    string ans = "";

    for (int i = 0; i < str.length(); i++){
        char ch = str[i];
        s.push(ch);
    }

    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);

        s.pop();
    }

    cout << ans << endl;
    return 0;
}