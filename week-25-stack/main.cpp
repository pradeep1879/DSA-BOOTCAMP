#include <iostream>
using namespace std;

const int MAX_SIZE = 10^6;
const int INVALID_OPERATION = 10^6;

class Stack{
  int arr[MAX_SIZE];
  int ptr = -1;

  void push(int x){
    if(size() == MAX_SIZE) return;
    ptr++;
    arr[ptr] = x;
  }

  void pop(){
    if(!empty());
    ptr--;
  }

  int peek(){
    return empty() ? INVALID_OPERATION : arr[ptr];
  }

  bool empty(){
    return ptr == -1;
  }

  int size(){
    return ptr + 1;
  }
};

int main(){

}