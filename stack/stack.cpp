// Stack - Stack is a data structure that follows the Last In First Out (LIFO) principle. It allows adding and removing elements from the top of the stack only. The stack is implemented using a linked list, where each node contains a value and a pointer to the next node. The stack has two main operations: push (to add an element) and pop (to remove an element). The stack can also be checked for emptiness and can return the top element without removing it.

// push - Adds an element to the top of the stack
// pop - Removes the top element from the stack
// top - Returns the top element of the stack without removing it
// empty - Checks if the stack is empty
// size - Returns the number of elements in the stack
// clear - Removes all elements from the stack
// display - Displays the elements in the stack from top to bottom

// Implementation of Stack using Arrays
//top, push, pop, empty, size, clear, display
class Stack {
private:
    int top;
    int capacity;
    int* stack;
public:
    Stack(int size) {
        capacity = size;
        stack = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] stack;
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        stack[++top] = value;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return stack[top--];
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stack[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }

    void clear() {
        top = -1;
    }


    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

#include <iostream>
using namespace std;

int main() {
    Stack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display(); // Output: Stack elements: 30 20 10
    cout << "Top element: " << stack.peek() << endl; // Output: Top element: 30
    cout << "Stack size: " << stack.size() << endl; // Output: Stack size: 3
    stack.pop();
    stack.display(); // Output: Stack elements: 20 10
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: Is stack empty? No
    stack.clear();
    cout << "Stack cleared." << endl;
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: Is stack empty? Yes
    return 0;
}

// Implementation of Stack using Linked List
//top, push, pop, empty, size, clear, display
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class StackLL {
private:
    Node* top;
    int count;
public:
    StackLL() {
        top = nullptr;
        count = 0;
    }

    ~StackLL() {
        clear();
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        count++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        Node* temp = top;
        int poppedValue = top->data;
        top = top->next;
        delete temp;
        count--;
        return poppedValue;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int size() {
        return count;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = top;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        top = prev;
    }
};

#include <iostream>
using namespace std;

int main() {
    StackLL stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display(); // Output: Stack elements: 30 20 10
    cout << "Top element: " << stack.peek() << endl; // Output: Top element: 30
    cout << "Stack size: " << stack.size() << endl; // Output: Stack size: 3
    stack.pop();
    stack.display(); // Output: Stack elements: 20 10
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: Is stack empty? No
    stack.clear();
    cout << "Stack cleared." << endl;
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: Is stack empty? Yes
    return 0;
}

//Implementation Stack using Queue
//top, push, pop, empty, size, clear, display
class QueueStack {
private:
    Queue queue1;
    Queue queue2;
public:
    QueueStack(int size) : queue1(size), queue2(size) {}

    void push(int value) {
        queue1.enqueue(value);
    }

    int pop() {
        if (queue1.isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        while (queue1.size() > 1) {
            queue2.enqueue(queue1.dequeue());
        }
        int poppedValue = queue1.dequeue();
        swap(queue1, queue2);
        return poppedValue;
    }

    int top() {
        if (queue1.isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        while (queue1.size() > 1) {
            queue2.enqueue(queue1.dequeue());
        }
        int topValue = queue1.frontElement();
        queue2.enqueue(queue1.dequeue());
        swap(queue1, queue2);
        return topValue;
    }

    bool isEmpty() {
        return queue1.isEmpty();
    }

    int size() {
        return queue1.size();
    }

    void clear() {
        queue1.clear();
    }

    void display() {
        queue1.display();
    }

    void swap(Queue& q1, Queue& q2) {
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void reverse() {
        queue1.reverse();
    }

    void sort() {
        queue1.sort();
    }

    void merge(Queue& other) {
        queue1.merge(other);
    }

    void splitSortedK(Queue& other, int k) {
        queue1.splitSortedK(other, k);
    }

    void mergeSorted(Queue& other) {
        queue1.mergeSorted(other);
    }

    void displaySorted() {
        queue1.displaySorted();
    }

    void clearSorted() {
        queue1.clearSorted();
    }

    void rotate(int k) {
        queue1.rotate(k);
    }

    void split(Queue& other) {
        queue1.split(other);
    }
    void splitSorted(Queue& other) {
        queue1.splitSorted(other);
    }
    void mergeSortedK(Queue& other, int k) {
        queue1.mergeSortedK(other, k);
    }

  };



  // Check for Balanced Parentheses
//   Input: s = "()[]{}"
// Output: true
