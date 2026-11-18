#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Level-order input se tree banata hai. "N" ka matlab NULL node.
Node* buildTree(const string& str) {
    if (str.empty() || str[0] == 'N') return NULL;

    vector<string> tokens;
    stringstream ss(str);
    string tok;
    while (ss >> tok) tokens.push_back(tok);

    Node* root = new Node(stoi(tokens[0]));
    queue<Node*> q;
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < tokens.size()) {
        Node* cur = q.front();
        q.pop();

        // left child
        if (tokens[i] != "N") {
            cur->left = new Node(stoi(tokens[i]));
            q.push(cur->left);
        }
        i++;
        if (i >= tokens.size()) break;

        // right child
        if (tokens[i] != "N") {
            cur->right = new Node(stoi(tokens[i]));
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

vector<int> zigZagTraversal(Node* root) {
    queue<Node*> q;
    vector<int> result;

    if (root == NULL) return result;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++) {
            Node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)  q.push(frontNode->left);
            if (frontNode->right) q.push(frontNode->right);
        }

        leftToRight = !leftToRight;

        for (auto x : ans) result.push_back(x);
    }
    return result;
}

int main() {
    string input;
    cout << "Enter tree (level order, N for NULL): ";
    getline(cin, input);

    Node* root = buildTree(input);
    vector<int> res = zigZagTraversal(root);

    cout << "Zigzag: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}