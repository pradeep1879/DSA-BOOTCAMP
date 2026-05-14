#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

void searchQueries()
{
  int n, q;
  cin >> n >> q;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  for (int i = 0; i < q; i++)
  {
    int x;
    cin >> x;

    int l = 0;
    int r = n - 1;
    int ans = -1;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (arr[mid] == x)
      {
        ans = mid;
        break;
      }
      else if (arr[mid] < x)
      {
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }
    }
    if (ans == -1)
    {
      cout << ans << endl;
    }
    else
    {
      cout << ans + 1 << endl;
    }
  }
}

void searchQueriesII()
{
  int n, q;
  cin >> n >> q;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  for (int i = 0; i < q; i++)
  {
    int x;
    cin >> x;

    int l = 0;
    int r = n - 1;
    int ans = -1;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (arr[mid] == x)
      {
        ans = mid;
        break;
      }
      else if (arr[mid] < x)
      {
        r = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }
    if (ans == -1)
    {
      cout << ans << endl;
    }
    else
    {
      cout << ans + 1 << endl;
    }
  }
}

void firstAndLastOccurance()
{
  int n, q;
  cin >> n >> q;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  for (int i = 0; i < q; i++)
  {
    int x;
    cin >> x;

    int firstA = -1;
    int lastA = -1;

    // first occurance(search in left)
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (arr[mid] == x)
      {
        firstA = mid;
        r = mid - 1; // move left
      }
      else if (arr[mid] < x)
      {
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }
    }

    // last occurance(search in right)
    l = 0;
    r = n - 1;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (arr[mid] == x)
      {
        lastA = mid;
        l = mid + 1; // move right
      }
      else if (arr[mid] < x)
      {
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }
    }

    if (firstA == -1)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << firstA + 1 << " " << lastA + 1 << endl;
    }
  }
}

// void frequencyOfElement()
// {
//   int n, q;
//   cin >> n >> q;

//   int arr[n];

//   for (int i = 0; i < n; i++)
//   {
//     cin >> arr[i];
//   }

//   while (q--)
//   {

//     int x;
//     cin >> x;

//     int count = 0;

//     for (int i = 0; i < n; i++)
//     {

//       if (arr[i] == x)
//       {
//         count++;
//       }
//     }

//     cout << count << endl;
//   }
// }

void frequencyOfElement(){
  int n,q;
  cin >> n >> q;

  unordered_map<int, int> freq;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    freq[x]++;
  }

  while(q--){
    int x;
    cin >> x;

    cout << freq[x] << endl;
  }
}

void frequencyOfElementGreatThenX(){
  int n, q;
  cin >> n >> q;

  int arr[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);
  while(q--){
    int x;
    cin >> x;

    int l = 0; 
    int r = n - 1;
    int ans = -1;

    while(l <= r){
      int mid = (l+r)/2;
      if(arr[mid] >= x){
        ans = mid;
        r = mid - 1;
      }else{
        l = mid + 1;
      }
    }
    if(ans == -1){
      cout << 0 << endl;
    }else{
      cout << (n - ans) << endl;
    }
  }
}

void frequencyOfElementBTNXandY(){
  int n, q;
  cin >> n >> q;

  int arr[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);
  while(q--){
    int x, y;
    cin >> x >> y;

    int l = 0;
    int r = n - 1;
    int ans1 = -1;
    int ans2 = -1;
    // for first condition
    while(l <= r){
      int mid = (l+r)/2;
      if(arr[mid] >= x){
        ans1 = mid;
        r = mid - 1;
      }else{
        l = mid + 1;
      }
    }
    // for second condition

    l = 0;
    r = n - 1;
    while(l <= r){
      int mid = (l+r)/2;
      if(arr[mid] <= y){
        ans2 = mid;
        l = mid + 1;
      }else{
        r = mid - 1;
      }
    }

    // No valid elements
    if(ans1 == -1 || ans2 == -1 || ans1 > ans2){
      cout << 0 << endl;
    }else{
      cout << ans2 - ans1 + 1 << endl;
    }
    
  }
}

