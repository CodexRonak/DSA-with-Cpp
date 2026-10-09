#include <iostream>
#include <map>
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

    while(currNode->data != val && currNode != tail){
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

    if(currNode == tail){ 
        tail = temp;
    }
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

void revList(Node* &tail){
    if(tail == NULL || tail->next == tail){
        return;
    }

    Node *temp = NULL;
    Node *currNode = tail->next;
    Node *headNode = tail->next;

    do{
        temp = currNode->prev;
        currNode->prev = currNode->next;
        currNode->next = temp;

        currNode = currNode->prev;
    } while (currNode != headNode);

    tail = headNode; 
}

bool checkCycle(Node* tail){
    if(tail == NULL){
        return false;
    }
    
    map<Node*, bool> visited;
    Node *temp = tail->next;

    while(temp != NULL){
        if(visited[temp] == true){
            cout << "present on element " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}


Node* floydCycleDetection(Node *tail){
    Node *head = tail -> next;
    if(head == NULL){
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast -> next;
        
        if(fast != NULL){
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast){
            return slow;
        }
    }
}


void print(Node* tail){
    if(tail == NULL){
        cout << "Empty List" << endl;
        return;
    }

    Node *head = tail->next;
    Node *temp = head;

    do{
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
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
    // print(tail);
    // deleteNode(tail, 20);

    cout << tail->prev->data << endl;
    cout << tail->data << endl;
    cout << tail->next->data << endl;
    print(tail);
    
    // revList(tail);
    // print(tail);

    // if(checkCycle(tail)){
    //     cout << "cycle is present" << endl;
    // }
    // else{
    //     cout << "no cycle" << endl;
    // }

    if(floydCycleDetection(tail) != NULL){
        cout << "cycle is present" << endl;
    }
    else{
        cout << "no cycle" << endl;
    }
}