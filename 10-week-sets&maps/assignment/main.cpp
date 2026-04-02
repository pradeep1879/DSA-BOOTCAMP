#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

/*

1. Count Distinct Elements

Problem:
Given an array, count how many distinct (unique) elements are present.

Approach:
- Use unordered_set (stores only unique elements)
- Insert all elements
- Answer = size of set

Time: O(n)
*/



void countDistinct() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];

  unordered_set<int> s;

  for (int x : arr) s.insert(x);

  cout << s.size() << endl;
}

/*

2. Search Queries (Value → Index)

Problem:
Given array and queries, for each query find index of element.

Approach:
- Store value → index in map
- Answer each query in O(1)

Time: O(n + q)
*/



void searchQueriesIII(){
  int n, q;
  cin >> n >> q;

  unordered_map<int, int> pos;

  for(int i=1; i<=n; i++){
    int x; cin >> x;
    pos[x] = i;
  }

  while(q--){
    int x; cin >> x;
    cout << (pos.count(x) ? pos[x] : -1) << endl;
  }
}

/*

3. Count Distinct Queries (Remove ALL)

Operations:
1 x → insert
2 x → remove ALL x
3 → count distinct
4 x → check existence

Approach:
- map stores frequency
- distinctCount tracks unique values
*/



void countDistinctQueries(){
  int q; cin >> q;

  unordered_map<int,int> mp;
  int distinctCount = 0;

  while(q--){
    int type; cin >> type;

    if(type == 1){
      int x; cin >> x;
      if(!mp.count(x)) distinctCount++;
      mp[x]++;
    }
    else if(type == 2){
      int x; cin >> x;
      if(mp.count(x)){
        mp.erase(x);
        distinctCount--;
      }
    }
    else if(type == 3){
      cout << distinctCount << endl;
    }
    else{
      int x; cin >> x;
      cout << (mp.count(x) ? "YES\n" : "NO\n");
    }
  }
}

/*

4. Count Distinct Queries II (Remove ONE)

Difference:
- Remove only ONE occurrence

Approach:
- Decrease freq
- Remove key only when freq = 0
*/



void countDistinctQueriesII(){
  int q; cin >> q;

  unordered_map<int,int> mp;
  int distinctCount = 0;

  while(q--){
    int type; cin >> type;

    if(type == 1){
      int x; cin >> x;
      if(!mp.count(x)) distinctCount++;
      mp[x]++;
    }
    else if(type == 2){
      int x; cin >> x;
      if(mp.count(x)){
        if(mp[x] > 1) mp[x]--;
        else{
          mp.erase(x);
          distinctCount--;
        }
      }
    }
    else if(type == 3){
      cout << distinctCount << endl;
    }
    else{
      int x; cin >> x;
      cout << (mp.count(x) ? "YES\n" : "NO\n");
    }
  }
}

/*

5. Union of Two Arrays

Problem:
Print all unique elements from both arrays.

Approach:
- Insert both arrays into set (auto sorted)

Time: O((n+m) log n)
*/



void unionOfTwoArrays() {
  int n; cin >> n;
  vector<int> A(n);
  for(int &x : A) cin >> x;

  int m; cin >> m;
  vector<int> B(m);
  for(int &x : B) cin >> x;

  set<int> s;
  for(int x : A) s.insert(x);
  for(int x : B) s.insert(x);

  cout << s.size() << endl;
  for(int x : s) cout << x << " ";
  cout << endl;
}

/*

6. Intersection (Unique)

Problem:
Find common elements (no duplicates)

Approach:
- Store A in set
- Check B
*/


void intersectionOfTwoArrays(){
  int n; cin >> n;
  vector<int> A(n);
  for(int &x : A) cin >> x;

  int m; cin >> m;
  vector<int> B(m);
  for(int &x : B) cin >> x;

  set<int> lookup(A.begin(), A.end());
  set<int> result;

  for(int x : B){
    if(lookup.count(x)) result.insert(x);
  }

  cout << result.size() << endl;
  for(int x : result) cout << x << " ";
  cout << endl;
}

/*

7. Intersection II (With duplicates)

Problem:
Include duplicates → min(freqA, freqB)

Approach:
- Count freq of A
- Traverse B and reduce
*/



