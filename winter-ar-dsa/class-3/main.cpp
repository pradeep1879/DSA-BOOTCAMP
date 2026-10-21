#include <iostream>
#include <vector>
using namespace std;

void printAllSubArray(){
  int n;
  cin >> n;
  
  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  for(int l = 0; l < n; l++){
    for(int r = l; r < n; r++){

      for(int j = l; j <= r; j++){
        cout << arr[j] << " ";
      }
      cout << endl;
    }
  }

}

void sumOfSubArraySeperately(){
  int n;
  cin >> n;
  
  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  
  for(int l = 0; l < n; l++){
    for(int r = l; r < n; r++){
      
      long long sum = 0;
      for(int j = l; j <= r; j++){
        sum += arr[j];
      }
      cout << sum << endl;
    }
  }
}

void sumOfAllSubArraysSeperatelyHard(){
  int n;
  cin >> n;
  vector<long long> arr(n);
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  
  for(int l = 0; l < n; l++){

    long long sum = 0;
    for(int r = l; r < n; r++){
      sum += arr[r];
      cout << sum << '\n';
    }

  }
}


void sumOfAllSubarraysEasy(){
  int n;
  cin >> n;
  vector<long long> arr(n+1);
  for(int i=1; i<=n; i++){
    cin >> arr[i];
  }
  long long ans = 0;
  for(int l=1; l<=n; l++){
    for(int r=l; r<=n; r++){
      long long sum = 0;
      for(int i=l; i<=r; i++){
        sum += arr[i];
      }
      ans += sum;
    }
  }
  cout << ans << endl;

}

void sumOfAllSubArraysMedium(){
  int n;
  cin >> n;
  vector<long long> arr(n);
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  
  long long ans = 0;
  for(int l = 0; l < n; l++){

    long long sum = 0;
    for(int r = l; r < n; r++){
      sum += arr[r];
    }
    ans += sum;
  }
  cout << ans << '\n';
}


void sumOfAllSubarraysHard(){
  int n;
  cin >> n;

  vector<long long> arr(n);
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  long long ans = 0;
  for(int i = 0; i < n; i++){
    ans += arr[i] * (n - i) * (i + 1);
  }
  cout << ans << '\n';

}

void maximumOfAllSubarrays(){
  int n;
  cin >> n;
  
  vector<long long> arr(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  
  for(int l = 0; l < n; l++){
    for(int r = l; r < n; r++){
      
      int mx = arr[l];
      for(int j = l; j <= r; j++){
        if(arr[j] > mx){
          mx = arr[j];
        }
      }
      cout << mx << endl;
    }
  }
}


void rangeSumQuery(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  long long preFixSum[n];
  long long sum = 0;
  for(int i = 0; i < n; i++)  {
    sum += arr[i];
    preFixSum[i] = sum;
  }
  
  int q;
  cin >> q;
  while(q--){
    int l, r;
    cin >> l >> r;

    l--;
    r--;

    if(l == 0){
      cout << preFixSum[r] << endl;
    }else{
      cout << preFixSum[r] - preFixSum[l - 1] << endl;
    }
  }

}


void evenSumQuery(){
  int n;
  cin >> n;
  vector<long long> arr(n+1);
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
  }

  vector<long long> preFixSum(n+1, 0);
  long long sum = 0;
  for(int i = 1; i <= n; i++)  {
    if(i % 2 == 0){
      sum += arr[i];
    }else{
      sum += 0;
    }
    preFixSum[i] = sum;
  }

  int q;
  cin >> q;
  while(q--){
    int l, r;
    cin >> l >> r;

  if(l == 0){
      cout << preFixSum[r] << endl;
    }else{
      cout << preFixSum[r] - preFixSum[l - 1] << endl;
    }
    
  }
}

bool isVowel (char c){
  return (c == 'a' or c == 'e' or c =='i' or c =='o' or c == 'u');
}

void countVowels(){
  int n;
  cin >> n;

  string s;
  cin >> s;
  

  vector<int> prefix(n);
  long long sum = 0;
  for(int i = 0; i < n; i++){
    if(isVowel(s[i])){
      sum++ ;
    }
    prefix[i] = sum;
  }

  int q;
  cin >> q;
  while(q--){
    int l, r;
    cin >> l >>r;
    l--;
    r--;

    if(l == 0){
      cout << prefix[r] << "\n";
    }else {
      cout << prefix[r] - prefix[l-1] << "\n";
    }
  }

}

void rangeSumOfSquares(){
  int n, q;
  cin >> n >> q;

  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  vector<long long> prefix(n,0);
  long long sum = 0;
  for(int i = 0; i < n; i++){
    sum += 1LL * arr[i] * arr[i];
    prefix[i] = sum;
  }

  while(q--){
    int l, r;
    cin >> l >>r;
    l--;
    r--;

    if(l == 0){
      cout << prefix[r] << "\n";
    }else {
      cout << prefix[r] - prefix[l-1] << "\n";
    }
  }
}

bool digitSum(int x, int k){
    int sum = 0;
    while (x > 0){
        sum += x % 10;
        x /= 10;
    }
    return sum == k ;
}

void countNumbersWithDigitSumK(){
  int n, q, k;
  cin >> n >> q >> k;

  vector<long long> arr(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  vector<long long> prefix(n);
  long long sum = 0;
  for(int i = 0; i < n; i++){
    if(digitSum(arr[i],k)){
      sum++;
    }
    prefix[i] = sum;
  }
  while(q--){
    int l, r;
    cin >> l >>r;
    l--;
    r--;

    if(l == 0){
      cout << prefix[r] << "\n";
    }else {
      cout << prefix[r] - prefix[l-1] << "\n";
    }
  }
}

bool countFactors(int x, int k){
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

    return count == k;
}

void countFactorsWithExactalyKFactors(){
  int n, q, k;
  cin >> n >> q >> k;

  vector<long long> arr(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  vector<long long> prefix(n);
  long long sum = 0;
  for(int i = 0; i < n; i++){
    if(countFactors(arr[i],k)){
      sum++;
    }
    prefix[i] = sum;
  }
  while(q--){
    int l, r;
    cin >> l >>r;
    l--;
    r--;

    if(l == 0){
      cout << prefix[r] << "\n";
    }else {
      cout << prefix[r] - prefix[l-1] << "\n";
    }
  }

}


void alternatingRangeSum(){
  int n, q;
  cin >> n >> q;

  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  vector<int> prefix(n);
  long long sum = 0;
  for(int i = 0; i < n; i++){
    if(i % 2 == 0){
      sum += arr[i];
    }else{
      sum -= arr[i];
    }

    prefix[i] = sum;
  }

   while (q--) {
    int l, r;
    cin >> l >> r;

    l--;
    r--;

    long long ans = prefix[r];

    if(l > 0) {
        ans -= prefix[l - 1];
    }

    // adjust the sign when the starting index is odd
    if(l % 2 != 0) {
        ans = -ans;
    }

    cout << ans << "\n";
    }

}

int main(){
  // printAllSubArray();
  // sumOfSubArraySeperately();
  // sumOfAllSubArraysSeperatelyHard();
  // sumOfAllSubarraysEasy();
  // sumOfAllSubarraysHard();
  // maximumOfAllSubarrays();
  // sumOfAllSubArraysMedium();

  // rangeSumQuery();
  // evenSumQuery();
  // countVowels();
//  rangeSumOfSquares();
// countNumbersWithDigitSumK();

  // countFactorsWithExactalyKFactors();
  alternatingRangeSum();


}