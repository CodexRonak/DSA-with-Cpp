#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Level-order input se tree banata hai. "N" = NULL.
// "1 2 3 N 4" aur "[1, 2, 3, N, 4]" dono format chalte hain.
Node* buildTree(string str) {
    for (char &c : str) {
        if (c == '[' || c == ']' || c == ',') c = ' ';
    }

    vector<string> tokens;
    stringstream ss(str);
    string tok;
    while (ss >> tok) tokens.push_back(tok);

    if (tokens.empty() || tokens[0] == "N") return NULL;

    Node* root = new Node(stoi(tokens[0]));
    queue<Node*> q;
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < tokens.size()) {
        Node* cur = q.front();
        q.pop();

        if (tokens[i] != "N") {
            cur->left = new Node(stoi(tokens[i]));
            q.push(cur->left);
        }
        i++;
        if (i >= tokens.size()) break;

        if (tokens[i] != "N") {
            cur->right = new Node(stoi(tokens[i]));
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

// ---------- Aapka solution ----------

void traverseLeft(Node *root, vector<int> &ans) {
    if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
        return;
    }

    ans.push_back(root->data);

    if (root->left) traverseLeft(root->left, ans);
    else traverseLeft(root->right, ans);
}

void traverseLeaf(Node *root, vector<int> &ans) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans) {
    if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
        return;
    }

    if (root->right) traverseRight(root->right, ans);
    else traverseRight(root->left, ans);

    ans.push_back(root->data);
    return;
}

vector<int> boundaryTraversal(Node *root) {
    vector<int> ans;
    if (root == NULL) return ans;
    ans.push_back(root->data);

    if (root->left == NULL && root->right == NULL) return ans;

    traverseLeft(root->left, ans);
    traverseLeaf(root, ans);
    traverseRight(root->right, ans);

    return ans;
}

// ---------- Driver ----------

int main() {
    string input;
    cout << "Enter tree (level order, N for NULL): ";
    getline(cin, input);

    Node* root = buildTree(input);
    vector<int> res = boundaryTraversal(root);

    cout << "Boundary: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}