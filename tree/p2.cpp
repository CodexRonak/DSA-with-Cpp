#include <iostream>
#include <algorithm>
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

// first = diameter, second = height
pair<int, int> diameterfast(Node* root) {
    if (root == NULL) {
        return make_pair(0, 0);
    }

    pair<int, int> left = diameterfast(root->left);
    pair<int, int> right = diameterfast(root->right);

    int op1 = left.first;                    // diameter sirf left subtree mein
    int op2 = right.first;                   // diameter sirf right subtree mein
    int op3 = left.second + right.second;    // diameter root se hokar guzre (edges mein)

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(Node* root) {
    return diameterfast(root).first;
}

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Diameter: " << diameter(root) << endl;
    return 0;
}