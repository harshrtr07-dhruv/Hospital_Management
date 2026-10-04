#ifndef QUEUE_TEMPLATE_H
#define QUEUE_TEMPLATE_H

#include <iostream>
using namespace std;

template <class T>
class QueueTemplate {
private:
    T* elements;
    int frontIndex;
    int rearIndex;
    int capacity;
    int currentSize;

public:
    QueueTemplate(int cap = 10) {
        capacity = cap;
        elements = new T[capacity];
        frontIndex = 0;
        rearIndex = -1;
        currentSize = 0;
    }

    ~QueueTemplate() {
        delete[] elements;
    }

    void enqueue(T item) {
        if (currentSize == capacity) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        elements[rearIndex] = item;
        currentSize++;
    }

    T dequeue() {
        if (currentSize == 0) {
            throw "Queue is empty. Cannot dequeue.";
        }
        T item = elements[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
        return item;
    }

    bool isEmpty() const {
        return currentSize == 0;
    }

    int getSize() const {
        return currentSize;
    }
};

template <typename T>
void printUsingTemplate(const T& item) {
    cout << ">> Template Print: " << item << "\n";
}

#endif
