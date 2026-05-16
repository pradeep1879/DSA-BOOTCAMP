#include <iostream>
using namespace std;

int f(int n){
  
  if(n == 0){
    return 1;
  }

  int smallAns = f(n-1);
  int ans = n * smallAns;

  
  return ans;
}

int main(){
  f(0);
}