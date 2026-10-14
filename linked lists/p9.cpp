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

void sort012(Node* &head){

    if(head == NULL || head->next == NULL){
        return ;
    }


    int c0 = 0;
    int c1 = 0;
    int c2 = 0;

    Node* temp = head;

    while(temp != NULL){
        if(temp->data == 0){
            c0++;
        }
        else if(temp->data == 1){
            c1++;
        }
        else{
            c2++;
        }
        temp = temp ->next;
    }
    temp = head;

    while(temp != NULL){
        if(c0 != 0){
            temp->data = 0;
            c0--;
        }
        else if(c1 != 0){
            temp->data = 1;
            c1--;
        }
        else{
            temp->data = 2;
            c2--;
        }
        temp = temp->next;
    }
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

    // enter only 0, 1 and 2
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
    
    sort012(head);
    
    cout << "Baad : ";
    printList(head);
    return 0;
}

