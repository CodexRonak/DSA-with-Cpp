#include <iostream>
using namespace std;

class Node{
    public:
        Node *prev;
        int data;
        Node *next;

        Node(int num){
            this->prev = NULL;
            this->data = num;
            this->next = NULL;
        }
};

void insertAtHead(Node* &head, Node* &tail, int num){
    if(head==NULL){
        Node *temp = new Node(num);
        head = temp;
        tail = temp;
        return;
    }

    Node *temp = new Node(num);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &head, Node* &tail, int num){
    if(tail==NULL){
        Node *temp = new Node(num);
        head = temp;
        tail = temp;
        return;
    }

    Node *temp = new Node(num);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

void insertAtMid(Node* &head, Node* &tail, int pos, int num){
    if(pos == 1){
        insertAtHead(head, tail, num);
        return;
    }
    

    Node *temp = new Node(num);
    Node *currNode = head;
    Node *prevNode = NULL;
    int count = 0;

    while(count < pos && currNode != NULL){
        prevNode = currNode;
        currNode = currNode->next;
        count++;
    }



    if(currNode == NULL){
        insertAtTail(head, tail, num);
        return;
    }

    temp->next = currNode;
    temp->prev = prevNode;
    prevNode->next = temp;
    currNode->prev = temp;
}


void revlist(Node* &head, Node* &tail){
    Node *f = head;
    Node *p = tail;

    while(f != p && f->prev != p){
        swap(f->data, p->data);
        f = f->next;
        p = p->prev;
    }
}


void print(Node* head){
    Node *temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl << endl;
}

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    // print(head);

    insertAtHead(head, tail, 10);
    print(head);

    insertAtHead(head, tail, 20);
    print(head);

    insertAtTail(head, tail, 40);
    print(head);

    insertAtMid(head, tail, 3, 14);
    print(head);


    // deleteNode(head, tail, 4);
    // print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
    cout << endl;
    
    revlist(head, tail);
    print(head);
    
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
    cout << endl;
}