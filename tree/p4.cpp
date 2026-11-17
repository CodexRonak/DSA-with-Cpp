#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

// pair.first = sum tree hai ya nahi, pair.second = subtree ke saare nodes ka sum
pair<bool, int> isSumTreeFast(Node* root) {
    if (root == NULL) {
        return make_pair(true, 0);
    }

    if (root->left == NULL && root->right == NULL) {
        return make_pair(true, root->data);
    }

    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;
    bool condn = (root->data == leftAns.second + rightAns.second);

    pair<bool, int> ans;

    if (left && right && condn) {
        ans.first = true;
        ans.second = 2 * root->data;
    } else {
        ans.first = false;
        ans.second = 0;
    }
    return ans;
}

bool isSumTree(Node* node) {
    return isSumTreeFast(node).first;
}

// Level order input se tree banana (-1 matlab NULL)
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
    cout << "Enter the no. of Values ";
    cin >> n;

    vector<int> arr(n);
    cout << "Level order values (-1 = NULL): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* root = buildTree(arr);

    if (isSumTree(root))
        cout << "Sum Tree" << endl;
    else
        cout << "Not a sum Tree" << endl;

    return 0;
}