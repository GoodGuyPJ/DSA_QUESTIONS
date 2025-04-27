// Queue - Queue is a linear data structure that follows the First In First Out (FIFO) principle.
// It allows adding elements to the back and removing elements from the front. The queue is implemented using a linked list, where each node contains a value and a pointer to the next node. The queue has two main operations: enqueue (to add an element) and dequeue (to remove an element). The queue can also be checked for emptiness and can return the front element without removing it.

// enqueue - Adds an element to the back of the queue
// dequeue - Removes the front element from the queue
// front - Returns the front element of the queue without removing it
// empty - Checks if the queue is empty
// size - Returns the number of elements in the queue
// clear - Removes all elements from the queue
// display - Displays the elements in the queue from front to back

// Implementation of Queue using Arrays
//top, push, pop, empty, size, clear, display
#include <iostream>
using namespace std;

class Queue {
private:
    int front;
    int rear;
    int capacity;
    int* queue;
public:
    Queue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = 0;
        rear = -1;
    }

    ~Queue() {
        delete[] queue;
    }

    void enqueue(int value) {
        if (size() == capacity) {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int dequeuedValue = queue[front];
        front = (front + 1) % capacity;
        return dequeuedValue;
    }

    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue[front];
    }

    bool isEmpty() {
        return front == (rear + 1) % capacity;
    }

    int size() {
        return (rear - front + capacity) % capacity + 1;
    }

    void clear() {
        front = 0;
        rear = -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i != (rear + 1) % capacity; i = (i + 1) % capacity) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }

};

