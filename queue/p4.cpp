#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> firstNegInt(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> ans;
    int n = arr.size();

    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }
    ans.push_back(dq.empty() ? 0 : arr[dq.front()]);

    for (int i = k; i < n; i++) {
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        if (arr[i] < 0) {
            dq.push_back(i);
        }
        ans.push_back(dq.empty() ? 0 : arr[dq.front()]);
    }
    return ans;
}

int main() {
    int n, k;

    cout << "Array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Elements daalo: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Window size k: ";
    cin >> k;

    vector<int> res = firstNegInt(arr, k);

    cout << "Result: ";
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}