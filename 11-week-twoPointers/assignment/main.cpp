#include <iostream>
using namespace std;


void maxSubArraySumOfSizeK(){
  int n, k;
  cin >> n >> k;
  int arr[n];
  for(int i = 0; i< n; i++){
    cin >> arr[i];
  }

  int ans = 0;
  for(int l = 0; l < n; l++){
    int sum = 0;
    for(int r = l; r < n; r++){
      sum += arr[r];

      if((r - l + 1) == k){
        ans = max(ans, sum);
      }
    }
  }

  cout << ans;
}

int main(){
  maxSubArraySumOfSizeK();
}