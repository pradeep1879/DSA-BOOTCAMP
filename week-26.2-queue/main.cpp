#include <iostream>
using namespace std;

/*
    Implement only the class below (a queue backed by a singly linked list).
    void push(int x) -- insert x at the back.
    int  pop()       -- remove and return the front element; -1 if empty.
    int  front()     -- return the front element; -1 if empty.
    int  back()      -- return the last element; -1 if empty.
    bool empty()     -- return true if the queue is empty, else false.
    int  size()      -- return the number of elements.
    All operations must run in O(1).
*/

class MyQueue {
public:

    MyQueue()
    {

    }

    void push(int x)
    {

    }

    int pop()
    {

    }

    int front()
    {

    }

    int back()
    {

    }

    bool empty()
    {

    }

    int size()
    {

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

    while (q--)
    {
        cin >> op;

        if (op == "push")
        {
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
        else // size
            cout << que.size() << '\n';
    }

    return 0;
}