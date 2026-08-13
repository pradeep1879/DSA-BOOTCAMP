#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:

    stack<int> inStack;
    stack<int> outStack;

    int last = -1;
    int count = 0;

    void push(int x){
      inStack.push(x);
      last = x;
      count++;
    }

    int front(){
      if (empty())
          return -1;

      // Move elements only when outStack is empty
      if (outStack.empty()){
        while (!inStack.empty())
        {
            outStack.push(inStack.top());
            inStack.pop();
        }
      }

      return outStack.top();
    }

    int pop(){
      if (empty())
          return -1;

      int ans = front();
      outStack.pop();
      count--;
      
      if (count == 0)
          last = -1;

      return ans;
    }

    int back(){
      if (empty())
          return -1;

      return last;
    }

    bool empty(){
      return inStack.empty() && outStack.empty();
    }

    int size(){
        return count;
    }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;

  MyQueue que;

  string op;

  while (q--){
    cin >> op;

    if (op == "push"){
      int x;
      cin >> x;
      que.push(x);
      cout << "null" << '\n';
    }
    else if (op == "pop")
        cout << que.pop() << '\n';

    else if (op == "front")
        cout << que.front() << '\n';

    else if (op == "back")
        cout << que.back() << '\n';

    else if (op == "empty")
        cout << (que.empty() ? "true" : "false") << '\n';

    else
        cout << que.size() << '\n';
  }

  return 0;
}