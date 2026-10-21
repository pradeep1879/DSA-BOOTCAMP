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



int main(){
  // printAllSubArray();
  // sumOfSubArraySeperately();
  // sumOfAllSubArraysSeperatelyHard();
  // sumOfAllSubarraysEasy();
  // sumOfAllSubarraysHard();
  maximumOfAllSubarrays();
  // sumOfAllSubArraysMedium();
}