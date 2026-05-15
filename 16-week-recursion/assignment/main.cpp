#include <iostream>
using namespace std;

// Recursive function
void f(int n){
  if(n == 0) return;

  cout << n << endl;
  f(n - 1);
}

void printDecreasing(){
  int n;
  cin >> n;

  f(n);  // function call
}

void f1(int n){
  if(n == 0) return;

  f1(n - 1);
  cout << n << endl;
}

void printIncreasing(){
  int n;
  cin >> n;

  f1(n);
}

void f3(int n){
  if(n == 0) return;

  cout << n << endl;
  f3(n - 1);
  if(n != 1){
    cout << n << endl;
  }
}

void printZigZag(){
  int n;
  cin >> n;
  f3(n);
}


void f4(int n){
  if(n == 0) return;

  cout << n % 10;
  f4(n/10);
}

void printNumberInReverse(){
  int n;
  cin >> n;
  if(n == 0){
    cout << 0;
      return;
    }
  f4(n);
}

int f5 (int n){
  if(n == 0){
    return 1;
  } 
  int smallAns = f5(n - 1); 
  int ans = n * smallAns;

  return ans;
}

void factorial(){
  int n;
  cin >> n;

  if(n == 0){
    cout << 1;
    return;
  }

  cout << f5(n);
}

long long f6(int n){

  if(n == 1){
    return 1;
  }

  long long smallAns = f6(n - 1);
  long long ans = n + smallAns;

  return ans;
}

void sumOfFirstNnaturalNumbers(){
  long long n;
  cin >> n;

  cout << f6(n);
}

long long f7(long long x, long long y){
  if(y == 0){
    return 1;
  }

  long long smallAns = f7(x, y-1);
  long long ans = x * smallAns;
  return ans;
}

void power(){
  long long x, y;
  cin >> x >> y;

  cout << f7(x, y);
}

long long f8(long long n){
  if(n == 0){
    return 0;
  }

  long long smallAns = (n % 10);
  long long ans = f8(n/10);
  long long result = smallAns + ans;

  return result;
}

void sumOfDigits(){
  long long n;
  cin >> n;
  
  cout << f8(n);
}

long long f9(long long n){
  if(n == 0){
    return 0;
  }
  if(n == 1){
    return 1;
  }

  long long smallAns1 = f9(n - 1);
  long long smallAns2 = f9(n - 2);

  long long ans = smallAns1 + smallAns2;

  return ans;
}

void nthFibonacci(){
  long long n;
  cin >> n;

  cout << f9(n);
}

int main(){
  // printDecreasing();
  // printIncreasing ();
  // printZigZag();
  // printNumberInReverse();
  // factorial();
  // sumOfFirstNnaturalNumbers();
  // power();
  // sumOfDigits();
  nthFibonacci();
  return 0;
}