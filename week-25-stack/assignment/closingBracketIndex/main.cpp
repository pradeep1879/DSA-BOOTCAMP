#include <iostream>
#include <stack>
using namespace std;

bool isOpening(char ch)
{
    return ch == '(';
}

bool isClosing(char ch)
{
    return ch == ')';
}

void closingBracketIndex(string s, int k)
{
  int n = s.size();
  stack<int> st;

  for (int i = 0; i < n; i++)
  {
    if (isOpening(s[i]))
    {
      st.push(i);
    }
    else if (isClosing(s[i]))
    {
      if (!st.empty())
      {
        if (st.top() == k)
        {
          cout << i << "\n";
          return;
        }
        st.pop();
      }
    }
  }

  cout << -1 << "\n"; // no matching closing bracket
}


int main(){
  string s;
  cin >> s;
  int n;
  cin >> n;

  closingBracketIndex(s, n);
}