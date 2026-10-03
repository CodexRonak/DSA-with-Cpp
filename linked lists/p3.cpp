#include <iostream>
using namespace std;


// Circular Linked List
class Node{
    public:
        Node *next;
        int data;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


void insertNode(Node* &tail, int ele, int num){
    if(tail == NULL){
        Node *newNode = new Node(num);
        tail = newNode;
        newNode->next = newNode; 
        return;
    }
    Node *curr = tail;

    while(curr->data != ele){
        curr = curr->next;
    }

    Node *temp = new Node(num);
    temp->next = curr->next;
    curr->next = temp;
}

void deleteNode(Node* &tail, int val){
    Node *prev = tail;
    // Empty List
    if(tail == NULL){
        return;
    }


    while(prev->next->data == val){
        prev = prev->next;
    }

    Node *curr = prev->next;

    prev->next = curr->next;
    if(tail == curr){
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
}

void print(Node* tail){
    if(tail == NULL){
        return;
    }
    Node *temp = tail;
    do{
        cout << tail->data << " ";
        tail = tail->next;
    } while (temp != tail);
    cout << endl << endl;
}

int main(){
    Node *tail = NULL;
    insertNode(tail, 1, 10);
    print(tail);

    insertNode(tail, 10, 20);
    print(tail);

    deleteNode(tail, 10);
    print(tail);
    return 0;
}
