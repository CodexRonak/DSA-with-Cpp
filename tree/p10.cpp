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

void solve(Node *root, vector<int> &ans, int level) {
    if (root == NULL) return;

    if (level == ans.size()) ans.push_back(root->data);

    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

vector<int> leftView(Node *root) {
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
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
        vector<int> res = leftView(root);

        for (int x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}