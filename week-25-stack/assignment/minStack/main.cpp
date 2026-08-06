#include <iostream>
#include <stack>
using namespace std;

/*
    Implement only the class below.
*/
class MinStack {
public:
  stack<pair<long long, long long>> st;
    MinStack() {
        // implement
    }

    void push(long long x) {
        // implement
        if(st.empty()){
          st.push({x, x});
        }
        else 
        {
          st.push({x, min(x, getMin())});
        }
    }

    void pop() {
        // implement
        if (!st.empty())
          st.pop();
    }

    long long top() {
        // implement
        if(!st.empty()){
         return st.top().first;
        }
        return -1;
    }

    long long getMin() {
        // implement
        if(!st.empty()){
          return st.top().second;
        }
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    MinStack st;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            long long x;
            cin >> x;
            st.push(x);
        } else if (type == 2) {
            st.pop();
        } else if (type == 3) {
            cout << st.top() << "\n";
        } else {
            cout << st.getMin() << "\n";
        }
    }

    return 0;
}