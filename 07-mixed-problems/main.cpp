#include <iostream>
using namespace std;



void sumOfNumbers(){
  int n;
  cin >> n;

  int sum = 0;
  while (n != 0){
    sum += n % 10;
    n = n / 10;
  }
  cout << sum << endl;
}


void alphabetCounter(){
  string s;
  cin >> s;

  int n = s.size();
  int i = 0;

  while(i < n){
    int count = 0;
    int j = i;
    while(j < n && s[i] == s[j]){
      count++;
      j++;
    }

    cout << s[i];
    if(count > 1){
      cout << count;
    }
    i = j;
  }
}

void longestWordInLine(){
  string s;
  getline(cin, s);

  int n = s.size();
  int i = 0;

  while(i < n){

    if(s[i] == ' '){
      i++;
      continue;
    }

    int count = 0;
    int j = i;
    int ans = 0;
    while(j < n && s[i] != ' '){
      count++;
      j++;
    }

    if(count > ans){
      ans = count;
    }
    i = j;
  }

}


void diagonalSum(){
  int n;
  cin >> n;
  int arr[n][n];

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> arr[i][j];
    }
  }

  int sum = 0;
  int i = 0, j = 0;
  while(i<n && j<n){
    sum += arr[i][j];
    i++;
    j++;
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout << arr[i][j];
    }
    cout << endl;
  }

  cout << sum;
}


int main(){
  // sumOfNumbers();
  // alphabetCounter();
  //  longestWordInLine()
  diagonalSum();
}