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



void binarySearchString() {
    int n;
    cin >> n;

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string target;
    cin >> target;

    // binary search requires sorted data
    sort(arr.begin(), arr.end());

    int l = 0;
    int r = n - 1;
    bool ans = false;

    while (l <= r) {
      int mid = l + (r - l) / 2;

      if(arr[mid] == target) {
        ans = true;
        break;
      }
      else if (arr[mid] < target) {
          l = mid + 1;
      }
      else {
          r = mid - 1;
      }
    }

    cout << (ans ? "YES" : "NO") << "\n";
}



int main(){
  // searchQueries();
  // searchQueriesII();
  // firstAndLastOccurance();
  // frequencyOfElement();
  binarySearchString();
}