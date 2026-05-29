#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  vector<int> freq(26, 0);

  for (char c : s) {
      freq[c - 'a']++;
  }

  string ans;

  for (int i = 0; i < 26; i++) {
      ans.append(freq[i], char('a' + i));
  }

  cout << ans << '\n';

  return 0;
}