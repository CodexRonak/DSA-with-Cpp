#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node * next;
        node(int data){
            this->data=data;
            this->next=NULL;
        }
};

node* findMid(node* head){
    node* fast = head -> next;
    node* slow = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

node* merge(node* left, node* right){
    if(left == NULL) return right;
    if(right == NULL) return left;

    node* ans = new node(-1);
    node* temp = ans;

    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->next = left;
            left = left->next;
        }
        else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    while(left != NULL){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }

    while(right != NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }

    ans = ans -> next;
    return ans;
}

node* mergeSort(node *head) {
    if(head ==  NULL || head -> next == NULL){
        return head;
    }

    node* mid = findMid(head);

    node* left = head;
    node* right = mid -> next;
    mid -> next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    node* ans = merge(left, right);
    return ans;
}

void printList(node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    node* head = NULL;
    node* tail = NULL;
    for(int i = 0; i < n; i++){
        node* temp = new node(arr[i]);
        if(head == NULL){
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    cout << "Before: ";
    printList(head);

    head = mergeSort(head);

    cout << "After:  ";
    printList(head);

    return 0;
}