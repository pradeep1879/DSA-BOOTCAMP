#include <iostream>
using namespace std;

/*
    Implement only the class below (a queue backed by a singly linked list).
    void push(int x) -- insert x at the back.
    int  pop()       -- remove and return the front element; -1 if empty.
    int  front()     -- return the front element; -1 if empty.
    int  back()      -- return the last element; -1 if empty.
    bool empty()     -- return true if the queue is empty, else false.
    int  size()      -- return the number of elements.
    All operations must run in O(1).
*/


class Node {
public:
    int val;
    Node* next;

    Node(int val) {
      this->val = val;
      this->next = NULL;
    }
};

class LinkedList {
    Node* head;
    Node* tail;
    int _size;

public:
    LinkedList() {
      head = NULL;
      tail = NULL;
      _size = 0;
    }

    void addAtTail(int x) {
      Node* newNode = new Node(x);

      if (_size == 0) {
          head = tail = newNode;
      }
      else {
          tail->next = newNode;
          tail = newNode;
      }

      _size++;
    }

    int deleteAtHead() {
      if (_size == 0) {
          return -1;
      }

      Node* temp = head;
      int ans = temp->val;

      head = head->next;

      // Queue became empty
      if (head == NULL) {
          tail = NULL;
      }

      delete temp;
      _size--;

      return ans;
    }

    int getHead() {
      if (_size == 0) {
          return -1;
      }

      return head->val;
    }

    int getTail() {
      if (_size == 0) {
          return -1;
      }

      return tail->val;
    }

    int size() {
    return _size;
    }
};

class MyQueue {
    LinkedList list;

public:

    MyQueue() {
    }

    void push(int x) {
      list.addAtTail(x);
    }

    int pop() {
      return list.deleteAtHead();
    }

    int front() {
      return list.getHead();
    }

    int back() {
      return list.getTail();
    }

    bool empty() {
      return list.size() == 0;
    }

    int size() {
      return list.size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    MyQueue que;

    string op;

    while (q--) {
      cin >> op;

      if (op == "push") {
        int x;
        cin >> x;
        que.push(x);
        cout << "null" << '\n';
      }
      else if (op == "pop") {
          cout << que.pop() << '\n';
      }
      else if (op == "front") {
          cout << que.front() << '\n';
      }
      else if (op == "back") {
          cout << que.back() << '\n';
      }
      else if (op == "empty") {
          cout << (que.empty() ? "true" : "false") << '\n';
      }
      else {
          cout << que.size() << '\n';
      }
    }

    return 0;
}