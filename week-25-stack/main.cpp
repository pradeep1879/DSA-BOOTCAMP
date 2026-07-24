#include <iostream>
using namespace std;

const int MAX_SIZE = 10^6;

class Stack{
  int arr[MAX_SIZE];
  int ptr = -1;
  void push(int x){
    ptr++;
    arr[ptr] = x;
  }

  void pop(){
    ptr--;
  }

  int peek(){
    return arr[ptr];
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