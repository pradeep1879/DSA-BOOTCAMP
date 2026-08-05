#include <iostream>
#include <stack>
using namespace std;


string doubleTrobble(string s){
  stack<char> st;
  for(char ch: s){
    if(st.empty()){
      st.push(ch);
    }else if(st.top() != ch){
      st.push(ch);
    }else{
      st.top(); // delete the top and the 
    }
  }

  string ans;

  while(!st.empty()){
    ans += st.top();
    st.top();
  }

  

}