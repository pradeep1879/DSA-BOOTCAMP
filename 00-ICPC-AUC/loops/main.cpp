#include <iostream>
using namespace std;


void oneToN(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cout << i << endl;
  }
}


void evenNumbers(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    if(i % 2 == 0){
      cout << i << endl;
    }
  }
}


void evenOddPositiveNegative(){
  int n;
  cin >> n;

  int even = 0;
  int odd =  0;
  int positive = 0;
  int negative = 0;

  while(n--){
    int x;
    cin >> x;
 
      if(x % 2 == 0){
        even++;
      } 
      if(x % 2 != 0){
        odd++;
      } 
      if(x > 0){
        positive++;
      }
      if(x < 0){
        negative++;
      }
  
  }
  cout << "Even: " << even << endl;
  cout << "Odd: " << odd << endl;
  cout << "Positive: " << positive << endl;
  cout << "Negative: " << negative << endl;
}

int main(){
  // oneToN();
  // evenNumbers();
  evenOddPositiveNegative();
}