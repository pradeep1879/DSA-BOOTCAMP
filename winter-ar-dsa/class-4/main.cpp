#include <iostream>
#include <vector>

using namespace std;

void arrayManipulation() {
    int n, q;
    cin >> n >> q;

    vector<long long> arr(n + 1, 0);

    while (q--) {
      int a, b;
      long long k;
      cin >> a >> b >> k;

      arr[a - 1] += k;
      arr[b] -= k;
    }

    vector<long long> prefix(n);
    prefix[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    long long mx = prefix[0];
    for (int i = 0; i < n; i++) {
      if(prefix[i] > mx){
        mx = prefix[i];
      }
    }
    cout << mx;
}

int main() {
    arrayManipulation();
}
