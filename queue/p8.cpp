#include <iostream>
using namespace std;

class KQueue{
    int *arr;
    int *next;
    int *front;
    int *rear;
    int n;
    int k;
    int freeSpot;

    public:
        KQueue(int n, int k){
            this->n = n;
            this->k = k;
            arr = new int[n];
            next = new int[n];
            front = new int[k];
            rear = new int[k];
            freeSpot = 0;

            // intializing front and rear array
            for (int i = 0; i < k; i++){
                front[i] = rear[i] = -1;
            }

            //  intializing next indices
            for (int i = 0; i < n - 1; i++){
                next[i] = i + 1;
            }

            // intialiazing last index as -1 to check whether arr is full or not
            next[n - 1] = -1;
        }

        void enqueue(int num, int qn){
            if(freeSpot == -1){
                cout << "Queue overflow" << endl;
                return ;
            }

            int index = freeSpot;
            freeSpot = next[index];

            if(front[qn -1] == -1)
            // to check 
                front[qn - 1] = index;
            else{
                next[rear[qn - 1]] = index;
            }
            // update next
            next[index] = -1;

            //  update rear
            rear[qn - 1] = index;

            // pushing element
            arr[index] = num;
        }

        int dequeue(int qi){
            if(front[qi - 1] == -1){
                cout << "Queue underflow" << endl;
                return -1;
            }

            int index = front[qi - 1];
            front[qi - 1] = next[index];

            next[index] = freeSpot;
            freeSpot = index;
            return arr[index];
        }
};

int main() {
    KQueue q(6, 3);   // 6 size ka array, 3 queues

    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 3);
    q.enqueue(30, 2);

    cout << "Queue 1 dequeue: " << q.dequeue(1) << endl;  // 10
    cout << "Queue 2 dequeue: " << q.dequeue(2) << endl;  // 20
    cout << "Queue 3 dequeue: " << q.dequeue(3) << endl;  // 25
    cout << "Queue 3 dequeue: " << q.dequeue(3) << endl;  // underflow, -1

    q.enqueue(40, 3);
    cout << "Queue 3 dequeue: " << q.dequeue(3) << endl;  // 40

    return 0;
}