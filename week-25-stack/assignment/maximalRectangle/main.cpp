#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


#define int long long

// void maximalRectangleBrutForce(){
//   int n;
//   int arr[n];
//   int ans = 0;

//   for(int i = 0; i < n; i++){
//     int h = arr[i];
//     int w = 1;

//     // expand in left
//     int j = i - 1;
//     while(j >= 0 and arr[j] >= arr[i]){
//       w++;
//       j--;
//     }

//     // expand in right
//     while(j < n and arr[j] >= arr[i]){
//       w++;
//       j++;
//     }

//     ans = max(ans, h * w);
//   }

//   cout << ans;
// }




vector<int> getNextSmallerLeft(int A[], int n) {

    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
      // Remove elements that are >= current height
      while (!st.empty() && A[st.top()] >= A[i]) {
          st.pop();
      }

      if (st.empty()) {
          ans[i] = -1;
      } else {
          ans[i] = st.top();
      }

      // Store index, NOT value
      st.push(i);
    }

    return ans;
}


vector<int> getNextSmallerRight(int A[], int n) {

    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
      // Remove elements that are >= current height
      while (!st.empty() && A[st.top()] >= A[i]) {
          st.pop();
      }

      if (st.empty()) {
          ans[i] = n;
      } else {
          ans[i] = st.top();
      }

      // Store index, NOT value
      st.push(i);
    }

    return ans;
}


int max_area_histogram(int A[], int n){

    auto leftSmaller = getNextSmallerLeft(A, n);
    auto rightSmaller = getNextSmallerRight(A, n);

    int ans = 0;

    for (int i = 0; i < n; i++) {
      int h = A[i];
      int w = rightSmaller[i] - leftSmaller[i] - 1;
      ans = max(ans, h * w);
      
    }
  return ans;
}


signed main() {
  int n, m;
  cin >> n >> m;
  
  char A[n][m];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> A[i][j];
    }
  }

  int heights[m];
  for(int i = 0; i < m; i++){
    heights[i] = 0;
  }

  int ans = 0;

  for(int i = 0; i < n; i++){
    //update the heights array
    for(int j = 0; j < m; j++){
      if(A[i][j] == '0'){
        heights[j] = 0;
      }else{
        heights[j]++;
      }
    }

    ans = max(ans, max_area_histogram(heights, m));
  }
  cout << ans << "\n";
}


