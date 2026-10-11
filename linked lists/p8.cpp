#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node *removeDuplicates(Node *head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }

    unordered_set<int> visited;
    Node* curr = head;
    Node* pre = NULL;

    while(curr != NULL){
        if(visited.count(curr->data)){
            Node* del = curr;
            pre->next = curr->next;
            curr = curr->next;
            delete del;
        }
        else{
            visited.insert(curr->data);
            pre = curr;
            curr = curr->next;
        }
    }
    return head;
}

void printList(Node* head){
    while(head != NULL){
        cout << head->data;
        if(head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Kitne nodes? ";
    cin >> n;

    cout << "Values likho (space se alag): ";
    Node* head = NULL;
    Node* tail = NULL;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        Node* temp = new Node(x);
        if(head == NULL){
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    cout << "Pehle : ";
    printList(head);

    head = removeDuplicates(head);

    cout << "Baad me: ";
    printList(head);

    // memory free
    while(head != NULL){
        Node* t = head;
        head = head->next;
        delete t;
    }
    return 0;
}