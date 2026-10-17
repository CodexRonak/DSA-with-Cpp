#include <iostream>
#include <vector>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};

class Solution {
  public:

    void insertAtEnd(Node* &head, Node* &tail, int num){
        Node* temp = new Node(num);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }

    Node* cloneLinkedList(Node* head) {
        if(head == NULL){
            return head;
        }

        // Step 1: clone list (data + next)
        Node* temp = head;
        Node* ansHead = NULL;
        Node* ansTemp = NULL;

        while(temp != NULL){
            insertAtEnd(ansHead, ansTemp, temp->data);
            temp = temp->next;
        }

        // Step 2: interleave original and clone nodes
        Node* originalNode = head;
        Node* cloneNode = ansHead;

        while(originalNode != NULL){
            Node* forward = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = forward;

            forward = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = forward;
        }

        // Step 3: set random pointers of clones
        temp = head;
        while(temp != NULL){
            if(temp->next != NULL){
                temp->next->random = temp->random
                    ? temp->random->next : NULL;
            }
            temp = temp->next->next;
        }

        // Step 4: separate the two lists
        originalNode = head;
        cloneNode = ansHead;

        while(originalNode != NULL && cloneNode != NULL){
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if(originalNode != NULL){
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }

        return ansHead;
    }
};

// ---------- Helpers for testing ----------

void printList(Node* head, const string& name) {
    cout << name << ":\n";
    for(Node* t = head; t != NULL; t = t->next){
        cout << "  data=" << t->data << "  addr=" << t
             << "  random=";
        if(t->random) cout << t->random->data;
        else cout << "NULL";
        cout << "\n";
    }
}

int main() {
    // Input format:
    // n
    // n values (data)
    // n random indices (0-based, -1 for NULL)
    // Example:
    // 4
    // 1 2 3 4
    // 2 0 -1 1
    int n;
    cout << "Enter n: ";
    cin >> n;

    if(n <= 0){
        cout << "Empty list\n";
        return 0;
    }

    vector<Node*> nodes(n);
    cout << "Enter " << n << " values: ";
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        nodes[i] = new Node(x);
    }
    for(int i = 0; i + 1 < n; i++){
        nodes[i]->next = nodes[i + 1];
    }

    cout << "Enter " << n << " random indices (-1 for NULL): ";
    for(int i = 0; i < n; i++){
        int idx;
        cin >> idx;
        nodes[i]->random = (idx >= 0 && idx < n) ? nodes[idx] : NULL;
    }

    Node* head = nodes[0];

    Solution sol;
    Node* cloned = sol.cloneLinkedList(head);

    cout << "\n";
    printList(head, "Original");
    cout << "\n";
    printList(cloned, "Clone");

    // Verify the clone is a deep copy (different addresses)
    bool deep = true;
    for(Node *a = head, *b = cloned; a && b; a = a->next, b = b->next){
        if(a == b || (a->random && a->random == b->random)) deep = false;
    }
    cout << "\nDeep copy check: " << (deep ? "PASS" : "FAIL") << "\n";

    return 0;
}