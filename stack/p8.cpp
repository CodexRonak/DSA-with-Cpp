#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for(int i = 0; i < s.length(); i++){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else if(ch == ')'){
            bool isRedundant = true;

            while(st.top() != '('){
                char top = st.top();
                if(top == '+' || top == '-' || top == '*' || top == '/'){
                    isRedundant = false;
                }
                st.pop();
            }
            st.pop();   // '(' hatao

            if(isRedundant){
                return true;
            }
        }
        // letters/digits ignore
    }
    return false;
}

int main(){
    string a = "((a+b))";
    string b = "(a+b)";
    string c = "(a*(b+c))";
    string d = "((a))";

    cout << findRedundantBrackets(a) << endl;  // 1
    cout << findRedundantBrackets(b) << endl;  // 0
    cout << findRedundantBrackets(c) << endl;  // 0
    cout << findRedundantBrackets(d) << endl;  // 1
    return 0;
}