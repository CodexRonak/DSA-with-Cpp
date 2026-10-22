#include <iostream>
using namespace std;

class Stack{
    public:
        int top;
        int *arr;
        int size;
    
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int num){
        if(size - top > 1){
            top++;
            arr[top] = num;
        }
        else{
            cout << "Stack Overflow!" << endl;
        }
    }

    void pop(){
        if(top > -1){
            top--;
        }
        else{
            cout << "Stack Underflow" << endl;
        }
    }

    int peek(){
        if(top >= 0){
            return arr[top];
        }
        else{
            cout << "Stack Underflow" << endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1)
            return true;
        else{
            return false;
        }
    }
};


int main(){
    Stack s(4);

    for (int i = 0; i < 4; i++){
        int num;
        cout << "Enter the number" << endl;
        cin >> num;
        s.push(num);
    }

    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;
}