#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

Node* buildTree(const string& line) {
    if (line.empty() || line[0] == 'N') return NULL;

    stringstream ss(line);
    string tok;
    ss >> tok;

    Node* root = new Node(stoi(tok));
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        if (!(ss >> tok)) break;
        if (tok != "N") {
            cur->left = new Node(stoi(tok));
            q.push(cur->left);
        }

        if (!(ss >> tok)) break;
        if (tok != "N") {
            cur->right = new Node(stoi(tok));
            q.push(cur->right);
        }
    }
    return root;
}

void solve(Node *root, int len, int &maxLen, int sum, int &maxSum) {
    if (root == NULL) {
        if (len > maxLen) {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen) {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum = sum + root->data;

    solve(root->left, len + 1, maxLen, sum, maxSum);
    solve(root->right, len + 1, maxLen, sum, maxSum);
}

int sumOfLongRootToLeafPath(Node *root) {
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, len, maxLen, sum, maxSum);
    return maxSum;
}

int main() {
    int t;
    cout << "Number of test cases: ";
    cin >> t;
    cin.ignore();

    while (t--) {
        string line;
        cout << "Enter level order (N for null): ";
        getline(cin, line);

        Node* root = buildTree(line);
        cout << sumOfLongRootToLeafPath(root) << "\n";
    }
    return 0;
}