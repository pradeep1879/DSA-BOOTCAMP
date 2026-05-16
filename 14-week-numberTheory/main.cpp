#include  <iostream>
using namespace std;


void factors(){
  int n;
    cin >> n;
    for (int i = 1; i * i <= n; i++){
      if (n % i == 0){
        int f1 = i;
        int f2 = n / i;
        
        if (f1 == f2){
          cout << f1 << endl;
        }else{
          cout << f1 << endl;
          cout << f2 << endl;
        }
      }
    }
}

void factorsI(){
  int n;
  cin >> n;
  
  int i = 1;
  while(i * i <= n){
    if(n % i == 0){
      int f1 = i;
      int f2 = n / i;

      cout << f1 << endl;
    }
    i++;
  }
  i--;
  while(i  >= 1){
    if(n % i == 0){
      int f1 = i;
      int f2 = n / i;

      if(f1 != f2){
        cout << f2 << endl;
      }
    }
    i--;
  }
}

int main(){
  // factors();
  factorsI();
}