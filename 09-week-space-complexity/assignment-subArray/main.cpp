#include <iostream>
#include <vector>
using namespace std;

void printAllSubarrays(){
  int n;
  cin >> n;
  vector<long long> arr(n+1);
  for(int i=1; i<=n; i++){
    cin >> arr[i];
  }
  for(int l=1; l<=n; l++){
    for(int r=l; r<=n; r++){
      for(int i=l; i<=r; i++){
        cout << arr[i] << " ";
      }
      cout << endl;
    }
  }
  cout << endl;
}

void sumOfAllSubarraysSeparately(){
  int n;
  cin >> n;
  vector<long long> arr(n+1);
  for(int i=1; i<=n; i++){
    cin >> arr[i];
  }
  for(int l=1; l<=n; l++){
    for(int r=l; r<=n; r++){
      long long sum = 0;
      for(int i=l; i<=r; i++){
        sum += arr[i];
      }
      cout << sum << endl;
    }
  }

}

void sumOfAllSubarraysSeparatelyHard(){
  int n;
  cin >> n;
  vector<long long> arr(n+1);
  for(int i=1; i<=n; i++){
    cin >> arr[i];
  }

   // step 1: prefix sum
    vector<long long> prefix(n+1, 0);
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }

  for(int l = 1; l <= n; l++){
    long long sum = 0;
    for(int r = l; r <= n; r++){
        sum += arr[r];
        cout << sum << '\n';  // faster than endl
    }
  }

}

void sumOfAllSubarrays(){
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

void sumOfAllSubarraysMedium(){
  int n;
  cin >> n;
  vector<long long> arr(n+1);
  for(int i=1; i<=n; i++){
    cin >> arr[i];
  }

  vector<long long> prefix(n+1, 0);
  for(int i=1; i<=n; i++){
    prefix[i] = prefix[i-1] + arr[i];
  }
  
  long long ans = 0;
  for(int l=1; l<=n; l++){
    for(int r=l; r<=n; r++){
      long long sum = prefix[r] - prefix[l-1];
      ans += sum;
    }
  }
  cout << ans << endl;
}

void sumOfAllSubarraysHard(){
  int n;
  cin >> n;
  vector<long long> arr(n+1);
  for(int i=1; i<=n; i++){
    cin >> arr[i];
  }

  long long ans = 0;
  for(int i=1; i<=n; i++){
    ans += arr[i] * i * (n - i + 1);
  }
  cout << ans << endl;
}

void maximumSubarraySumOfSizeK(){
  int n, k;
  cin >> n >> k;

  vector<long long> arr(n);
  for(int i = 0; i < n; i++){
      cin >> arr[i];
  }

  //  first window
  long long windowSum = 0;
  for(int i = 0; i < k; i++){
      windowSum += arr[i];
  }

  long long maxSum = windowSum;

  //  slide window
  for(int i = k; i < n; i++){
      windowSum = windowSum - arr[i - k] + arr[i];
      maxSum = max(maxSum, windowSum);
  }

  cout << maxSum << endl;
}

int main(){
  // printAllSubarrays();
  // sumOfAllSubarraysSeparately();
  // sumOfAllSubarraysSeparatelyHard();
  // sumOfAllSubarrays();
  // sumOfAllSubarraysMedium();
  // sumOfAllSubarraysHard();
  maximumSubarraySumOfSizeK();
}