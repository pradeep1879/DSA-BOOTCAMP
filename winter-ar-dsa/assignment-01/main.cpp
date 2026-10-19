#include <iostream>
#include <vector>
using namespace std;

int sum() {
    int n;
    cin >> n;
    
    long long ans = (n*(n + 1)) / 2;
    cout << ans << "\n";

    return 0;
}

int intervalSum(){
  int q;
  cin >> q;
  while (q--)
  {
    long long l, r;
    cin >> l >> r;
    
    long long ans = ((l + r)*(r-l+1))/2;

    cout << ans << endl;
  }
  return 0;
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

int countingFactors(){
  long long n;
  cin >> n;

  long long count = 0;
  for(long long i = 1; i * i <= n; i++){
    if(n % i == 0){
        long long j = n/i;
          if(i == j){
            count++;
            break;
          }
        count+= 2;
      }
  }
  cout << count << "\n";
  return count;
}

void amIPrime(){
  long long n;
  cin >> n;
  
  long long count = 0;
  for(long long i = 1; i * i <= n; i++){
    if(n % i == 0){
        long long j = n/i;
          if(i == j){
            count++;
            break;
          }
        count+= 2;
      }
  }
  if(count == 2){
    cout << "YES" << "\n";
  }else{
    cout << "NO" << "\n";
  }

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

int main(){
  // sum();
  // intervalSum();
  // countingInterval();
  // countingFactors();
  // amIPrime();
  // countPrimes();
  printFactors();
}