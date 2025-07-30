#include <vector>

class MyCircularQueue {
private:
    std::vector<int> data;
    int front;
    int rear;
    int count;
    int capacity;

public:
    MyCircularQueue(int k) {
        data.resize(k);
        front = 0;
        rear = -1;
        count = 0;
        capacity = k;
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        rear = (rear + 1) % capacity;
        data[rear] = value;
        ++count;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        front = (front + 1) % capacity;
        --count;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : data[front];
    }

    int Rear() {
        return isEmpty() ? -1 : data[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};
