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

  int main(){
    // powersOf2();
    // breakDownN();
    // decimalToBinary();
    // binaryToDecimal();
    // bitWiseOperatorI();
    // bitWiseOperatorII();
    bitWiseQueries();
  }