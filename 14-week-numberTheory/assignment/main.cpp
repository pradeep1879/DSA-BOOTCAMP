#include <iostream>
#include <vector>
using namespace std;

void factorsOfAllNumbers(){
  int n;
  cin >> n;

  vector<int> factor[n+1];
  for(int i = 1; i <= n; i++){
    for(int j = i; j <= n; j+=i){
      factor[j].push_back(i);
    }
  }

  // print factors
  for(int i = 1; i<=n; i++){
    for(int x: factor[i]){
      cout << x << " ";
    }
    cout << endl;
  }
}

// void factorCountQueries(){  /// this solution will give tle;
//   int q;
//   cin >> q;
  
//   while(q--){
//     int n;
//     cin >> n;
//     vector<int> factor[n+1];
//     for(int i = 1; i <= n; i++){
//       for(int j = i; j <= n; j+=i){
//         factor[j].push_back(i);
//       }
//     }
    
//     // print factors
//     cout << factor[n].size() << endl;
//   }
// }

void factorCountQueries(){
  int q;
  cin >> q;
  
  while(q--){
    int n;
    cin >> n;
    vector<int> factor(n + 1, 0);
    for(int i = 1; i <= n; i++){
      for(int j = i; j <= n; j+=i){
        factor[j]++;
      }
    }
    
    // print factors
    cout << factor[n] << endl;
  }

}


void printPrimesFrom1ToN(){
  int n;
  cin >> n;
  vector<bool> isPrime(n+1, true);

  if(n >= 0){
      isPrime[0] = false;
    }

    if(n >= 1){
      isPrime[1] = false;
    }


  for(int i = 2; i * i <= n; i++){
    if(isPrime[i]){
      for(int j = i * i; j <= n; j+=i){
        isPrime[j] =  false;
      }
    }
  }

  // print primes
  int count = 0;
  for(int i = 2; i <= n; i++){
    if(isPrime[i]){
      cout << i << " ";
      count++;
    }
  }
  cout << endl;
  cout << count << endl;

}

void primeQueries(){
  int q;
  cin >> q;

    vector<int> queries(q);
    int mx = 0;
    
    // read queries and find maximum
    for(int i = 0; i < q;  i++){
      cin >> queries[i];
      mx = max(mx, queries[i]);
    }

    // build seive once
    vector<bool> isPrime(mx+1, true);
    
    if(mx >= 0){
      isPrime[0] = false;
    }
    
    if(mx >= 1){
      isPrime[1] = false;
    }
    
    
    for(int i = 2; i * i <= mx; i++){
      if(isPrime[i]){
        for(int j = i * i; j <= mx; j+=i){
          isPrime[j] =  false;
        }
      }
    }
    
    for(int x: queries){
      if(isPrime[x]){
        cout << "YES\n";
      }else{
        cout << "NO\n";
      }
    }

}


void goodNumberQueries(){
 int q;
  cin >> q;

    vector<int> queries(q);
    int mx = 0;
    
    // read queries and find maximum
    for(int i = 0; i < q;  i++){
      cin >> queries[i];
      mx = max(mx, queries[i]);
    }

    // build seive once
    vector<bool> isPrime(mx+1, true);
    
    if(mx >= 0){
      isPrime[0] = false;
    }
    
    if(mx >= 1){
      isPrime[1] = false;
    }
    
    
    for(int i = 2; i * i <= mx; i++){
      if(isPrime[i]){
        for(int j = i * i; j <= mx; j+=i){
          isPrime[j] =  false;
        }
      }
    }
    
    vector<int> divisorCount(mx+1, 0);
    for(int i = 1; i <= mx; i++){
      for(int j = i; j <= mx; j+=i){
        divisorCount[j]++;
      }
    }

    for(int x: queries){
      int divisors = divisorCount[x];
      if(isPrime[divisors]){
        cout << "YES\n";
      }else{
        cout << "NO\n";
      }
    }
}

void primeRangeQueries(){
  int n, q;
  cin >> n >> q;

  vector<bool> isPrime(n+1, true);
   if(n >= 0){
      isPrime[0] = false;
    }
    
    if(n >= 1){
      isPrime[1] = false;
    }

   for(int i = 2; i * i <= n; i++){ 
      if(isPrime[i]){
        for(int j = i * i; j <= n; j+=i){
          isPrime[j] =  false;
        }
      }
    }

    vector<int> pre(n+1);
    for(int i = 1; i <= n; i++){
      pre[i] = pre[i-1] + isPrime[i];
    }

    while(q--){
      int l,r;
      cin >> l >> r;

      if(l == 0){
        cout << pre[r] << "\n";
      }else{
        cout << pre[r] - pre[l-1] << "\n";
      }
    }
  
}

int main(){
  ios::sync_with_stdio(false);
    cin.tie(NULL);
  // factorsOfAllNumbers();
  // factorCountQueries();
  // printPrimesFrom1ToN();
  // primeQueries();
  // goodNumberQueries();
  primeRangeQueries();

}