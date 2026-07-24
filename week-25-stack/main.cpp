#include <iostream>
using namespace std;

// ------------------ Stack using Array ------------------

const int MAX_SIZE = 1000000;
const int INVALID_OPERATION = -1;

class Stack {
    int arr[MAX_SIZE];
    int ptr;

public:
    Stack() {
        ptr = -1;
    }

    void push(int x) {
        if (size() == MAX_SIZE)
            return;

        arr[++ptr] = x;
    }

    void pop() {
        if (empty())
            return;

        ptr--;
    }

    int peek() {
        if (empty())
            return INVALID_OPERATION;

        return arr[ptr];
    }

    bool empty() {
        return ptr == -1;
    }

    int size() {
        return ptr + 1;
    }
};

// ------------------ Linked List ------------------

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList {
    Node* head;
    int sz;

public:
    LinkedList() {
        head = nullptr;
        sz = 0;
    }

    void addAtHead(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        sz++;
    }

    int deleteAtHead() {
        if (head == nullptr)
            return INVALID_OPERATION;

        Node* temp = head;
        int value = temp->val;

        head = head->next;
        delete temp;
        sz--;

        return value;
    }

    int getHead() {
        if (head == nullptr)
            return INVALID_OPERATION;

        return head->val;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        return sz;
    }
};

// ------------------ Stack using Linked List ------------------

class MyStack {
    LinkedList list;

public:
    void push(int x) {
        list.addAtHead(x);
    }

    int pop() {
        return list.deleteAtHead();
    }

    int top() {
        return list.getHead();
    }

    bool empty() {
        return list.empty();
    }

    int size() {
        return list.size();
    }
};

// ------------------ Driver ------------------

int main() {

    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;
    cout << "Size: " << st.size() << endl;

    cout << "Pop: " << st.pop() << endl;
    cout << "Top: " << st.top() << endl;

    st.push(40);

    while (!st.empty()) {
        cout << st.pop() << " ";
    }

    cout << endl;

    return 0;
}