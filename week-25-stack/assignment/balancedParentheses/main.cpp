#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        if (isBalanced(s))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}