#include <bits/stdc++.h>
using namespace std;

void solve(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();
    solve(myStack, x);

    myStack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x){
    solve(myStack, x);
    return myStack;
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);   // top = 3

    int x = 9;
    stack<int> res = pushAtBottom(st, x);

    // top se bottom print karo
    while(!res.empty()){
        cout << res.top() << " ";
        res.pop();
    }
    cout << endl;
    return 0;
}