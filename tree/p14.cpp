#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void solve(Node *root, int k, long long currSum,
           unordered_map<long long,int> &freq, int &count) {
    if (!root) return;

    currSum += root->data;
    if (freq.count(currSum - k)) count += freq[currSum - k];

    freq[currSum]++;
    solve(root->left, k, currSum, freq, count);
    solve(root->right, k, currSum, freq, count);
    freq[currSum]--;  // backtrack
}

int countAllPaths(Node *root, int k) {
    unordered_map<long long,int> freq;
    freq[0] = 1;
    int count = 0;
    solve(root, k, 0, freq, count);
    return count;
}

int main() {
    //        1
    //       / \
    //      2   3
    //     / \
    //    1   2
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(2);

    cout << countAllPaths(root, 3) << endl;  // expected: 3 (1->2, 2->1, 3)
    return 0;
}