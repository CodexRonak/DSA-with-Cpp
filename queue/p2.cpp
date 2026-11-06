#include <iostream>
using namespace std;

class CircularQueue {
public:
    int *arr;
    int size;
    int front;
    int rear;

    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool enqueue(int value) {
        // full check
        if ((rear + 1) % size == front) {
            return false;
        }
        // empty queue
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        return true;
    }

    int dequeue() {
        if (front == -1) return -1;   // empty

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) {
            front = rear = -1;        // last element nikal gaya
        } else {
            front = (front + 1) % size;
        }
        return ans;
    }
};

int main() {
    CircularQueue q(3);

    cout << q.enqueue(10) << endl;   // 1
    cout << q.enqueue(20) << endl;   // 1
    cout << q.enqueue(30) << endl;   // 1
    cout << q.enqueue(40) << endl;   // 0 (full)

    cout << q.dequeue() << endl;     // 10
    cout << q.enqueue(40) << endl;   // 1 (wrap-around)
    cout << q.dequeue() << endl;     // 20
    cout << q.dequeue() << endl;     // 30
    cout << q.dequeue() << endl;     // 40
    cout << q.dequeue() << endl;     // -1 (empty)
    return 0;
}