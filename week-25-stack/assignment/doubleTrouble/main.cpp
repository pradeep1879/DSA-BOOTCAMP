#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


void doubleTrouble(){
  string s;
  cin >> s;
  stack <char> st;

  for(char ch: s){
    if(st.empty() or st.top() != ch) {
      st.push(ch);
    }else{
      st.pop(); // delete the top and the incoming element (equal nbs)
    }
  }

  string ans;
  while(!st.empty()){
    ans += st.top();
    st.pop();
  }
  reverse(ans.begin(), ans.end());

  cout << ans << "\n";
}

int main(){
  doubleTrouble();
}