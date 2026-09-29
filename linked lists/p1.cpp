#include <iostream>
using namespace std;

// Singley Linked List

// node creation
class Node{
public:
    // node values
    int data;
    Node *next;
    
    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int num){
    Node *temp = new Node(num);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int num){
    Node *temp = new Node(num);
    tail->next = temp;
    tail = tail->next;
}

void insertAtMid(Node* &head, Node* &tail, int pos, int num){

    // inserting at head
    if (pos == 1){
        insertAtHead(head, num);
        return;
    }
    
    // node traversal
    Node *temp = head;
    int count = 1;

    while(count < pos-1){
        temp = temp->next;
        count++;
    }

    // inserting at tail
    if(tail->next == NULL){
        insertAtTail(tail, num);
        return;
    }

    Node *nodeToInsert = new Node(num);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head, Node* &tail, int pos){

    if(pos == 1){
        Node *temp = head;
        head = temp->next;
        return;
    }
    else{
        Node *currentNode = head;
        Node *previousNode = NULL;

        int count = 1;
        while(count < pos){
            previousNode = currentNode;
            currentNode = currentNode->next;
            count++;
        }
        previousNode->next = currentNode->next;
        if(currentNode->next == NULL){
            tail = previousNode;
        }
        currentNode->next = NULL;
        delete currentNode;

    }

}

void print(Node* &head){
    Node *temp = head;

    cout << endl;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main(){
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, 12);
    print(head);
    
    insertAtHead(head, 15);
    print(head);

    insertAtTail(tail, 22);
    print(head);
    
    insertAtMid(head, tail, 3, 44);
    print(head);

    insertAtMid(head, tail, 1, 94);
    print(head);

    cout << "Head->" << head->data << endl;
    cout << "Tail->" << tail->data << endl;
    
    deleteNode(head, tail, 6);
    print(head);
    
    cout << "Head->" << head->data << endl;
    cout << "Tail->" << tail->data << endl;
    deleteNode(head, tail, 5);
    print(head);

}