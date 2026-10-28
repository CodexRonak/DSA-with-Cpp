#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &st, int ele){
    if(st.empty() || st.top() <= ele){
        st.push(ele);
        return;
    }

    int num = st.top();
    st.pop();
    solve(st, ele);
    st.push(num);
}

void sortStack(stack<int> &st){
    if(st.empty()) return;

    int num = st.top();
    st.pop();
    sortStack(st);
    solve(st, num);
}

int main(){
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);   // top = 2

    sortStack(st);

    // top se bottom print karo
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}