#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int num){
            this->data = num;
            this->next = NULL;
        }
};

void insertAtHead(Node* &head, Node* &tail, int num){
    if(head == NULL){
        Node *temp = new Node(num);
        head = temp;
        tail = head;
        return;
    }

    Node *temp = new Node(num);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, Node* &tail, int num){
    if(tail == NULL){
        insertAtHead(head, tail, num);
        return;
    }

    Node *temp = new Node(num);
    tail->next = temp;
    tail = temp;
}

void insertAtMid(Node* &head, Node* &tail, int pos, int num){
    if(head == NULL || pos == 1){
        insertAtHead(head, tail, num);
        return;
    }

    Node *prev = head;
    int count = 1;
    while(count < pos - 1 && prev != NULL){
        prev = prev->next;
        count++;
    }

    if(prev == NULL){
        return;
    }

    Node *temp = new Node(num);
    temp->next = prev->next;
    prev->next = temp;

    // Agar last node ke baad insert hua hai, toh tail update karein
    if(temp->next == NULL){
        tail = temp;
    }
}

// appraoch 1
void revList(Node* &head){
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

// approach 2
void recRevList(Node* &head, Node* curr, Node* prev){
    if(curr == NULL){
        head = prev;
        return;
    }

    Node *forward = curr->next;
    curr->next = prev;
    recRevList(head, forward, curr);
}

// appraoch 3

Node* rev(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node *subhead = rev(head->next);
    head->next->next = head;
    head->next = NULL;
    return subhead;
}

void print(Node* head){
    Node *temp = head;

    cout << endl;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 12);
    print(head);
    
    insertAtHead(head, tail, 15);
    print(head);

    insertAtTail(head, tail, 22);
    print(head);
    
    insertAtMid(head, tail, 3, 44);
    print(head);

    insertAtMid(head, tail, 1, 94);
    print(head);

    cout << "Head->" << head->data << endl;
    cout << "Tail->" << tail->data << endl;

    cout << endl;

    // revList(head);
    // recRevList(head, head, NULL);
    head = rev(head);
    print(head);
    return 0;
}
