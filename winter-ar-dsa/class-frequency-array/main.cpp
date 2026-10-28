
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void characterFrequency(){
  string s;
  cin >> s;

  vector<int> freq(26,0);

  for(int i = 0; i < s.size(); i++){
    freq[s[i]-'a']++;
  }
  for(int i = 0; i < 26; i++){
    if(freq[i]>0){
      cout << char(i+'a') << ":"  << freq[i] <<"\n";
    }
  }
}

void digitFrequency(){
  string s;
  cin >> s;

  int freq[10] = {0};
  for(int i = 0; i < s.size(); i++){
    freq[s[i]-'0']++;
  }

  for(int i = 0; i < 10; i++){
    cout << freq[i] << " " ;
  }
}

void checkAnagram(){
  string s, t;
  cin >> s >> t;

  if(s.length() != t.length()){
    cout << "NO";
    return;
  }

  vector<int> freq(26,0);
  for(int i = 0; i < s.length(); i++){
    freq[s[i]-'a']++;
  }

  for(int i = 0; i < s.length(); i++){
    freq[t[i]-'a']--;
  }

  for(int i = 0; i < 26; i++){
    if(freq[i] != 0){
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}
 

void stringDuplicates() {
  string s;
  cin >> s;

  vector<int> freq(26, 0);


  for (int i = 0; i < s.length(); i++) {
      freq[s[i] - 'a']++;
  }

  bool ans = false;

  // print characters that occur more than once
  for (int i = 0; i < 26; i++) {
      if (freq[i] > 1) {
          cout << char(i + 'a');
          ans = true;
      }
  }

  if (!ans) {
      cout << -1;
  }
}


void arrayDuplicates(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  
  vector<int> freq(n);
  for(int i = 0; i < n; i++){
    freq[arr[i]]++;
  }
  bool ans = false;

  // print characters that occur more than once
  for(int i = 0; i < n; i++){
    if (freq[i] > 1) {
      cout << arr[i] << " ";
      ans = true;
    }
  }

  if(!ans){
    cout << -1;
  }

}




void uniqueQueries() {
  ios_base::sync_with_stdio(false);
  int q;
  cin >> q;

  unordered_map<int, int> freq;
  int unique = 0;

  while(q--){
    char type;
    cin >> type;

    if(type == '?'){
        cout << unique << '\n';
    } else {
      int x;
      cin >> x;

      if(type == '+'){
          if (freq[x] == 0) {
              unique++;
          }
          freq[x]++;
      } 
      else if(type == '-'){
          if(freq[x] > 0){
              freq[x]--;

              if(freq[x] == 0){
                unique--;
              }
          }
      }
    }
  }
}



void elementQuries(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  const int k = 1e5 + 1;
  int freq[k] = {0};

  for(int i = 0; i < q; i++){
    int t;
    cin >> t;

    int x;
    cin >> x;

    if(t == 1){
      freq[x]++;
    }else if(t == 2){
      if(freq[x]){
        freq[x]--;
      }
    }else{
      cout << freq[x] << "\n";
    }
  }
}


int main(){
  // characterFrequency();
  // digitFrequency();
  // checkAnagram();
  // stringDuplicates();
  // arrayDuplicates();
  // uniqueQueries();
  elementQuries();
}