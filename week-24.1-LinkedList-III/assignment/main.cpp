#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void build(int n) {
        Node* tail = nullptr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            Node* node = new Node(x);
            if (!head) head = tail = node;
            else tail->next = node, tail = node;
        }
    }

    void print() {
        bool first = true;
        Node* cur = head;
        while (cur) {
            if (!first) cout << ' ';
            cout << cur->val;
            first = false;
            cur = cur->next;
        }
        cout << "\n";
    }

    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
};

/*
    Implement only the class below.
*/
class MyLinkedList {
private:
    Node* head;
    int size;

    Node* getKthNode(int k) {
        if (k < 0 || k >= size) return nullptr;

        Node* ptr = head;
        for (int i = 0; i < k; i++) {
            ptr = ptr->next;
        }
        return ptr;
    }

public:
    MyLinkedList(Node* head) {
        this->head = head;
        size = 0;

        Node* temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;

        Node* node = getKthNode(index);
        return node->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }

        Node* tail = getKthNode(size - 1);
        tail->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {

        if (index < 0)
            index = 0;

        if (index > size)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* prev = getKthNode(index - 1);
        Node* newNode = new Node(val);

        newNode->next = prev->next;
        prev->next = newNode;

        size++;
    }

    void deleteAtIndex(int index) {

        if (index < 0 || index >= size)
            return;

        Node* temp;

        if (index == 0) {
            temp = head;
            head = head->next;
        } else {
            Node* prev = getKthNode(index - 1);
            temp = prev->next;
            prev->next = temp->next;
        }

        delete temp;
        size--;
    }

    Node* getHead() {
        return head;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;
    ll.build(n);

    MyLinkedList my(ll.head);

    int Q;
    cin >> Q;

    while (Q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int index;
            cin >> index;
            cout << my.get(index) << "\n";
        } else if (type == 1) {
            int val;
            cin >> val;
            my.addAtHead(val);
        } else if (type == 2) {
            int val;
            cin >> val;
            my.addAtTail(val);
        } else if (type == 3) {
            int index, val;
            cin >> index >> val;
            my.addAtIndex(index, val);
        } else {
            int index;
            cin >> index;
            my.deleteAtIndex(index);
        }
    }

    ll.head = my.getHead();
    ll.print();
    return 0;
}