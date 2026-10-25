#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};



class Stack{
    public:
        Node* top = new Node(-1);
        Node* head = top;
    
    void push(int num){
        Node *temp = new Node(num);
        top->next = temp;
        top = top->next;
        if(head->data == -1)
            head = head->next;
    }

    int pop(){
        if(top->data < 0){
            cout << "Stack Underflow" << endl;
            return -1;
        }else{
            int d = top->data;
            if(head == top){
                delete top;
                top = new Node(-1);
                return d;
            }
            Node *curr = head;
            while(curr->next != top){
                curr = curr->next;
            }
            top = curr;
            curr = curr->next;
            top->next = NULL;
            delete curr;
            return d;
        }
    }

    int peek(){
        if(top->data < 0){
            cout << "Stack is empty" << endl;
            return -1;
        }
        else{
            return top->data;
        }
    }

    bool isEmpty(){
        if(top->data < 0)
            return 1;
        else
            return 0;
    }

};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(50);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    if(s.isEmpty()){
        cout << "Stack is empty" << endl;
    }
    else{
        cout << "Stack is not empty" << endl;
    }
    return 0;
}