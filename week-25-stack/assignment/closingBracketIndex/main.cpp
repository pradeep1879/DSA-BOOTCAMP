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

void maximumNestingDepth(string s)
{
  stack<char> st;

  int ans = 0;

  for (char ch : s)
  {
    if (isOpening(ch))
    {
      st.push(ch);
      ans = max(ans, (int)st.size());
    }
    else if (isClosing(ch))
    {
      if (!st.empty())
      {
        st.pop();
      }
    }
  }

  cout << ans << "\n";
}

// int maximumNestingDepth(string s)
// {
//     int depth = 0, ans = 0;

//     for (char ch : s)
//     {
//         if (ch == '(')
//         {
//             depth++;
//             ans = max(ans, depth);
//         }
//         else if (ch == ')')
//         {
//             depth--;
//         }
//     }

//     return ans;
// }

int main()
{
  // string s;
  // cin >> s;
  // int n;
  // cin >> n;

  // closingBracketIndex(s, n);

  string s;
  cin >> s;

  maximumNestingDepth(s);

}