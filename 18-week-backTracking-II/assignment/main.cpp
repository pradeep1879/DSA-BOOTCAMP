#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int count = 0;

void f(int open, int close, int n, string &path)
{
  if (open == n && close == n)
  {
    // pring path
    for (char s : path)
    {
      cout << s;
    }
    cout << endl;
    return;
  }

  if (open < n)
  {
    path += '(';
    f(open + 1, close, n, path);
    path.pop_back();
  }

  if (open > close)
  {
    path += ')';
    f(open, close + 1, n, path);
    path.pop_back();
  }
}

void generateParenthese()
{
  int n;
  cin >> n;

  string path = "";

  f(0, 0, n, path);
}

// Mapping digits to letters
unordered_map<int, string> keypad;

int cnt = 0;

void f1(string s, int idx, string &path)
{
  if (idx == s.size())
  {
    // print
    cout << path << endl;
    cnt++;
    return;
  }

  char digit = s[idx] - '0';

  string choices = keypad[digit];

  for (char ch : choices)
  {
    path.push_back(ch);
    f1(s, idx + 1, path);
    path.pop_back();
  }
}

void keypadCombinations()
{
  string s;
  cin >> s;

  string path = "";

  f1(s, 0, path);
}

vector<string> ans;

char getAlphabet(int num){
  return 'a' + num - 1;
}

void f2(string &s, int idx, string &path){

    if(idx == s.size()){
      ans.push_back(path);
      return;
    }

    if(s[idx] == '0') return;

    // take 1 digit
    int num1 = s[idx] - '0';

    path.push_back(getAlphabet(num1));

    f2(s, idx + 1, path);

    path.pop_back();

    // take 2 digits
    if(idx + 1 < s.size()){
        int num2 = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
        if(num2 <= 26){
          path.push_back(getAlphabet(num2));
          f2(s, idx + 2, path);
          path.pop_back();
        }
    }
}

void allEncodings(){

    string s;
    cin >> s;

    string path = "";

    f2(s, 0, path);

    // print count first
    cout << ans.size() << endl;

    // then print encodings
    for(string str : ans){
      cout << str << endl;
    }
}



vector<vector<int>> ans1;

void f(vector<int>& arr, int idx, int target, vector<int>& path){

  // target achieved
  if(target == 0){
      ans1.push_back(path);
      return;
  }

  // out of bounds
  if(idx == arr.size()) return;

  // take current element

  if(arr[idx] <= target){
      path.push_back(arr[idx]);
      // stay on same index
      f(arr, idx, target - arr[idx], path);
      path.pop_back();
  }

  // skip current element

  f(arr, idx + 1, target, path);
}


void combinationSum(){

    int n, target;
    cin >> n >> target;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }

    vector<int> path;

    f(arr, 0, target, path);

    // print count
    cout << ans1.size() << endl;

    // print combinations
    for(auto vec : ans1){
      cout << vec.size() << " ";

        for(int x : vec){
           cout << x << " ";
        }

      cout << endl;
    }
}


int main()
{
  keypad[2] = "abc";
  keypad[3] = "def";
  keypad[4] = "ghi";
  keypad[5] = "jkl";
  keypad[6] = "mno";
  keypad[7] = "pqrs";
  keypad[8] = "tuv";
  keypad[9] = "wxyz";
  // generateParenthese();
  // keypadCombinations();
  // allEncodings();
  combinationSum();
}