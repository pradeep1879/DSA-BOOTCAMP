#include <iostream>
using namespace std;

/*
    Implement only the class below.
*/
class MinStack {
public:
    MinStack() {
        // implement
    }

    void push(long long x) {
        // implement
    }

    void pop() {
        // implement
    }

    long long top() {
        // implement
        return -1;
    }

    long long getMin() {
        // implement
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