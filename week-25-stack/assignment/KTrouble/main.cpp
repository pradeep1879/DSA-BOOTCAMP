#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


void KTrouble(string s, int k){
  if (k == 1){
    cout << "\n";
    return;
  }
  stack <pair<char, int>> st;

  for(char ch: s){
    if(st.empty() or st.top().first != ch) {
      st.push({ch, 1});
    }else{
      st.top().second++;
      if(st.top().second == k){
        st.pop(); // delete the top if it is equal to k;
      }
    }
  }

  string ans;
  while(!st.empty()){
    auto [ch, count] = st.top();
    
    while (count--){
      ans += ch;
    }
    
    st.pop();
  }
  reverse(ans.begin(), ans.end());

  cout << ans << "\n";
}

int main(){
  string s;
  cin >> s;
  int k;
  cin >> k;
  KTrouble(s, k);
}