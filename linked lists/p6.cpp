#include <iostream>
using namespace std;

class Node{
    public:
        Node* prev;
        int data;
        Node *next;

        Node(int num){
            this->prev = NULL;
            this->data = num;
            this->next = NULL;
        }

        ~Node(){
            int val = this->data;
            cout << "Memory free " << val << endl;
        }
};

void insertNode(Node* &tail, int val, int num){
    if(tail == NULL){
        Node *temp = new Node(num);
        tail = temp;
        tail->prev = temp;
        tail->next = temp;
        return;
    }

    Node *currNode = tail->next;
    Node *nextNode = NULL;

    while(currNode->data != val && currNode ->next != tail){
        currNode = currNode->next;
    }
    nextNode = currNode->next;

    if(currNode->data != val){
        cout << "Value not found!" << endl;
        return;
    }

    Node *temp = new Node(num);
    currNode->next = temp;
    temp->prev = currNode;
    temp->next = nextNode;
    nextNode->prev = temp;
}

void deleteNode(Node* &tail, int val){
    if(tail == NULL){
        cout << "Empty List" << endl;
        return;
    }

    Node *currNode = tail->next;
    Node *prevNode = tail;

    do{
        if(currNode->data == val){
            if(currNode->next == currNode){
                tail = NULL;
            }
            else{
                prevNode->next = currNode->next;
                currNode->next->prev = prevNode;

                if(tail == currNode){
                    tail = tail->next;
                }
            }
            currNode->next = NULL;
            currNode->prev = NULL;
            delete currNode;
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    } while (currNode != tail->next);

}

void print(Node* tail){
    Node *temp = tail;

    do{
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

int main(){
    Node *tail = NULL;

    insertNode(tail, 1, 10);
    print(tail);
    insertNode(tail, 10, 20);
    print(tail);
    insertNode(tail, 20, 30);
    print(tail);
    insertNode(tail, 30, 40);
    print(tail);
    deleteNode(tail, 20);

    cout << tail->prev->data << endl;
    cout << tail->data << endl;
    cout << tail->next->data << endl;
    print(tail);
}