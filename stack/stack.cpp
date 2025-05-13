// Stack - Stack is a data structure that follows the Last In First Out (LIFO) principle. It allows adding and removing elements from the top of the stack only. The stack is implemented using a linked list, where each node contains a value and a pointer to the next node. The stack has two main operations: push (to add an element) and pop (to remove an element). The stack can also be checked for emptiness and can return the top element without removing it.

// push - Adds an element to the top of the stack
// pop - Removes the top element from the stack
// top - Returns the top element of the stack without removing it
// empty - Checks if the stack is empty
// size - Returns the number of elements in the stack
// clear - Removes all elements from the stack
// display - Displays the elements in the stack from top to bottom

// Implementation of Stack using Arrays
// top, push, pop, empty, size, clear, display
class Stack
{
private:
    int top;
    int capacity;
    int *stack;

public:
    Stack(int size)
    {
        capacity = size;
        stack = new int[capacity];
        top = -1;
    }

    ~Stack()
    {
        delete[] stack;
    }

    void push(int value)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        stack[++top] = value;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return stack[top--];
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stack[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    int size()
    {
        return top + 1;
    }

    void clear()
    {
        top = -1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

#include <iostream>
using namespace std;

int main()
{
    Stack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();                                 // Output: Stack elements: 30 20 10
    cout << "Top element: " << stack.peek() << endl; // Output: Top element: 30
    cout << "Stack size: " << stack.size() << endl;  // Output: Stack size: 3
    stack.pop();
    stack.display();                                                        // Output: Stack elements: 20 10
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: Is stack empty? No
    stack.clear();
    cout << "Stack cleared." << endl;
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: Is stack empty? Yes
    return 0;
}

// Implementation of Stack using Linked List
// top, push, pop, empty, size, clear, display
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class StackLL
{
private:
    Node *top;
    int count;

public:
    StackLL()
    {
        top = nullptr;
        count = 0;
    }

    ~StackLL()
    {
        clear();
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        count++;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        Node *temp = top;
        int poppedValue = top->data;
        top = top->next;
        delete temp;
        count--;
        return poppedValue;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    int size()
    {
        return count;
    }

    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        Node *current = top;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = top;
        Node *next = nullptr;
        while (current != nullptr)
        {
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

int main()
{
    StackLL stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();                                 // Output: Stack elements: 30 20 10
    cout << "Top element: " << stack.peek() << endl; // Output: Top element: 30
    cout << "Stack size: " << stack.size() << endl;  // Output: Stack size: 3
    stack.pop();
    stack.display();                                                        // Output: Stack elements: 20 10
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: Is stack empty? No
    stack.clear();
    cout << "Stack cleared." << endl;
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: Is stack empty? Yes
    return 0;
}

// Implementation Stack using Queue
// top, push, pop, empty, size, clear, display
class QueueStack
{
private:
    Queue queue1;
    Queue queue2;

public:
    QueueStack(int size) : queue1(size), queue2(size) {}

    void push(int value)
    {
        queue1.enqueue(value);
    }

    int pop()
    {
        if (queue1.isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        while (queue1.size() > 1)
        {
            queue2.enqueue(queue1.dequeue());
        }
        int poppedValue = queue1.dequeue();
        swap(queue1, queue2);
        return poppedValue;
    }

    int top()
    {
        if (queue1.isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        while (queue1.size() > 1)
        {
            queue2.enqueue(queue1.dequeue());
        }
        int topValue = queue1.frontElement();
        queue2.enqueue(queue1.dequeue());
        swap(queue1, queue2);
        return topValue;
    }

    bool isEmpty()
    {
        return queue1.isEmpty();
    }

    int size()
    {
        return queue1.size();
    }

    void clear()
    {
        queue1.clear();
    }

    void display()
    {
        queue1.display();
    }

    void swap(Queue &q1, Queue &q2)
    {
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void reverse()
    {
        queue1.reverse();
    }

    void sort()
    {
        queue1.sort();
    }

    void merge(Queue &other)
    {
        queue1.merge(other);
    }

    void splitSortedK(Queue &other, int k)
    {
        queue1.splitSortedK(other, k);
    }

    void mergeSorted(Queue &other)
    {
        queue1.mergeSorted(other);
    }

    void displaySorted()
    {
        queue1.displaySorted();
    }

    void clearSorted()
    {
        queue1.clearSorted();
    }

    void rotate(int k)
    {
        queue1.rotate(k);
    }

    void split(Queue &other)
    {
        queue1.split(other);
    }
    void splitSorted(Queue &other)
    {
        queue1.splitSorted(other);
    }
    void mergeSortedK(Queue &other, int k)
    {
        queue1.mergeSortedK(other, k);
    }
};

// Check for Balanced Parentheses
//   Input: s = "()[]{}"
// Output: true
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> s1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                s1.push(s[i]);
            }
            else
            {
                if (s1.empty())
                    return false;

                char x = s1.top();
                s1.pop();
                if (x == '(' && s[i] != ')')
                {
                    return false;
                }

                if (x == '[' && s[i] != ']')
                {
                    return false;
                }

                if (x == '{' && s[i] != '}')
                {
                    return false;
                }
            }
        }
        if (s1.empty())
        {
            return true;
        }
        return false;
    }
};

// Prefix, Infix, and Postfix Conversion used in LISP(LISP is a family of computer programming languages with a long history and a distinctive, fully parenthesized prefix notation.) and Tree
// Infix to Postfix-> its a common way to represent expressions in programming languages. Infix notation is the standard way of writing expressions, where operators are placed between operands (e.g., A + B). Postfix notation, also known as Reverse Polish Notation (RPN), places operators after their operands (e.g., AB+). This conversion is useful for evaluating expressions using stacks, as it eliminates the need for parentheses and operator precedence rules.
// For example, the infix expression (A + B) * C would be represented in postfix as AB+C*.
infixtoPostfix(string s)
{
    int i = 0;
    string ans = "";
    stack<char> st;
    while (i < n)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            ans += s[i];
        }
        else
        {
            while (!st.empty() && precedence(st.top()) >= precedence(s[i]))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

// Infix to Prefix
infixtoPrefix(string s)
{
    int i = 0;
    string ans = "";
    stack<char> st;
    reverse(s.begin(), s.end());
    while (i < n)
    {
        if (s[i] == ')')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            ans += s[i];
        }
        else
        {
            while (!st.empty() && precedence(st.top()) >= precedence(s[i]))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Postfix to Infix

Postfixtoinfix(string s)
{
    int i = 0;
    string ans = "";
    stack<string> st;
    while (i < n)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            st.push(s[i]);
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = "(" + op2 + s[i] + op1 + ")";
            st.push(temp);
        }
        i++;
    }
    return st.top();
}

// Prefix to Infix
PrefixToInfix(string s)
{
    int i = 0;
    string ans = "";
    stack<string> st;
    reverse(s.begin(), s.end());
    while (i < n)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            st.push(s[i]);
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = "(" + op1 + s[i] + op2 + ")";
            st.push(temp);
        }
        i++;
    }
    return st.top();
}

// Postfix to Prefix
// Prefix to Postfix

// Implement Min Stack
class MinStack
{
    stack<pair<int, int>> st;

public:
    void push(int x)
    {
        int min;
        if (st.empty())
        {
            min = x;
        }
        else
        {
            min = std::min(x, st.top().second);
        }
        st.push({x, min});
    }
    void pop()
    {
        if (!st.empty())
        {
            st.pop();
        }
    }
    int top()
    {
        if (!st.empty())
        {
            return st.top().first;
        }
        return -1; // or throw an exception
    }
    int getMin()
    {
        if (!st.empty())
        {
            return st.top().second;
        }
        return -1; // or throw an exception
    }
}

// approch 2
class MinStack
{
    stack<long long> st;
    long long minEle;

public:
    MinSatck()
    {
        while (st.empty() == false)
            st.pop();
        minEle = INT_MAX;
    }
    void push(int val)
    {
        long long val = Long.valuevalue;
        if (st.empty())
        {
            minEle = val;
            st.push(val);
        }
        else
        {
            if (val < minEle)
            {
                st.push(2 * val - minEle);
                minEle = val;
            }
            else
            {
                s.push(val);
            }
        }
    }
    void pop()
    {
        if (st.empty())
            return;
        if (st.top() < minEle)
        {
            minEle = 2 * minEle - st.top();
        }
        st.pop();
    }
    int top()
    {
        if (st.empty())
            return -1;
        if (st.top() < minEle)
            return minEle;
        return st.top();
    }
    int getMin()
    {
        if (st.empty())
            return -1;
        return minEle;
    }
}

// Next Greater Element
 class solution{
    public: 
    vector<int> nextGreaterElements(vector<int> & nums){
        int n = nums.size();
        vector<int nge(n, -1);
        stack<int> st;
        for(int i= 2*n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            if(i<n){
                if(!st.empty()) nge[i] = st.top();
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
 }


//  Next Greater Element - II 
