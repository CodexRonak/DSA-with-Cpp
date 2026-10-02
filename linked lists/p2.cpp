#include <iostream>
using namespace std;

// Doubley Linked List

class Node{
    public:
        Node *prev;
        int data;
        Node *next;
    
    Node(int data){
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
    
    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory Free: " << val << endl;
    }
};

void insertAtStart(Node *&head, Node* &tail, int num){
    if(head == NULL){
        Node *temp = new Node(num);
        head = temp;
        tail = temp;
    }
    else{
        Node *temp = new Node(num);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtEnd(Node *&head, Node* &tail, int num){
    if(tail == NULL){
        Node *temp = new Node(num);
        head = temp;
        tail = temp;
    }
    else{
        Node *temp = new Node(num);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtMid(Node* &head, Node* &tail, int pos, int num){
    if(pos == 1){
        insertAtStart(head, tail, num);
        return;
    }
    

    Node *temp = head;
    int count = 1;
    while(count<pos-1){
        temp = temp->next;
        count++;
    }

    if(temp->next==NULL){
        insertAtEnd(head, tail, num);
        return;
    }

    Node *nodeToInsert = new Node(num);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;

}


void deleteNode(Node* &head, Node* &tail, int pos){
    if(head == NULL){
        return;
    }

    // Case 1: First node delete karni hai
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        
        if(head != NULL){
            head->prev = NULL;
        } else {
            tail = NULL; // List completely empty ho gayi
        }
        
        temp->next = NULL;
        delete temp;
        return;
    }

    // Case 2: Middle ya Last node delete karni hai
    Node *currNode = head;
    Node *prevNode = NULL;
    int count = 1;
    
    while(count < pos && currNode != NULL){
        prevNode = currNode;
        currNode = currNode->next;
        count++;
    }

    // Safety check: Agar position list ki length se badi hai
    if(currNode == NULL){
        cout << "Position out of range!" << endl;
        return;
    }

    // Case 2.1: Last node delete karni hai
    if(currNode->next == NULL){
        tail = prevNode;
        prevNode->next = NULL;
        currNode->prev = NULL;
        delete currNode;
        return; // <--- Yeh return zaroori hai!
    }

    // Case 2.2: Beech ki node delete karni hai
    prevNode->next = currNode->next;
    currNode->next->prev = prevNode;
    currNode->prev = NULL;
    currNode->next = NULL;
    delete currNode;
}

void print(Node* &head){

    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl << endl;
    return;
}



int main(){

    Node *head = NULL;
    Node *tail = NULL;

    print(head);

    insertAtStart(head, tail, 10);
    print(head);

    insertAtStart(head, tail, 20);
    print(head);

    insertAtEnd(head, tail, 40);
    print(head);

    insertAtMid(head, tail, 3, 14);
    print(head);

    deleteNode(head, tail, 4);
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
    cout << endl;
}
