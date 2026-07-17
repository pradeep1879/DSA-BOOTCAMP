#include <iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int val){
      this->val = val;
    }
};

class MyLinkedList{
  private:
      ListNode* head = NULL;
      int size = 0;

      ListNode* getKthNode(int k){
        if(k >= size) return NULL;
        auto ptr = head;
        for(int i = 0; i < k; i++){
          ptr = ptr->next;
        }
        return ptr;
      };

  public:

  int get(int index){
      auto node = getKthNode(index);
      return node == NULL ? -1 : node->val;
    }

  void addAtHead(int val){
    auto newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
    size++;
  }

  void addAtTail(int val){
    addAtIndex(size, val);
  }

  void addAtIndex(int index, int val){
    if(index > size) return;
    if(index == 0){
      addAtHead(val);
      return;
    }
    auto newNode = new ListNode(val);
    auto prev = getKthNode(index - 1);
    newNode->next = prev->next;
    prev->next = newNode;

    size++;
  }

  void deleteAtIndex(int index){
    if(index >= size){
      return;
    };
    
    ListNode* temp;

    if(index == 0){
      temp = head;
      head = head->next;
      delete temp;
      size--;
    }else{
      auto prev = getKthNode(index - 1);
      temp = prev-> next;
      prev->next = temp->next;
    }
    size--;
    delete temp;
  }
};
