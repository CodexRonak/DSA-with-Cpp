#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return qfront == rear;
    }

    void enqueue(int data) {
        if (rear == size) return;     // full
        arr[rear] = data;
        rear++;
    }

    int dequeue() {
        if (qfront == rear) return -1;   // empty

        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;

        if (qfront == rear) {            // queue khaali ho gayi, reset
            qfront = 0;
            rear = 0;
        }
        return ans;
    }

    int front() {
        if (qfront == rear) return -1;
        return arr[qfront];
    }
};

int main() {
    Queue q;

    cout << q.isEmpty() << endl;   // 1
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.front() << endl;     // 10
    cout << q.dequeue() << endl;   // 10
    cout << q.dequeue() << endl;   // 20
    cout << q.front() << endl;     // 30
    cout << q.isEmpty() << endl;   // 0
    cout << q.dequeue() << endl;   // 30
    cout << q.isEmpty() << endl;   // 1
    cout << q.dequeue() << endl;   // -1
    return 0;
}