#include <iostream>
#include <vector>

using namespace std;

int query(vector<int> &p, int l, int r ){
  if(l > r){
    return 0;
  }
  if (l == 0){
    return p[r];
  }else {
    return p[r] - p[l-1];
  }
}

void isEveryoneSame(){
  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  for(int i = 0 ; i < n; i++){
    cin >> arr[i];
  }

  vector<int> c(n-1);
  for(int i = 0; i < n - 1; i++){
    if(arr[i] == arr[i+1]){
      c[i] = 1;
    }else{
      c[i] = 0;
    }
  }

  vector<int> p(n-1);
  int sum = 0;
  for(int i = 0; i < n - 1; i++){
    sum += c[i];
    p[i] = sum;
  }
   for(int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    l--, r--;
  
    sum = query(p, l, r-1); 
    
    // if sum of lenght-1 is equal to sum then yes;
    if(sum == r-l){
      cout << "YES" << "\n";
    }else{
      cout << "NO" << "\n";
    }
  }
}


void isItSorted(){
  int n, q;
  cin >> n >> q;

  vector<int> arr(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  vector<int> c(n-1);
  for(int i = 0; i < n - 1; i++){
    if(arr[i] <= arr[i+1]){
      c[i] = 1;
    }else{
      c[i] = 0;
    }
  }

  vector<int> p(n-1);
  long long sum = 0;
  for(int i = 0; i < n - 1; i++){
    sum += c[i];
    p[i] = sum;
  }

  for(int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    l--, r--;
  
    sum = query(p, l, r-1); 
    
    // if sum of lenght-1 is equal to sum then yes;
    if(sum == r-l){
      cout << "YES" << "\n";
    }else{
      cout << "NO" << "\n";
    }
  }
}


void countAdjacentElements(){
  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  for(int i = 0 ; i < n; i++){
    cin >> arr[i];
  }

  vector<int> c(n-1);

  for(int i = 0; i < n - 1; i++){
    if(arr[i] == arr[i+1]){
      c[i] = 1;

    }else{
      c[i] = 0;
    }
  }

  vector<int> p(n-1);
  int sum = 0;
  for(int i = 0; i < n - 1; i++){
    sum += c[i];
    p[i] = sum;
  }
   for(int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    l--, r--;
  
    sum = query(p, l, r-1); 
    
    // if sum of lenght-1 is equal to sum then yes;
    cout << sum << "\n";
  }
}

void countLocalMaximas(){
  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  for(int i = 0 ; i < n; i++){
    cin >> arr[i];
  }

  vector<int> c(n-1);
  for(int i = 1; i < n - 1; i++){
    if(arr[i] > arr[i-1] and  arr[i] > arr[i+1]){
      c[i] = 1;
    }else{
      c[i] = 0;
    }
  }

  vector<int> p(n-1);
  int sum = 0;
  for(int i = 0; i < n - 1; i++){
    sum += c[i];
    p[i] = sum;
  }
   for(int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    l--, r--;
  
    sum = query(p, l, r-1); 
    
    // if sum of lenght-1 is equal to sum then yes;
    cout << sum << "\n";
  }
}




int main(){
  // isEveryoneSame();
  // isItSorted();
  // countAdjacentElements();
  countLocalMaximas();
}