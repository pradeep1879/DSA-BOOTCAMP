#include <iostream>
#include <cmath>
#include <vector>
using namespace std;



void naturalSum(){
    long long n;
    cin >> n;
    long long sum =  n*(n+1)/2;
    cout << sum << endl;
}



void intervelSum(){
  long long n;
  cin >> n;
  
  /**
   * S(n) = n*(n+1)/2
   * S(l, r) = S(r) - S(l-1)
   *
   *  S(l,r) = r(r+1)/2 - l(l-1)/2
   * another formula
   * S(l, r) = sum = average of numbers * count
   */
  
  while(n--){
    long long l, r;
    cin >> l >> r;

    cout << ((l + r)*(r-l+1))/2 << endl;
  }

}


void countingInterval() {
    int q;
    cin >> q;

    while(q--) {
        int t;
        long long l, r;
        cin >> t >> l >> r;

        if(l > r){
            cout << 0 << endl;
            continue;
        }

        long long ans = 0;

        if(t == 1) ans = r - l - 1;
        else if(t == 2) ans = r - l;
        else if(t == 3) ans = r - l;
        else if(t == 4) ans = r - l + 1;

        cout << max(0LL, ans) << endl;
    }
}


void countFactors(){
    long long n ;
    cin >> n;

    int count = 0;
    for(long long i = 1; i <= sqrt(n); i++){
      if(n % i == 0){
        long long j = n/i;
          if(i == j){
            count++;
            break;
          }
        count+= 2;
      }
    }
  
  cout << count << endl;
}


void amIPrime(){
  long long n;
  cin >> n;

  if(n <= 1){
      cout << "NO";
      return;
  }

  for(long long i = 2; i * i <= n; i++){
      if(n % i == 0){
          cout << "NO";
          return;
      }
  }

  cout << "YES";
}


bool isPrime(int x){
  if(x<=1) return false;

  for(int i = 2; i*i <= x; i++){
    if(x % i == 0){
      return false;
    }
  }
  return true;
}


void countPrimes(){
  int n;
  cin >> n;

  int count = 0;
  for(int i = 2; i<=n; i++){
    if(isPrime(i)){
      count++;
    }
  }
  cout << count << endl;
}


void printFactors(){
    long long n;
    cin >> n;

    vector<long long> largeFactors;

    for(long long i = 1; i * i <= n; i++){
        if(n % i == 0){
            cout << i << " ";

            if(i != n/i){
                largeFactors.push_back(n/i);
            }
        }
    }

    for(int i = largeFactors.size() - 1; i >= 0; i--){
        cout << largeFactors[i] << " ";
    }
}


void KthFactor(){
    long long n, k;
    cin >> n >> k;

    vector<long long> large;

    for(long long i = 1; i * i <= n; i++){
        if(n % i == 0){
            k--;

            if(k == 0){
                cout << i;
                return;
            }

            if(i != n/i){
                large.push_back(n/i);
            }
        }
    }

    for(int i = large.size() - 1; i >= 0; i--){
        k--;

        if(k == 0){
            cout << large[i];
            return;
        }
    }

    cout << -1;
}



int main(){
  // naturalSum();
  // intervelSum();
  // countingInterval();
  // countFactors();
  // amIPrime();
  // countPrimes();
  // printFactors();
  KthFactor();
}