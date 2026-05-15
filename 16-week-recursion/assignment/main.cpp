#include <iostream>
#include <vector>
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

void f10(int arr[], int n){
  if(n == 0){
    return;
  }
  cout << arr[n-1] << " ";
  f10(arr, n-1);
}

void printArrayReverse(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n;  i++){
    cin >> arr[i];
  }

  f10(arr, n);
}

void f11(int arr[], int n){
  if(n == 0) return;
  f11(arr, n-1);
  cout << arr[n-1] << " ";
}

void printArray(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n;  i++){
    cin >> arr[i];
  }

  f11(arr, n);
}

int f12(int arr[], int n){
  if(n == 1){
    return arr[0];
  }
  int smallAns = f12(arr, n-1);
  int ans = min(smallAns, arr[n - 1]);

  return ans;
}

void minimumElement(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n;  i++){
    cin >> arr[i];
  }
  cout << f12(arr, n);
}

int f13(int arr[], int n){
  if(n == 1){
    return arr[0];
  }
  int smallAns = f13(arr, n-1);
  int ans = max(smallAns, arr[n - 1]);

  return ans;
}

void maximumElement(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n;  i++){
    cin >> arr[i];
  }
  cout << f13(arr, n);
}

long long f14(int arr[], int n){
  if(n == 1){
    return arr[0];
  }

  long long smallAns = f14(arr, n-1);
  long long ans = smallAns + arr[n-1];

  return ans;
}

void sumOfArray(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n;  i++){
    cin >> arr[i];
  }
  
  cout << f14(arr, n);
}

long long f15(int arr[], int n, long long x){
  if(n == 0){
    return -1;
  }

  // check first n-1 elements
  int smallAns = f15(arr, n-1, x);

  // if found earlier, return it
  if(smallAns != -1){
    return smallAns;
  }
  // check current element
  if(arr[n-1] == x){
    return n; // for 1-base indexing
  }
  return -1;
}

void firstOccurenceOfX(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n;  i++){
    cin >> arr[i];
  }
  long long x;
  cin >> x;

  cout << f15(arr, n, x);
  
}


long long f16(int arr[], int n, long long x){
  if(n == 0){
    return -1;
  }
  
  if(arr[n-1] == x){
    return n; // for 1-base indexing
  }

  int smallAns = f16(arr, n-1, x);
  return smallAns;
}

void lastOccurenceOfX(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n;  i++){
    cin >> arr[i];
  }
  long long x;
  cin >> x;

  cout << f16(arr, n, x);
  
}

vector<int> ans;
void f17(int arr[], int n, long long x){
  if(n == 0){
    return;
  }
  
  f17(arr, n-1, x);

  if(arr[n-1] == x){
    ans.push_back(n);
  }
}

void indicesOfX(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n;  i++){
    cin >> arr[i];
  }
  long long x;
  cin >> x;

  f17(arr, n, x);

  // If not found
    if(ans.size() == 0){
      cout << -1;
      return;
    }

  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  }
}

void f18(int n, char src, char aux, char dest){
  if(n == 0) return;

  f18(n - 1, src, dest, aux);

  cout << "Move " << src << " to " << dest << endl;

  f18(n - 1, aux, src, dest);
}

void towerOfHanoi(){
  int n;
  cin >> n;
  char A = 'A';
  char B = 'B';
  char C = 'C';

  f18(n, A, B, C);
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
  // nthFibonacci();
  // printArrayReverse();
  // printArray();
  // minimumElement();
  // maximumElement();
  // sumOfArray();
  // firstOccurenceOfX();
  // lastOccurenceOfX();
  // indicesOfX();
  towerOfHanoi();
  return 0;
}