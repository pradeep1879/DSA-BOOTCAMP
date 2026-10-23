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

void arrayManipulationII() {
    int n, q;
    cin >> n >> q;

    vector<long long> arr(n + 1, 0);
    for(int i = 1; i <= n; i++){
      cin >> arr[i];
    }

    vector<long long> diffArr(n+2, 0);
    while (q--) {
      int a, b;
      long long k;
      cin >> a >> b >> k;

      diffArr[a] += k;
      diffArr[b+1] -= k;
    }

    long long current = 0;
    long long mx = 0;

    for (int i = 1; i <= n; i++) {
        current += diffArr[i];
        arr[i] += current;

        if (i == 1 || arr[i] > mx) {
            mx = arr[i];
        }
    }
    cout << mx;
}


void toggleBinaryArray() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> diffArr(n + 2, 0);

    while (q--) {
      int a, b;
      cin >> a >> b;

      diffArr[a] += 1;
      diffArr[b + 1] -= 1;
    }

    int current = 0;

    for (int i = 1; i <= n; i++) {
        current += diffArr[i];

        // toggle only when the number of toggles is odd
        if (current % 2 == 1) {
            arr[i] ^= 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}
int main() {
    // arrayManipulation();
    // arrayManipulationII();
    toggleBinaryArray();
}
