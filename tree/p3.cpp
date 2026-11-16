#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <utility>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// first = balanced hai ya nahi, second = height
pair<bool, int> isBalancedFast(Node* root) {
    if (root == NULL) {
        return make_pair(true, 0);
    }

    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (leftAns && rightAns && diff) {
        ans.first = true;
    }
    else {
        ans.first = false;
    }
    return ans;
}

bool isBalanced(Node* root) {
    return isBalancedFast(root).first;
}

int main() {
    /* Tree 1 (balanced)
            1
           / \
          2   3
         / \
        4   5
    */
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    /* Tree 2 (unbalanced)
            1
           /
          2
         /
        3
    */
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    cout << "Tree 1: " << (isBalanced(root1) ? "Balanced" : "Not Balanced") << endl;
    cout << "Tree 2: " << (isBalanced(root2) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}