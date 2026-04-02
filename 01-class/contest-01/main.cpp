#include <iostream>
using namespace std;


void isVowel(){
    char ch;
    cin >> ch;
    if(ch == 'a' or ch == 'i' or ch == 'o' or ch == 'i' or ch == 'u'){
        cout << "YES";
    }else{
        cout << "NO";
    }
}

void secondLastDigit(){
    long long digit;
    cin >> digit;

    cout << ((digit/10)%10);
    
}

void isLeapYear(){
    long long year;
    cin >> year;
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
        cout << "Yes";
    }else{
        cout << "No";
    }
}

void fizzBuzz(){
    long long number;
    cin >> number;

    for(int i=1; i<=number; i++){
        if(i % 3 == 0 && i % 5 != 0){
            cout << "Fizz";
        }else if(i % 5 == 0 && i % 3 != 0){
            cout << "Buzz";
        }else if(i % 3 == 0 && i % 5 == 0){
            cout << "FizzBuzz";
        }else{
            cout << i;
        }
        cout << endl;
    }
}

void countZeros(){
    long long n;
    cin >> n;
    int count = 0;
    long long rev = 0;
    while(n !=0){
        int digit = n % 10;
        if(digit == 0){
            count++;
        }
        n = n/10;
    }

    cout << count;
}

void countGoodNumber(){
    int n;
    cin >> n;
    long long x;
    int count = 0;
    for(int i=0; i<n; i++){
        cin >> x;
        if((x != 0 && 18 % x == 0) || (x % 45 == 0)){
            count++;
        }
    }
    cout << count;
}

void countZerosIncludingInitial() {
    string s;
    cin >> s;

    int count = 0;
    string rev = "";

    for (char ch : s) {
        if (ch == '0') {
            count++;
        }
    }

    // reverse the string
    // for (int i = s.length() - 1; i >= 0; i--) {
    //     rev += s[i];
    // }

    cout << count;
}

void emptyRectangle(){
    long long n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 or i==n-1 or j == 0 or j == m-1){
                cout << '^';
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
}

void shiftedPyramid(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i+1; j++){
            cout << " ";
        }
        for(int j=0; j<=i; j++){
            cout << "x";
        }
        cout << endl;
    }
}

void hourGlass(){
    long long n;
    cin >> n;

   for(int i = n; i>0; i--){
      // print leading spaces
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // print stars
        for(int j = 1; j <= i; j++) {
            cout << ".";
            if(j < i) cout << " ";
        }

        cout << endl;
    }

    for(int i = 2; i<=n; i++){
      // print leading spaces
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // print stars
        for(int j = 1; j <= i; j++) {
            cout << ".";
            if(j < i) cout << " ";
        }

        cout << endl;
    }

    
}


void arrow() {
    long long n;  // middle height
    cin >> n;
/*solution-1*/

    //upper half
    for (int i = 0; i < n; i++) {
        // leading spaces
        for (int s = 0; s < i; s++)
            cout << " ";

        cout << ">";

        if (i > 0) {
            for (int sp = 0; sp < 2 * i - 1; sp++)
                cout << " ";
            cout << ">";
        }
        cout << endl;
    }

    // lower half
    for (int i = n - 2; i >= 0; i--) {
        for (int s = 0; s < i; s++)
            cout << " ";

        cout << ">";

        if (i > 0) {
            for (int sp = 0; sp < 2 * i - 1; sp++)
                cout << " ";
            cout << ">";
        }
        cout << endl;
    }

    cout << endl;

/*solution-2*/
    for(int i=0; i<n; i++){
        for(int j=0; j<=i-1; j++){
            cout << " ";
        }
        cout << ">";
        if(i !=0 ){
            for(int j=0; j<2*i-1; j++){
                cout << " ";
            }
            cout << ">";
        }   
        cout << endl;
    }

    for(int i=n-2; i>=0; i--){
        for(int j=0; j<=i-1; j++){
            cout << " ";
        }
        cout << ">";
        if(i !=0 ){
            for(int j=0; j<2*i-1; j++){
                cout << " ";
            }
            cout << ">";
        }   
        cout << endl;
    }

}


int main(){
    // isVowel();
    // secondLastDigit();
    // countGoodNumber();
    // isLeapYear();
    // fizzBuzz();
    // countZeros();
    // countZerosIncludingInitial();
    // emptyRectangle();
    // shiftedPyramid();
    // hourGlass();
    arrow();

    
    // long long n;
    // cin >> n;

    // for(int i = 1; i<=n; i++){
    //     cout << "Hello Codeforces " << i << endl;
    // }
    
}


