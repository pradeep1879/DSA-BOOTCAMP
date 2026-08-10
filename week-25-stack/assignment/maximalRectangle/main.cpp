#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


void maximalRectangleBrutForce(){
  int n;
  int arr[n];
  int ans = 0;

  for(int i = 0; i < n; i++){
    int h = arr[i];
    int w = 1;

    // expand in left
    int j = i - 1;
    while(j >= 0 and arr[j] >= arr[i]){
      w++;
      j--;
    }

    // expand in right
    while(j < n and arr[j] >= arr[i]){
      w++;
      j++;
    }

    ans = max(ans, h * w);
  }

  cout << ans;
}

int main(){
  maximalRectangleBrutForce();
}