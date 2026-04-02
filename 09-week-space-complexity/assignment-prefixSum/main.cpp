#include <iostream>
#include <vector>
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


void rangeSumQueryOptimised(){
  int n;
  cin >>n;

  vector<int> arr(n);
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }

  vector<int> prefix(n);
  prefix[0] = arr[0];
  for(int i = 1; i < n; i++){
    prefix[i] = prefix[i - 1] + arr[i];
  }

  int q;
  cin >> q;
  while(q--){
    int l, r;
    cin >> l >> r;

    // If array is 1-based indexing
    l--; r--;
    int sum = prefix[r];
    if(l > 0){
      sum -= prefix[l-1];
    }

    cout << sum << endl;
  }
}



void evenSumQuery(){
  int n;
  cin >>n;

  vector<long long> arr(n+1); // 1-based indexing
  for(int i = 1; i<=n; i++){
    cin >> arr[i];
  }

  // prefix sum for even indices
  vector<long long> evenPrefix(n+1, 0);

  for(int i = 1; i <= n; i++){
    evenPrefix[i] = evenPrefix[i-1];

    if(i % 2 == 0){
      evenPrefix[i] += arr[i];
    }
  }
  int q;
  cin >> q;
  
  while (q--) {
    int l, r;
    cin >> l >> r;
    
    long long sum = evenPrefix[r] - evenPrefix[l - 1];
    cout << sum << endl;
  }


}


bool isVowel (char c){
  return (c == 'a' || c == 'e' || c =='i' || c =='o' || c == 'u');
}

void countVowels(){
  int n;
  cin >> n;
  string s;
  cin >> s;

  //1-based indexing -> shift string
   s = " " + s;
  
   vector<int>prefix(n+1, 0);

   // build prefix
   for(int i=1; i<=n; i++){
    prefix[i] = prefix[i-1];

    if(isVowel(s[i])){
      prefix[i]++;
    }
   }

   int q;
   cin >> q;
   while(q--){
    int l, r;
    cin >> l >> r;

    int ans = prefix[r] - prefix[l-1];
    cout << ans << endl;
   }

}




void rangeSumOfSquares(){
  int n, q;
  cin >> n >> q;
  vector <long long> arr(n+1);
  for(int i=1; i<=n; i++){
    cin >> arr[i];
  }

  // prefix sum for (range sum of squares)
  vector <long long> prefixOfSquare(n+1, 0);
  for(int i=1; i<=n; i++){
    prefixOfSquare[i] = (prefixOfSquare[i-1]) + (arr[i])*(arr[i]);
  }

  while (q--) { 
    int l, r;
    cin >> l >> r;
    
    long long sum = prefixOfSquare[r] - prefixOfSquare[l - 1];
    cout << sum << endl;
  }
}



int digitSum(int x){
    int sum = 0;
    while (x > 0){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

void countNumbersWithDigitSumK(){
  int n, q, k;
  cin >> n >> q >> k;

  vector <long long> arr(n+1);
  for(int i=1; i<=n; i++){
    cin >> arr[i];
  }

  vector<int> prefix(n+1, 0);
  for(int i =1; i<=n; i++){
    prefix[i] = prefix[i-1];
    if(digitSum(arr[i]) == k){
      prefix[i]++;
    }
  }

  while(q--){
    int l, r;
    cin >> l >> r;

    int ans = prefix[r] - prefix[l-1];
    cout << ans << endl;
  }
}




int countFactors(int x){
    int count = 0;

    for(int i = 1; i * i <= x; i++){
        if(x % i == 0){
            if(i * i == x){
                count += 1;   // perfect square
            } else {
                count += 2;   // pair factors
            }
        }
    }

    return count;
}

void countNumbersWithExactlyKFactors(){
  int n, q, k;
  cin >> n >> q >> k;

  vector<long long> arr(n+1);
  for(int i=1; i<=n; i++){
    cin >> arr[i];
  }

  vector<long long> prefix(n+1, 0);
  for(int i=1; i<=n; i++){
    prefix[i] = prefix[i-1];

    if(countFactors(arr[i]) == k){
      prefix[i]++;
    }
  }

  while(q--){
    int l, r;
    cin >> l >> r;

    int ans = prefix[r] - prefix[l-1];
    cout << ans << endl;
  }

}




void alternatingRangeSum(){
  int n, q;
  cin >> n >> q;

  vector<long long> arr(n+1);
  vector<long long> newArr(n+1);
  for(int i=1; i<=n; i++){
    cin >> arr[i];
    if(i % 2 == 0){
      newArr[i] = -arr[i];
    }else{
      newArr[i] = arr[i];
    }
  }

  
  vector<long long> prefix(n+1, 0);
  prefix[0] = newArr[0];
  for(int i = 1; i<=n; i++){
    prefix[i] = prefix[i - 1] + newArr[i];
  }

  while (q--){
    int l, r;
    cin >> l >> r;
    long long ans = prefix[r] - prefix[l-1];
    if(l % 2 == 0){
      ans = -ans;
    }
    cout << ans << endl;
  }
  
}





int main(){
  // rangeSumProblem();
  // rangeSumQueryOptimised();
  // evenSumQuery();
  // countVowels();
  // rangeSumOfSquares();
  // countNumbersWithDigitSumK();
  // countNumbersWithExactlyKFactors();
  alternatingRangeSum();
}