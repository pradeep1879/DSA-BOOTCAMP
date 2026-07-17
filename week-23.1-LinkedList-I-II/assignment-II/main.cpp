// #include <iostream>
// using namespace std;

// struct Node {
//     int val;
//     Node* next;
//     Node(int v) : val(v), next(nullptr) {}
// };

// class LinkedList {
//   public:

//     Node* head;

//     LinkedList() : head(nullptr) {}

//     void build(int n) {
//         Node* tail = nullptr;
//         for (int i = 0; i < n; i++) {
//             int x;
//             cin >> x;
//             Node* node = new Node(x);
//             if (!head) head = tail = node;
//             else tail->next = node, tail = node;
//         }
//     }

//     Node* getTail() {
//         Node* cur = head;
//         if (!cur) return nullptr;
//         while (cur->next) cur = cur->next;
//         return cur;
//     }

//     Node* getNodeAt(int idx) { // 0-indexed
//         Node* cur = head;
//         while (cur && idx--) cur = cur->next;
//         return cur;
//     }

//     ~LinkedList() {
//     }
// };

// /*
//     Implement only the function below.
// */
// Node* getIntersectionNode(Node* headA, Node* headB) {
//     Node* ptr1 = headA;
//     Node* ptr2 = headB;

//     while (ptr1 != ptr2) {
//         ptr1 = (ptr1 == nullptr) ? headB : ptr1->next;
//         ptr2 = (ptr2 == nullptr) ? headA : ptr2->next;
//     }

//     return ptr1;
// }

// void deleteNode(Node* node){
//   node->val = node->next->val;
//   auto temp = node->next;
//   node->next = temp->next;
//   delete temp;
// }

//  Node* findMiddleNode(Node* head){
//     if(head == NULL) return;

//     auto slow = head;
//     auto fast = head;

//     while(fast->next != NULL and fast->next->next != NULL){
//       slow = slow->next;
//       fast = fast->next->next;
//     }

//   return slow;
// }

// void deleteMiddleNode(Node* head){
//   auto node = findMiddleNode(head);

//   deleteNode(node);
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int nA, nB, common;
//     cin >> nA >> nB >> common;

//     LinkedList A, B, C;
//     A.build(nA - common);
//     B.build(nB - common);
//     C.build(common);

//     Node* commonHead = C.head;

//     if (A.getTail()) A.getTail()->next = commonHead;
//     else A.head = commonHead;

//     if (B.getTail()) B.getTail()->next = commonHead;
//     else B.head = commonHead;

//     Node* ans = getIntersectionNode(A.head, B.head);

//     if (ans == nullptr) cout << -1 << "\n";
//     else cout << ans->val << "\n";

//     return 0;
// }











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
    Delete the middle node and return the head of the modified list.
    The middle node is the floor(n / 2)-th node (0-indexed).
*/

Node* deleteMiddle(Node* head) {
   if(head == nullptr) return nullptr;

   if(head->next == nullptr){
    delete head;
    return nullptr;
   }

   Node* prev = nullptr;
   Node* slow = head;
   Node* fast = head;

   while(fast and fast->next){
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
   }

   prev->next = slow->next;
   delete slow;
  
   return head;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    ll.head = deleteMiddle(ll.head);

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