#include <cctype>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;


void maxSubArraySumOfSizeK(){
  int n, k;
  cin >> n >> k;
  int arr[n];
  for(int i = 0; i< n; i++){
    cin >> arr[i];
  }

  int ans = 0;
  for(int l = 0; l < n; l++){
    int sum = 0;
    for(int r = l; r < n; r++){
      sum += arr[r];

      if((r - l + 1) == k){
        ans = max(ans, sum);
      }
    }
  }

  cout << ans;
}

//using sliding window method
void maxSubArraySumOfSizeKS(){
  int n,k;
  cin >> n >> k;
  int arr[n];
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }

  long long sum = 0;
  for(int i=0; i<k; i++){
    sum += arr[i];
  }
  long long ans = sum;

  for(int i = k; i < n; i++){
    sum += arr[i];
    sum -= arr[i - k];
    ans = max(ans, sum);
  }

  cout << ans << endl;

}


void countNumberOfDistinctIntegers(){
  int n,k;
  cin >> n >> k;
  int arr[n];
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }
  unordered_map<int, int> freq;

  //first window
  for(int i = 0; i < k; i++){
    freq[arr[i]]++;
  }
  cout << freq.size() << " ";

  // remaining window
  for(int i = k; i < n; i++){
    //remove left element
    freq[arr[i-k]]--;

    if(freq[arr[i-k]] == 0){
      freq.erase(arr[i-k]);
    }

    //add right element
    freq[arr[i]]++;
    
    cout << freq.size() << " ";
  }

}

bool isVowel(char l){

  l = tolower(l);

  if(l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u'){
    return true;
  }else{
    return false;
  }
}

void countVowels(){
  int n,k;
  cin >> n >> k;
  char arr[n];
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }

  int count = 0;
  for(int i = 0; i < k; i++){
    if(isVowel(arr[i])){
      count++;
    }
  }
  cout << count << " ";

  // remaining window
  for(int i = k; i < n; i++){
    if(isVowel(arr[i])){
      count++;
    }

    if(isVowel(arr[i-k])){
      count--;
    }
    cout << count << " ";
  }
}


// void countGoodNumbers(){     // this solution will give tle
//   int n, m, k;
//   cin >> n >> m >> k;
//   int arr[n];
//   for(int i = 0; i< n; i++){
//     cin >> arr[i];
//   }
//   int num[m];
//   for(int i = 0; i< m; i++){
//     cin >> num[i];
//   }
  

//   int count = 0;
//   //first window
//   for(int i = 0; i < k; i++){
//     for(int j = 0; j < m; j++){
//       if(arr[i] == num[j]){
//         count++;
//       }
//     }
//   }
//   cout << count << " ";

//   // remaining window
//   for(int i = k; i < n; i++){
//     for(int j = 0; j < m; j++){
//       if(arr[i] == num[j]){
//         count++;
//       }
//       if(arr[i-k] == num[j]){
//         count--;
//       }
//     }
//     cout << count << " ";
//   }

// }

void countGoodNumbers(){
  int n, m, k;
  cin >> n >> m >> k;
  int arr[n];
  for(int i = 0; i< n; i++){
    cin >> arr[i];
  }

  unordered_set<int> goodNumbers;
  for(int i = 0; i < m; i++){
    int x;
    cin >> x;
    goodNumbers.insert(x);
  }

  int count = 0;
  for(int i = 0; i < k; i++){
    if(goodNumbers.count(arr[i])){
      count++;
    }
  }

  cout << count << " ";

  for(int i = k; i<n; i++){
    if(goodNumbers.count(arr[i])){
      count++;
    }
    if(goodNumbers.count(arr[i-k])){
      count--;
    }
    cout << count << " ";
  }
}

void longestSubArrayWithSumLessThenK(){
  int n;
  long long k;
  cin >> n >> k;
  long long arr[n];
  for(int i = 0; i< n; i++){
    cin >> arr[i];
  }

  int maxLength = 0;
  long long sum = 0;
  int l = 0;

  for(int r = 0; r < n; r++){
    sum += arr[r];
    while(sum >= k){
      sum -= arr[l];
      l++;
    }
    maxLength = max(maxLength, (r - l + 1));
  }

  cout << maxLength ;
}

void longestSubstringWithoutRepeatingCharacters(){
  int n;
  cin >> n;

  string s;
  cin >> s;


  unordered_map<char,int> freq;
  int l = 0;
  int maxLength = 0;
  
  for(int r = 0; r < n; r++){
    freq[s[r]]++;

    // if duplicates exits
    while(freq[s[r]] > 1){
      freq[s[l]]--;
      l++;
    }
    maxLength = max(maxLength, r-l+1);
  }
  cout << maxLength;
}

void longestSubstringwithAtMostKDistinctCharacters(){
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  unordered_map<char,int> freq;
  int l = 0;
  int maxLength = 0;
  
  for(int r = 0; r < n; r++){
    freq[s[r]]++;

    // More than k distinct characters
    while(freq.size() > k){
      freq[s[l]]--;

      // remove characters if frequency becomes zero
      if(freq[s[l]] == 0){
        freq.erase(s[l]);
      }
      l++;
    }
    maxLength = max(maxLength, r-l+1);
  }
  cout << maxLength;
}

void countSubArraysWithSumGreaterThenK(){
  int n;
  long long k;
  cin >> n >> k;
  long long arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  long long sum = 0;
  long long count = 0;
  int l = 0;
  for(int r = 0; r < n; r++){
    sum += arr[r];

    // shrink window if invalid
    while(sum >= k){
      sum -= arr[l];
      l++;
    }
    //number of valid subarray ending at r
    count += (r-l+1);
  }

  cout << count;
}


int main(){
  // maxSubArraySumOfSizeK();
  // maxSubArraySumOfSizeKS();
  // countNumberOfDistinctIntegers();
  // countVowels();
  // countGoodNumbers();
  // longestSubArrayWithSumLessThenK();
  // longestSubstringWithoutRepeatingCharacters();
  // longestSubstringwithAtMostKDistinctCharacters();
  countSubArraysWithSumGreaterThenK();
}
