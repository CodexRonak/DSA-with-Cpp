#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> reverseFirstK(queue<int> q, int k) {
    stack<int> s;
    int n = q.size();

    if (k > n) return q;

    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < n - k; i++) {
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main() {
    int n, k;

    cout << "Queue size: ";
    cin >> n;

    queue<int> q;
    cout << "Elements daalo: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    cout << "k: ";
    cin >> k;

    queue<int> res = reverseFirstK(q, k);

    cout << "Result: ";
    while (!res.empty()) {
        cout << res.front() << " ";
        res.pop();
    }
    cout << endl;

    return 0;
}