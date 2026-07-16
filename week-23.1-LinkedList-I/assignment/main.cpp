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
        head = nullptr;
        Node* tail = nullptr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            Node* node = new Node(x);
            if (!head) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
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
    Implement the function below.
    It should print the linked list in the required format.
*/
void printList(Node* head){
  
  while(head != nullptr){
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "X";
};

int findLength(Node* head){
  int count = 0;
  while(head != nullptr){
    count++;
    head = head->next;
  }
  return count;
}

int countX(Node* head, int x){
  int count = 0;
  while(head != nullptr){
    if(head->val == x){
      count++;
    }
    head = head->next;
  }
  return count;
}

int findMin(Node* head){
  if(head == nullptr){
    return -1;
  }
  int ans = head->val;
  while(head != nullptr){
    ans = min(ans, head->val);
    head = head->next;
  }
  return ans;
}

int findKth(Node* head, int k){
  if(head == NULL) return -1;
  auto ptr = head;

  for(int i = 0; i < k -1; i++){
    ptr = ptr -> next;
    if(ptr == NULL) return -1;
  }
  return ptr->val;
}

int kthFromEnd(Node* head, int k){
  if(head == NULL) return -1;

  auto slow = head;
  auto fast = head;
  for(int i = 1; i <= k; i++){
    if(fast == NULL) return -1;
    fast = fast->next;
  }
  while(fast != NULL){
    slow = slow->next;
    fast = fast->next;
  }

  return slow->val;
}

int findMiddleNode(Node* head){
  if(head == NULL) return -1;

  auto slow = head;
  auto fast = head;

  while(fast->next != NULL and fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow->val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;
    ll.build(n);

    // printList(ll.head);
    // cout << findLength(ll.head);

    // int x;
    // cin >> x;
    // cout << countX(ll.head, x) << "\n";

    // cout << findMin(ll.head) << "\n";

    // int k;
    // cin >> k;
    // cout << findKth(ll.head, k) << "\n";

    // int k;
    // cin >> k;

    // cout << kthFromEnd(ll.head, k) << "\n";

    cout << findMiddleNode(ll.head) << "\n";
    return 0;
}