#include <iostream>
#include <vector>
using namespace std;

long long mergeSort(vector<long long>& a, int l, int r) {
  if (l >= r) return 0;

  int mid = l + (r - l) / 2;

  long long inv = 0;
  inv += mergeSort(a, l, mid);
  inv += mergeSort(a, mid + 1, r);

  vector<long long> temp;
  int i = l, j = mid + 1;

  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) {
       temp.push_back(a[i++]);
    } else {
        inv += (mid - i + 1);
      temp.push_back(a[j++]);
    }
  }

  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);

  for (int k = 0; k < temp.size(); k++) {
      a[l + k] = temp[k];
  }

  return inv;
}

int main() {
  int n;
  cin >> n;

  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
      cin >> a[i];
  }

  cout << mergeSort(a, 0, n - 1) << '\n';

  return 0;
}