  #include <iostream>
  using namespace std;

  void powersOf2(){
    long long n;
    cin >> n;
    
    long long curr = 1;
    while (curr <= n){
      cout << curr << " ";
      curr *= 2;
    }
  }

  void breakDownN(){
    long long n;
    cin >> n;

    long long curr = 1;
    while (curr <= n){
      curr *= 2;
    }

    curr /= 2;

    while(n > 0){
      if(curr <= n){
        cout << curr << " ";
        n -= curr;
      }
      curr /= 2;
    }

  }


  void decimalToBinary(){
    long long n;
    cin >> n;

    if(n == 0) {
      cout << 0;
      return;
    }

    long long curr = 1;
    while (curr <= n){
      curr *= 2;
    }

    curr /= 2;

    while(curr > 0){
      if(curr <= n){
        cout << 1;  
        n -= curr;
      }else{
        cout << 0;
      }
      curr /= 2;
    }
  }


  void binaryToDecimal(){
    string s;
    cin >> s;

    long long ans = 0;
    for(int i = 0; i < s.size(); i++){
      ans = ans * 2 + (s[i] - '0');
    }
    cout << ans;
  }

  void bitWiseOperatorI(){
    long long a, b;
    cin >> a >> b;

    cout << (a & b) << " " << (a | b) << " " << (a ^ b);
  }


  void bitWiseOperatorII(){
    long long n;
    cin >> n;

    long long arr[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }

    long long AND = arr[0];
    long long OR = arr[0];
    long long XOR = arr[0];

    for(int i = 1; i < n; i++){
      AND &= arr[i];
      OR |= arr[i];
      XOR ^= arr[i];
    }
    cout << AND << " "  << OR << " " << XOR;
  }

  void bitWiseQueries(){
    long long n , q;
    cin >> n >> q;

    while(q--){
      int t, i;
      cin >> t >> i;

      long long mask = (1LL << i);
      // check ith bit
      if(t == 1){
        if((n & mask) == 0){
          cout << "NO" << "\n";
        }else{
          cout << "YES" << "\n";
        }
      }
      // set ith bit
      else if(t == 2){
          n = (mask | n);
          cout << n << "\n";
        }
        // unset ith bit
      else if(t == 3){
          n = (n & (~mask));
          cout << n << "\n";
        }
        // toggle ith bit
      else if(t == 4){
          n = (n ^ mask);
          cout << n << "\n";
        }
    }
  }

 

  // void checkPowerOf2(){
  //   long long n;
  //   cin >> n;

  //   long  long count = 0;
  //   for(int i = 31; i >= 0; i--){
  //     if(checkIthBit(n, i)){
  //       count++;
  //     }
  //   }
  //   if(count == 1){
  //     cout << "YES\n";
  //   }else{
  //     cout << "NO\n";
  //   }
  // }

  void checkPowerOf2(){
    long long n;
    cin >> n;
    if(n > 0 && (n & (n - 1)) == 0){
      cout << "YES\n";
    }else{
      cout << "NO\n";
    }
  }

  void oddEvenWithoutModulo(){
    long long n;
    cin >> n;

    if((n & 1) == 0){
      cout << "Even\n";
    }else{
      cout << "Odd\n";
    }
  }

   bool checkIthBit(long long n, int i){
    long long mask = 1LL << i;
    return (n & mask) != 0;
  }


  // void countSetBit(){
  //   int n;
  //   cin >> n;

  //   int count = 0;
  //   for(int i = 31; i >= 0; i--){
  //     if(checkIthBit(n, i)){
  //       count++;
  //     }
  //   }

  //   cout << count << endl;

  // }

  void countSetBit(){
    long long n;
    cin >> n;

    long long count = 0;
    while(n != 0){
      count++;
      n = n & (n-1); // remove right most set bit
    }
    cout << count << endl;
  }


  void singleNumberI(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }

    int ans = 0;
    for(int x: arr){
      ans ^= x;
    }
    cout << ans << "\n";
  }


  void singleNumberII(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }

    int ans = 0;
    for(int j = 0; j < 31; j++){
      int sum  = 0;
      for(int i = 0; i < n; i++){
        if(checkIthBit(arr[i], j)){
          sum++;
        }
      }
      
      if(sum % 3 != 0){
        ans = ans | (1LL << j);
      }
    }

    cout << ans << "\n";

  }

  void singleNumberIII(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }

    // XOR for the entire array
    int xor_arr = 0;
    for(int x: arr){
      xor_arr ^= x;
    }

    // figure out any position in which they both differe
    // => position of any setbit in xor_arr

    int pos = -1;
    for(int i = 0; i < 32; i++){
      if(checkIthBit(xor_arr, i)){
        pos = i;
        break;
      }
    }

    // xor of groups seperately

    int group1 = 0;
    int group2 = 0;

    for(int x: arr){
      if(checkIthBit(x, pos)){
        group1 ^= x;
      }else{
        group2 ^= x;
      }
    }
    
    if(group1 < group2){
      cout << group1 << " " << group2 << "\n";
    }else{
      cout << group2 << " " << group1 << "\n";
    }

  }


  void printAllSubsets(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }

    // no of subsets equal to 2^n;
    for(int mask = 1; mask < (1 << n); mask++){
      for(int i = 0; i < n; i++){
        if(mask & (1 << i)){
          cout << arr[i] << " ";
        }
      }
      cout << "\n";
    }
  }


  int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // powersOf2();
    // breakDownN();
    // decimalToBinary();
    // binaryToDecimal();
    // bitWiseOperatorI();
    // bitWiseOperatorII();
    // bitWiseQueries();
    // checkPowerOf2();
    // oddEvenWithoutModulo();
    // countSetBit();
    // singleNumberI();
    // singleNumberII();
    // singleNumberIII();
    printAllSubsets();
  }