void smallestElementGreaterThenEqualToX(){
  int n, q;
  cin >> n >> q;

  int arr[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  while(q--){
    int x;
    cin >> x;

    int l = 0;
    int r = n - 1;

    int ans = -1;
    while(l <= r){
      int mid = (l+r)/2;
      
      if(arr[mid] >= x){
        ans = arr[mid];
        r = mid - 1;
      }else{
        l = mid + 1;
      }
    }

    cout << ans << endl;
  }
}

void largestElementLessThenEqualToX(){
  int n, q;
  cin >> n >> q;

  int arr[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  while(q--){
    int x;
    cin >> x;

    int l = 0;
    int r = n - 1;

    int ans = -1;
    while(l <= r){
      int mid = (l+r)/2;
      
      if(arr[mid] <= x){
        ans = arr[mid];
        l = mid + 1;
      }else{
        r = mid - 1;
      }
    }

    cout << ans << endl;
  }

}

bool isPossible(int arr[], int n, int gap, int k){
    int cowPlaced = 1;
    int prev = arr[0];

    for(int i = 1; i < n; i++){
      if(arr[i] - prev >= gap){
        cowPlaced++;
        prev = arr[i];
      }
    }

    return cowPlaced >= k;
}

void aggressiveCow(){

    int n, k;
    cin >> n >> k;

    int arr[n];

    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }

    sort(arr, arr + n);

    int l = 1;
    int r = arr[n - 1] - arr[0];

    int ans = -1;

    while(l <= r){
      int mid = (l + r) / 2;

      if(isPossible(arr, n, mid, k)){
          ans = mid;
          l = mid + 1;
        }else{
          r = mid - 1;
        }
    }

    cout << ans << endl;
}


bool isTrue(long long arr[], int n,  long long maxTime, int k){
  int painter = 1;
  long long work = 0;
  for(int i = 0; i < n; i++){

    if(arr[i] > maxTime){
      return false;
    }

    if(work + arr[i] <= maxTime){
      work += arr[i];
    }else{
      painter++;
      work = arr[i];
    }
  }
  return painter <= k;
}

void paintersPartition(){
  int n, k;
    cin >> n >> k;

    long long arr[n];

    long long mx = 0;
    long long sum = 0;
    for(int i = 0; i < n; i++){
      cin >> arr[i];
      mx = max(mx, arr[i]);
      sum += arr[i];
    }


    long long l = mx;
    long long r = sum;
    long long ans = -1;

    while( l<= r){
      long long mid = (l+r)/2;
      if(isTrue(arr, n, mid, k)){
        ans = mid;
        r = mid - 1;
      }else{
        l = mid + 1;
      }
    }

    cout << ans << endl;
 
}

bool isCorrect(long long arr[], int n, int k, long long maxPages){

    int students = 1;

    long long pages = 0;

    for(int i = 0; i < n; i++){

        // One book itself exceeds limit
        if(arr[i] > maxPages){
            return false;
        }

        // Assign to current student
        if(pages + arr[i] <= maxPages){

            pages += arr[i];

        }else{

            // New student needed
            students++;

            pages = arr[i];

            // Too many students
            if(students > k){
                return false;
            }
        }
    }

    return true;
}

void allocateMinimumPages(){

    int n, k;
    cin >> n >> k;

    // Impossible case
    if(k > n){
        cout << -1 << endl;
        return;
    }

    long long arr[n];

    long long mx = 0;
    long long sum = 0;

    for(int i = 0; i < n; i++){

        cin >> arr[i];

        mx = max(mx, arr[i]);

        sum += arr[i];
    }

    long long l = mx;

    long long r = sum;

    long long ans = -1;

    while(l <= r){

        long long mid = l + (r - l) / 2;

        if(isCorrect(arr, n, k, mid)){

            ans = mid;

            // Try smaller answer
            r = mid - 1;

        }else{

            // Need larger limit
            l = mid + 1;
        }
    }

    cout << ans << endl;
}

int main()
{
  // searchQueries();
  // searchQueriesII();
  // firstAndLastOccurance();
  // frequencyOfElement();
  // frequencyOfElementGreatThenX();
  // frequencyOfElementBTNXandY();
  // smallestElementGreaterThenEqualToX();
  // largestElementLessThenEqualToX();
  // aggressiveCow();
  paintersPartition();

}
