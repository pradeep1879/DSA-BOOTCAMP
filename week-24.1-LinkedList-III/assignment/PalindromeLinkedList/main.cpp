#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int v)
    {
        val = v;
        next = nullptr;
    }
};

class LinkedList {
public:

    Node* head;

    LinkedList()
    {
        head = nullptr;
    }

    void build(int n)
    {
        Node* tail = nullptr;

        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            Node* node = new Node(x);

            if(!head)
            {
                head = tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
        }
    }
};

/*
    Implement only the function below.
    Return true if the linked list is a palindrome, otherwise false.
*/

bool isPalindrome(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return true;

    // Find the middle
    Node* slow = head;
    Node* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    Node* prev = nullptr;
    Node* curr = slow->next;

    while (curr != nullptr)
    {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // Compare both halves
    Node* first = head;
    Node* second = prev;

    while (second != nullptr)
    {
        if (first->val != second->val)
            return false;

        first = first->next;
        second = second->next;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    cout << (isPalindrome(ll.head) ? "true" : "false") << '\n';

    return 0;
}