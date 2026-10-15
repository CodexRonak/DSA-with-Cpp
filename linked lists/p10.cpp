#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

void solve(Node<int>* first, Node<int>* second) {
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1->next;
    Node<int>* curr2 = second;

    while (next1 != NULL && curr2 != NULL) {
        if (curr2->data >= curr1->data && curr2->data <= next1->data) {
            Node<int>* next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        } else {
            curr1 = next1;
            next1 = next1->next;
        }
    }

    if (next1 == NULL) {
        curr1->next = curr2;
    }
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    if (first == NULL) return second;
    if (second == NULL) return first;

    if (first->data <= second->data) {
        solve(first, second);
        return first;
    } else {
        solve(second, first);
        return second;
    }
}

Node<int>* buildList(int n) {
    Node<int>* head = NULL;
    Node<int>* tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node<int>* newNode = new Node<int>(x);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(Node<int>* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, m;

    cout << "First list size: ";
    cin >> n;
    cout << "First list elements (sorted): ";
    Node<int>* first = buildList(n);

    cout << "Second list size: ";
    cin >> m;
    cout << "Second list elements (sorted): ";
    Node<int>* second = buildList(m);

    Node<int>* result = sortTwoLists(first, second);

    cout << "Merged list: ";
    printList(result);

    delete result;
    return 0;
}