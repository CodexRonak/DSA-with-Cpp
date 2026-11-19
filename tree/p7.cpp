#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalOrder(Node *root) {
    map<int, map<int, vector<int>>> node;
    queue<pair<Node*, pair<int, int>>> q;
    vector<vector<int>> ans;

    if (root == NULL) return ans;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty()) {
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        node[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
    }

    for (auto &i : node) {
        vector<int> col;
        for (auto &j : i.second)
            for (auto &k : j.second)
                col.push_back(k);
        ans.push_back(col);
    }
    return ans;
}

int main() {
    //        1
    //       / \
    //      2   3
    //     / \ / \
    //    4  5 6  7
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> res = verticalOrder(root);
    for (auto &col : res) {
        for (int x : col) cout << x << " ";
        cout << "\n";
    }
    return 0;
}