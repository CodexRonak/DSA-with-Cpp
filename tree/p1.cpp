#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    
    if(data == -1){
        return NULL;
    }
    root = new Node(data);

    cout << "Enter the left node data: " << endl;
    root->left = buildTree(root->left);
    cout << "Enter the right node data: " << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root){

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp->data << " ";

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

void inOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
void preOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void buildTreeFromLevelOrder(Node* &root){
    queue<Node *> q;
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        cout << "Enter the left data for " << temp->data << endl;
        int leftdata;
        cin >> leftdata;

        if(leftdata != -1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter the right data for " << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if(rightdata != -1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}

int height(Node* root) {
    if (root == NULL) {
        return -1;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

int main(){
    Node *root = NULL;
    // root = buildTree(root);
    buildTreeFromLevelOrder(root);
    levelOrderTraversal(root);

    // cout << endl << "Inorder Traversal" << endl;
    // inOrderTraversal(root);
    // cout << endl << "Preorder Traversal" << endl;
    // preOrderTraversal(root);
    // cout << endl << "Postorder Traversal" << endl;
    // postOrderTraversal(root);

    cout << "Height: " << height(root) << endl;
    return 0;
}
