#include <iostream>
#include <queue>
using namespace std;

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        if (q.empty()) {
            return;
        }

        int num = q.front();
        q.pop();

        reverseQueue(q);
        q.push(num);
    }
};

int main() {
    queue<int> q;
    int n;

    cout << "no. of elements? ";
    cin >> n;

    cout << "Enter Elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    Solution obj;
    obj.reverseQueue(q);

    cout << "Reversed queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}