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

vector<int> bottomView(Node *root) {
    vector<int> ans;
    if (root == NULL) return ans;

    map<int, int> bottomNode;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        bottomNode[hd] = frontNode->data;   // overwrite every time

        if (frontNode->left)  q.push(make_pair(frontNode->left, hd - 1));
        if (frontNode->right) q.push(make_pair(frontNode->right, hd + 1));
    }

    for (auto i : bottomNode)
        ans.push_back(i.second);

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
        vector<int> res = bottomView(root);

        for (int x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}