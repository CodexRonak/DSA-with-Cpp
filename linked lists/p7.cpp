#include <iostream>
using namespace std;

// Looped Linked List

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

    while(count < pos-1 && temp->next != NULL){
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
            if(head == NULL){
            tail = NULL;
        }
        temp->next = NULL;
        delete temp;
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

Node* floydCycleDetection(Node *head){
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
    return NULL;
}

Node* startingNode(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node *intersection = floydCycleDetection(head);
    
    if(intersection == NULL){
        return NULL;
    }
    
    Node *slow = head;
    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void removeCycle(Node* &head){
    if(head == NULL) return;

    Node *start = startingNode(head);
    if(start == NULL){
        cout << "No cycle to remove" << endl;
        return;
    }

    Node *temp = start;
    while(temp->next != start){   // head nahi, start
        temp = temp->next;
    }
    temp->next = NULL;
    cout << "Cycle is removed" << endl;
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
    insertAtHead(head, 15);
    
    Node *loop = tail;
    
    insertAtTail(tail, 22); 
    insertAtMid(head, tail, 3, 44);
    insertAtMid(head, tail, 1, 94);

    tail->next = loop;

    if(floydCycleDetection(head) != NULL){
        cout << "cycle is present" << endl;
    }
    else{
        cout << "no cycle" << endl;
    }

    Node *startNode = startingNode(head);
    cout << "Starting cycle at " << startNode->data << endl;

    removeCycle(head);
    print(head);
}