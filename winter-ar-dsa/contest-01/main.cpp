#include <iostream>
using namespace std;

int parkingFee() {
    int h1, m1, h2, m2;
    cin >> h1 >> m1;
    cin >> h2 >> m2;

    int startingMinute = h1 * 60 + m1;
    int endingMinute = h2 * 60 + m2;

    int duration = endingMinute - startingMinute;

    if (duration <= 120) {
        cout << 0 << endl;
    } else {
        int chargeableMinutes = duration - 120;
        int hours = (chargeableMinutes + 59) / 60;
        int fee = hours * 20;

        cout << min(fee, 100) << endl;
    }

    return 0;
}

int walkingTheWire(){
  int t;
  cin >> t;
  int n ;
  cin >> n;
  string str[n];

  for(int i = 0; i < t; i++){
    for(int j = 0; j < n; j++){
      cin >> str[j];
    }
    int peter = 0;
    int mj = n - 1;
    
  }

  

}

int main(){
  parkingFee();
}