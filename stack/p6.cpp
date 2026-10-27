#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }

    int num = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(num);
}

void reverseStack(stack<int> &st) {
    if(st.empty()) return;

    int num = st.top();
    st.pop();
    reverseStack(st);

    insertAtBottom(st, num);
}

int main(){
    stack<int> st;
    //  4 3 2 1
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);   // top = 4

    reverseStack(st);

    // top se bottom print karo
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}