void intersectionOfTwoArraysII() {
  int n; cin >> n;
  vector<int> A(n);
  for(int &x : A) cin >> x;

  int m; cin >> m;
  vector<int> B(m);
  for(int &x : B) cin >> x;

  unordered_map<int,int> freq;
  for(int x : A) freq[x]++;

  vector<int> res;

  for(int x : B){
    if(freq[x] > 0){
      res.push_back(x);
      freq[x]--;
    }
  }

  sort(res.begin(), res.end());

  cout << res.size() << endl;
  for(int x : res) cout << x << " ";
  cout << endl;
}

/*

8. Two Sum I (Existence)

Check if pair exists

Approach:
- Use set
*/



bool twoSumI() {
  int n, target;
  cin >> n >> target;

  vector<int> arr(n);
  for(int &x : arr) cin >> x;

  set<int> s;

  for(int x : arr){
    if(s.count(target - x)) return true;
    s.insert(x);
  }
  return false;
}

/*

9. Two Sum (Indices)

Return indices of pair
*/



void twoSumIndices() {
  int n, target;
  cin >> n >> target;

  vector<int> arr(n);
  for(int &x : arr) cin >> x;

  unordered_map<int,int> mp;

  for(int i=0;i<n;i++){
    int req = target - arr[i];
    if(mp.count(req)){
      cout << mp[req]+1 << " " << i+1 << endl;
      return;
    }
    mp[arr[i]] = i;
  }
  cout << -1 << endl;
}

/*

10. Two Sum III (Count pairs)

Count number of pairs

Important: use long long
*/



void twoSumIII(){
  int n, target;
  cin >> n >> target;

  vector<int> arr(n);
  for(int &x : arr) cin >> x;

  unordered_map<int,int> mp;
  long long count = 0;

  for(int x : arr){
    count += mp[target - x];
    mp[x]++;
  }

  cout << count << endl;
}

/*

11. Subarray Sum = X (Exists)

Use prefix sum + set
*/



void subArraySumEqualsX(){
  int n,x;
  cin >> n >> x;

  vector<int> arr(n);
  for(int &v:arr) cin>>v;

  set<int> st;
  st.insert(0);

  int prefix=0;

  for(int xVal:arr){
    prefix+=xVal;

    if(st.count(prefix-x)){
      cout<<"YES\n";
      return;
    }
    st.insert(prefix);
  }
  cout<<"NO\n";
}

/*

12. Subarray Sum = X (Indices)

Use map: prefix → index
*/



void findSubarrayWithSumX(){
  int n;
  long long x;
  cin>>n>>x;

  vector<long long> arr(n);
  for(auto &v:arr) cin>>v;

  unordered_map<long long,int> mp;
  mp[0]=0;

  long long prefix=0;

  for(int i=0;i<n;i++){
    prefix+=arr[i];

    if(mp.count(prefix-x)){
      cout<<mp[prefix-x]+1<<" "<<i+1<<endl;
      return;
    }

    if(!mp.count(prefix))
      mp[prefix]=i+1;
  }

  cout<<-1<<endl;
}

/*
13. Count Subarrays with Sum X

Core idea:
count += freq[prefix - x]
*/



void countSubarraysSumX() {
  int n;
  long long x;
  cin >> n >> x;

  vector<long long> arr(n);
  for (auto &v : arr) cin >> v;

  unordered_map<long long,long long> freq;
  freq[0]=1;

  long long prefix=0, count=0;

  for(auto v:arr){
    prefix+=v;
    count+=freq[prefix-x];
    freq[prefix]++;
  }

  cout<<count<<endl;
}

int main() {
  // countDistinct();
  // searchQueriesIII(); 
  // countDistinctQueries(); 
  // countDistinctQueriesII(); 
  // unionOfTwoArrays(); 
  // intersectionOfTwoArrays(); 
  // intersectionOfTwoArraysII(); 
  // twoSumI(); 
  // twoSumIAnswer(); 
  // twoSumIndices() 
  // twoSumIII(); 
  // subArraySumEqualsX(); 
  // findSubarrayWithSumX();
  countSubarraysSumX();
  return 0;
}