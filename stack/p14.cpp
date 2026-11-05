#include <bits/stdc++.h>
using namespace std;

class NStack
{
public:
    int *arr;
    int *next;
    int *top;
    int n, s;
    int freespot;

    NStack(int N, int S)
    {
        n = N;
        s = S;

        arr = new int[s];
        next = new int[s];
        top = new int[n];

        memset(top, -1, n * sizeof(int));

        for(int i = 0; i < s; i++){
            next[i] = i + 1;
        }
        next[s - 1] = -1;
        freespot = 0;
    }

    ~NStack()
    {
        delete[] arr;
        delete[] next;
        delete[] top;
    }

    // Pushes x into the mth stack (1-indexed)
    bool push(int x, int m)
    {
        if(freespot == -1){
            return false;           // overflow
        }

        int index = freespot;
        arr[index] = x;
        freespot = next[index];

        next[index] = top[m - 1];
        top[m - 1] = index;
        return true;
    }

    // Pops from mth stack, returns -1 if empty
    int pop(int m)
    {
        if(top[m - 1] == -1){
            return -1;              // underflow
        }

        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};

int main()
{
    int N, S, q;
    cout << "Enter N (stacks), S (array size), Q (queries): ";
    cin >> N >> S >> q;

    NStack st(N, S);

    cout << "Query format:\n  1 x m  -> push x in stack m\n  2 m    -> pop from stack m\n";

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x, m;
            cin >> x >> m;
            cout << (st.push(x, m) ? "true" : "false") << endl;
        } else {
            int m;
            cin >> m;
            cout << st.pop(m) << endl;
        }
    }
    return 0;
}