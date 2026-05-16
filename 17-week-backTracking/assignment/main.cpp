#include <iostream>
#include <vector>
using namespace std;


void f(int curr, int n, vector<int> &path){
  if(curr == n){
    // print the path
    for(int i = 0; i < path.size(); i++){
      cout << path[i] << " ";
    }
    cout << endl;
    return;
  }
  if(curr > n) return;

  // jump1
  path.push_back(1);
  f(curr + 1, n, path);
  path.pop_back();

  // jump2
  path.push_back(2);
  f(curr + 2, n, path);
  path.pop_back();

}

void climbStairsI(){
  int n;
  cin >> n;

  vector<int>path;
  f(0,n,path);
}

void f1(int curr, int n, int k, vector<int> &path){
  if(curr == n){
    // print here
    for(int i = 0; i < path.size(); i++){
      cout << path[i] << " ";
    }
    cout << endl;
    return;
  }
  if(curr > n) return;

  for(int i = 1; i <= k; i++){
    path.push_back(i);
    f1(curr + i, n, k, path);
    path.pop_back();
  }
}

void climbStairsII(){
  int n, k;
  cin >> n >> k;

  vector<int>path;
  f1(0, n, k, path);
}

void f2(int i, int j, int n, int m, vector<int> &path){

  if(i >= n || j >= m){
    return;
  }

  if(i == n-1 && j == m-1){
    // print here
    for(char ch: path){
      cout << ch;
    }
    cout << endl;
    return;
  }

  // right side (R)
  path.push_back('R');
  f2(i, j+1, n, m, path);
  path.pop_back();

  // down side (D)
  path.push_back('D');
  f2(i+1, j, n, m, path);
  path.pop_back();

}

void printAllPathsI(){
  int n, m;
  cin >> n >> m;
  
  vector<int> path;
  f2(0, 0, n, m, path);
}


void f3(int i, int j, int n, int m, 
  vector<vector<int>> &grid, string &path){

  if(i >= n || j >= m){
    return;
  }
  // blocked cell
  if(grid[i][j] == 1){
    return;
  }

  if(i == n-1 && j == m-1){
    // print here
    cout << path << endl;
    return;
  }

  // right side (R)
  path.push_back('R');
  f3(i, j+1, n, m, grid, path);
  path.pop_back();
  
  // down side (D)
  path.push_back('D');
  f3(i+1, j, n, m, grid, path);
  path.pop_back();

}

void printAllPathsII(){
  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> grid[i][j];
    }
  }
  
  string path = "";
  f3(0, 0, n, m, grid, path);
}

void f4(int idx,int arr[], int n, vector<int> &path){
  if(idx == n){
    for(int i = 0; i < path.size(); i++){
      cout << path[i] << " ";
    }
    cout << endl;
    return;
  }

  // Take
  
  path.push_back(arr[idx]);
  f4(idx+1, arr, n, path);
  path.pop_back();
  
  // Not take
  f4(idx+1, arr, n, path);
}

void printAllSubsequences(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  vector<int> path;
  f4(0, arr, n, path);
}

vector<vector<int>> ans;

void f5(int idx, int arr[], int n, long long k, long long sum, vector<int> &path){
  if(idx == n){
    if(sum == k){
      ans.push_back(path);
    }
      return;
    }
    
    // Take
    
    path.push_back(arr[idx]);
    f5(idx+1, arr, n, k, sum + arr[idx], path);
    path.pop_back();
    
    // Not take
    f5(idx+1, arr, n, k, sum, path);
}

void subsequencesWithSumK(){
  int n;
  long long k;
  cin >> n >> k;
  int arr[n];
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }
  
  vector<int> path;
  f5(0, arr, n, k, 0, path);

  // print count first
  cout << ans.size() << endl;

  //print all subsequences
  for(auto &v : ans){
    for(int x: v){
      cout << x << " ";
    }
    cout << endl;
  }
}

int main(){
  // climbStairsI();
  // climbStairsII();
  // printAllPathsI();
  // printAllPathsII();
  // printAllSubsequences();
  subsequencesWithSumK();
}