#include <iostream>
using namespace std;


void rangeSumProblem(){
  int n;
  cin >>n;

  int arr[n];
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }

  int q;
  cin >> q;
  for (int i=0; i<q; i++){
    int l, r;
    cin >> l >> r;
    int sum = 0;
    for(int j=l; j<=r; j++){
      sum += arr[j];
    }

    cout << sum << endl;
  }

}

int main(){


}