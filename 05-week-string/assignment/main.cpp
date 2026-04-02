#include <iostream>
using namespace std;

void charToASCII(){
  char ch;
  cin >> ch;

  cout << int(ch) ;
}

void ASCIIToCharacter(){
  int a;
  cin >> a;
  cout << char(a);
}

void LowercaseUppercaseDigitSpecial(){
    char ch;
    cin >> ch;

    if( ch >= 'A' && ch <= 'Z'){
      cout << "Uppercase" << endl;
    }else if(ch >= 'a' && ch <= 'z'){
      cout << "Lowercase" << endl;
    }else if(ch >= '0' && ch <= '9'){
      cout << "Digit" << endl;
    }else{
      cout << "Special" << endl;
    }
}

void convertToLowercase(){
  char ch;
  cin >> ch;

  if(ch >= 'A' && ch <= 'Z'){
    ch += 32;
  }
  cout << ch;
}

void brothers(){
  string f1, l1;
  string f2, l2;
  cin >> f1 >> l1;
  cin >> f2 >> l2;

  if(l1 == l2){
    cout << "YES";
  }else{
    cout << "NO";
  }
}

void lexicographicalOrder(){
  string A, B;
  cin >> A >> B;

  int n = min(A.size(),B.size());

  for(int i=0; i<n; i++){
    if(A[i] < B[i]){
      cout << "A";
      return;
    }else if(A[i] > B[i]) {
      cout << "B";
      return;
    }
  }

  if(A.size() < B.size()){
    cout << "A";
  }else if(A.size() > B.size()){
    cout << "B";
  }else{
    cout << "Equal";
  }

}

void replaceCharacter(){
  string s;
  char c1, c2;
  cin >> s >> c1 >> c2;

  string n = s;
  for(int i=0; i<s.size(); i++){
    if(s[i] == c1){
      n[i] = c2;
    }
  }
  cout << n;
}

void removeCharacter(){
  string s;
  char x;
  cin >> s >> x;

  string n = "";
  for(int i=0; i<s.size(); i++){
    if(s[i] != x){
      n += s[i];
    }
  }
  cout << n << endl;
}

void trimSpace(){
  string S;
  getline(cin, S);

  string result = "";
  for(int i=0; i<S.size(); i++){
    if(S[i] != ' '){
      result += S[i];
    }
  }
  cout << result << endl;
}

void toggleCase(){
  string s;
  cin >> s;

  string result = "";
  for(int i=0; i<s.size(); i++){
    if(s[i] >= 'A' && s[i] <= 'Z'){
      s[i] += 32;
      result += s[i];
    }else if(s[i] >= 'a' && s[i] <= 'z'){
      s[i] -= 32;
      result += s[i];
    }
  }
  cout << result << endl;
}

void strongPassword(){
  string s;
  cin >> s;

  if(s.length() != 10){
    cout << "Weak";
    return;
  }

  bool haslowerCase = false;
  bool hasupperCase = false;
  bool hasDigit = false;
  bool hasSpecialChar = false;

  for(int i=0; i<s.size(); i++){
    if(s[i] >= 'a' && s[i] <= 'z'){
      haslowerCase = true;
    }else if(s[i] >= 'A' && s[i] <= 'Z'){
      hasupperCase = true;
    }else if(s[i] >= '0' && s[i] <= '9'){
      hasDigit = true;
    }else{ 
      hasSpecialChar = true;
    }
  }

  if(haslowerCase && hasupperCase && hasDigit && hasSpecialChar){
    cout << "Strong" << endl;
  }else {
    cout << "Weak" << endl;
  }
}

void reverse(){
  string s;
  cin >> s;
  string reverse = "";
  for(int i=s.size()-1; i>=0; i--){
    reverse += s[i];
  }
  cout << reverse << endl;
}

void palindrome(){
  string s;
  cin >> s;

  string x = s;
  string reverse = "";
  for(int i=s.size()-1; i>=0; i--){
    reverse += s[i];
  }

  if(x == reverse){
    cout << "YES" << endl;
  }else{
    cout << "No" << endl;
  }
}

void countWords(){
  string s;
  getline(cin,  s);

  int count = 0;
  for(int i=0; i<s.size(); i++){
    if(s[i] != ' ' && (i == 0 || s[i-1] == ' ')){
      count++;
    }
  }
  cout << count << endl;
}

int main(){
  // charToASCII();
  // ASCIIToCharacter();
  // LowercaseUppercaseDigitSpecial();
  // convertToLowercase();
  // brothers();
  // lexicographicalOrder();
  // replaceCharacter();
  // removeCharacter();
  // trimSpace();
  // toggleCase();
  // strongPassword();
  // reverse();
  // palindrome();
  countWords();
}