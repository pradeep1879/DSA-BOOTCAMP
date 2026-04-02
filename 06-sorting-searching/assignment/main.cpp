#include <iostream>
#include <vector>
using namespace std;

//Determine whether 𝑋 exists in the array.
void linearSearch(){
  int n;
  cin >> n;
  
  vector<int> arr(n);
  
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  
  int x;
  cin >> x;
  

  for(int i=0; i<n; i++){
    if(arr[i] == x){
      cout << "YES";
      return;
    }      
  }
  cout << "NO";
}

void binarySearch(){
  int n;
  cin >> n;
  
  vector<int> arr(n);
  
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  
  int x;
  cin >> x;
  int target = x;
  int l = 0;
  int r = n-1;
  bool flag = false;

  while(l <=r){
    int mid = (l + r)/2;
    if(arr[mid] == target){
      flag = true;
      break;
    }else if(arr[mid] > target){
      r = mid - 1;
    }else{
      l = mid + 1;
    }
  }
  if(flag){
    cout << "YES";
  }else{
    cout << "NO";
  }
}

void binarySearchForString(){
  int n;
  cin >> n;
  vector<string> s(n);

  for(int i=0; i<n; i++){
    cin >> s[i];
  }
  string x;
  cin >> x;
  string target = x;
  int l = 0;
  int r = n - 1;
  bool flag = false;
  
  while(l <= r){
    int mid = (l + r)/2;
    if(s[mid] == x){
      flag = true;
      break;
    }else if(s[mid] > x){
      r = mid - 1;
    }else{
      l = mid + 1;
    }

  }

  if(flag){
    cout << "YES";
  }else{
    cout << "NO";
  }
}



void bubbleSortTrace(){
  int n;
  cin >> n;
  vector<int> arr(n);

  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  int pass = 1;

  for(int i=n-1; i>0; i--){
    int count = 0;
    for(int j=0; j<i; j++){
      if(arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
        count ++; 
      }
    }
    
    cout << "Pass " << pass << ": ";
    for(int k=0; k<n; k++){
      cout << arr[k] << " ";
    }
    
    cout << " , " << "swaps" << " = " << count << endl;
    
    pass++;
    if(count == 0) break; // Already sorted
  }
  
}

void mergeTwoSortedArray(){
  int n,m;
  cin >> n >> m;

  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  vector<int> b(m);
  for(int i=0; i<m; i++){
    cin >> b[i];
  }
 
  vector<int> c(n+m);
  int i=0, j=0, k=0;

  while(i < n && j < m){
    if(a[i] < b[j]){
      c[k] = a[i];
      i++;
    }else{
      c[k] = b[j];
      j++;
    }
    k++;
  }

  while(i < n ){
    c[k] = a[i];
    i++;
    k++;
  }
  while(j < m ){
    c[k] = b[j];
    j++;
    k++;
  }

  for(int t=0; t<(n+m); t++){
    cout << c[t] << " ";
  }
}

int main(){
// linearSearch();
// binarySearch();
// binarySearchForString();
// bubbleSortTrace();
mergeTwoSortedArray();
}