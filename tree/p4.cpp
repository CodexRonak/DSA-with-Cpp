#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

// Function: pair.first = diameter, pair.second = height
pair<int, int> diameterfast(Node* root) {
    if (root == NULL) {
        return make_pair(0, 0);
    }

    pair<int, int> left = diameterfast(root->left);
    pair<int, int> right = diameterfast(root->right);

    int op1 = left.first;                    // diameter sirf left subtree me
    int op2 = right.first;                   // diameter sirf right subtree me
    int op3 = left.second + right.second;    // diameter root se guzre

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(Node* root) {
    return diameterfast(root).first;
}


Node* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < (int)arr.size()) {
        Node* curr = q.front();
        q.pop();

        if (i < (int)arr.size() && arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < (int)arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    int n;
    cout << "Enter the no. of values: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Level order values (-1 = NULL): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* root = buildTree(arr);
    cout << "Diameter = " << diameter(root) << endl;

    return 0;
}