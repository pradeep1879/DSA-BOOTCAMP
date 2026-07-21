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
    Reverse the nodes of the list k at a time and return the new head.
    If the number of nodes is not a multiple of k, the leftover nodes at the
    end remain in their original order.
*/

Node* reverseList(Node* head){
  Node* prev = NULL;
  auto curr = head;
  

  while(curr != NULL){
    auto next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
    return prev;
}

Node* reverseKGroup(Node* head, int k){
  auto dummy = new Node(-1);
  auto tail = dummy;

  auto ptr = head;
  while(ptr != NULL){
    auto end = ptr;
    for(int i = 1; i <= k-1; i++){
      end = end->next;
      if(end == NULL){
        tail->next = ptr;
        return dummy->next;
      }
    }

    // start from ptr and ends at the end
    auto nextStart = end->next;
    end->next = NULL;

    // seprate the current group

    // reverse it
    reverseList(ptr);

    // attach with the tail
    tail->next = end;
    tail = ptr;

    // move to the next group
    ptr = nextStart;
  }
  return dummy->next;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    int k;
    cin >> k;

    ll.head = reverseKGroup(ll.head, k);

    Node* cur = ll.head;

    bool first = true;

    while(cur)
    {
        if(!first)
        {
            cout << ' ';
        }

        first = false;

        cout << cur->val;

        cur = cur->next;
    }

    cout << '\n';

    return 0;
}