// Implementation of Queue using Linked List

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class QueueLL {
private:
    Node* front;
    Node* rear;
    int count;
public:
    QueueLL() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    ~QueueLL() {
        clear();
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        Node* temp = front;
        int dequeuedValue = front->data;
        front = front->next;
        delete temp;
        count--;
        if (isEmpty()) {
            rear = nullptr;
        }
        return dequeuedValue;
    }

    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int size() {
        return count;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = front;
        Node* next = nullptr;
        rear = front; // Update rear to point to the original front
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        front = prev; // Update front to point to the new front (previously the last node)
    }

    void sort() {
        if (isEmpty()) {
            return;
        }
        Node* current = front;
        Node* index = nullptr;
        int temp;
        while (current != nullptr) {
            index = current->next;
            while (index != nullptr) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }

    void merge(QueueLL& other) {
        if (other.isEmpty()) {
            return;
        }
        if (isEmpty()) {
            front = other.front;
            rear = other.rear;
        } else {
            rear->next = other.front;
            rear = other.rear;
        }
        count += other.count;
        other.front = nullptr;
        other.rear = nullptr;
        other.count = 0;
    }

    void split(QueueLL& other) {
        if (isEmpty()) {
            return;
        }
        int mid = count / 2;
        Node* current = front;
        for (int i = 0; i < mid - 1; i++) {
            current = current->next;
        }
        other.front = current->next;
        other.rear = rear;
        other.count = count - mid;
        rear = current;
        rear->next = nullptr;
        count = mid;
    }
    
    void rotate(int k) {
        if (isEmpty() || k <= 0) {
            return;
        }
        k = k % count; // Handle cases where k is greater than the size of the queue
        Node* current = front;
        for (int i = 1; i < k; i++) {
            current = current->next;
        }
        Node* kthNode = current;
        rear->next = front;
        front = kthNode->next;
        kthNode->next = nullptr;
        rear = kthNode;
    }

    void reverseK(int k) {
        if (isEmpty() || k <= 0) {
            return;
        }
        Node* current = front;
        Node* prevTail = nullptr;
        while (current != nullptr) {
            Node* tail = current;
            Node* prev = nullptr;
            for (int i = 0; i < k && current != nullptr; i++) {
                Node* next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            if (prevTail != nullptr) {
                prevTail->next = prev;
            } else {
                front = prev;
            }
            tail->next = current;
            prevTail = tail;
        }
        rear = tail;
    }

    void rotateK(int k) {
        if (isEmpty() || k <= 0) {
            return;
        }
        Node* current = front;
        for (int i = 1; i < k && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            return;
        }
        Node* kthNode = current;
        rear->next = front;
        front = kthNode->next;
        kthNode->next = nullptr;
        rear = kthNode;
    }

    void reverseKGroup(int k) {
        if (isEmpty() || k <= 0) {
            return;
        }
        Node* current = front;
        Node* prevTail = nullptr;
        while (current != nullptr) {
            Node* tail = current;
            Node* prev = nullptr;
            for (int i = 0; i < k && current != nullptr; i++) {
                Node* next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            if (prevTail != nullptr) {
                prevTail->next = prev;
            } else {
                front = prev;
            }
            tail->next = current;
            prevTail = tail;
        }
        rear = tail;
    }

    void rotateKGroup(int k) {
        if (isEmpty() || k <= 0) {
            return;
        }
        Node* current = front;
        Node* prevTail = nullptr;
        while (current != nullptr) {
            Node* tail = current;
            for (int i = 1; i < k && current != nullptr; i++) {
                current = current->next;
            }
            if (current == nullptr) {
                break;
            }
            Node* nextGroupHead = current->next;
            current->next = nullptr;
            if (prevTail != nullptr) {
                prevTail->next = tail;
            } else {
                front = tail;
            }
            prevTail = current;
            tail->next = nextGroupHead;
            current = nextGroupHead;
        }
        rear = prevTail;
    }

    void mergeSorted(QueueLL& other) {
        if (isEmpty()) {
            front = other.front;
            rear = other.rear;
            count = other.count;
            return;
        }
        if (other.isEmpty()) {
            return;
        }
        Node* mergedHead = nullptr;
        Node* mergedTail = nullptr;
        Node* current1 = front;
        Node* current2 = other.front;
        while (current1 != nullptr && current2 != nullptr) {
            Node* newNode = nullptr;
            if (current1->data < current2->data) {
                newNode = new Node(current1->data);
                current1 = current1->next;
            } else {
                newNode = new Node(current2->data);
                current2 = current2->next;
            }
            if (mergedHead == nullptr) {
                mergedHead = newNode;
                mergedTail = newNode;
            } else {
                mergedTail->next = newNode;
                mergedTail = newNode;
            }
        }
        while (current1 != nullptr) {
            Node* newNode = new Node(current1->data);
            mergedTail->next = newNode;
            mergedTail = newNode;
            current1 = current1->next;
        }
        while (current2 != nullptr) {
            Node* newNode = new Node(current2->data);
            mergedTail->next = newNode;
            mergedTail = newNode;
            current2 = current2->next;
        }
        clear();
        front = mergedHead;
        rear = mergedTail;
    }

    void splitSorted(QueueLL& other) {
        if (isEmpty()) {
            return;
        }
        Node* current = front;
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->data > other.front->data) {
                if (prev != nullptr) {
                    prev->next = nullptr;
                }
                other.enqueue(current->data);
                current = current->next;
            } else {
                prev = current;
                current = current->next;
            }
        }
        rear = prev;
        if (rear != nullptr) {
            rear->next = nullptr;
        }
    }

    void mergeSortedK(QueueLL& other, int k) {
        if (isEmpty()) {
            front = other.front;
            rear = other.rear;
            count = other.count;
            return;
        }
        if (other.isEmpty()) {
            return;
        }
        Node* mergedHead = nullptr;
        Node* mergedTail = nullptr;
        Node* current1 = front;
        Node* current2 = other.front;
        while (current1 != nullptr && current2 != nullptr) {
            Node* newNode = nullptr;
            if (current1->data < current2->data) {
                newNode = new Node(current1->data);
                current1 = current1->next;
            } else {
                newNode = new Node(current2->data);
                current2 = current2->next;
            }
            if (mergedHead == nullptr) {
                mergedHead = newNode;
                mergedTail = newNode;
            } else {
                mergedTail->next = newNode;
                mergedTail = newNode;
            }
        }
        while (current1 != nullptr) {
            Node* newNode = new Node(current1->data);
            mergedTail->next = newNode;
            mergedTail = newNode;
            current1 = current1->next;
        }
        while (current2 != nullptr) {
            Node* newNode = new Node(current2->data);
            mergedTail->next = newNode;
            mergedTail = newNode;
            current2 = current2->next;
        }
        clear();
        front = mergedHead;
        rear = mergedTail;
    }

    void splitSortedK(QueueLL& other, int k) {
        if (isEmpty()) {
            return;
        }
        Node* current = front;
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->data > other.front->data) {
                if (prev != nullptr) {
                    prev->next = nullptr;
                }
                other.enqueue(current->data);
                current = current->next;
            } else {
                prev = current;
                current = current->next;
            }
        }
        rear = prev;
        if (rear != nullptr) {
            rear->next = nullptr;
        }
    }

    void mergeSortedKGroup(QueueLL& other, int k) {
        if (isEmpty()) {
            front = other.front;
            rear = other.rear;
            count = other.count;
            return;
        }
        if (other.isEmpty()) {
            return;
        }
        Node* mergedHead = nullptr;
        Node* mergedTail = nullptr;
        Node* current1 = front;
        Node* current2 = other.front;
        while (current1 != nullptr && current2 != nullptr) {
            Node* newNode = nullptr;
            if (current1->data < current2->data) {
                newNode = new Node(current1->data);
                current1 = current1->next;
            } else {
                newNode = new Node(current2->data);
                current2 = current2->next;
            }
            if (mergedHead == nullptr) {
                mergedHead = newNode;
                mergedTail = newNode;
            } else {
                mergedTail->next = newNode;
                mergedTail = newNode;
            }
        }
        while (current1 != nullptr) {
            Node* newNode = new Node(current1->data);
            mergedTail->next = newNode;
            mergedTail = newNode;
            current1 = current1->next;
        }
        while (current2 != nullptr) {
            Node* newNode = new Node(current2->data);
            mergedTail->next = newNode;
            mergedTail = newNode;
            current2 = current2->next;
        }
        clear();
        front = mergedHead;
        rear = mergedTail;

        count = mergedTail->data; // Update count to the last element's data
        mergedTail->next = nullptr; // Ensure the last node points to nullptr
    }
};


