#include <iostream>
using namespace std;

void helloFunciton(int n){
    for(int i=0; i<n; i++){
        cout << "I am learning functions" << endl;
    }
}

void printFactorsI(int n){
    for(int i=n; i>=1; i--){
        if(n % i == 0){
            cout << i << " ";
        }
    }
}

bool checkPrime(int n){
    int count = 0;
    for(int i=n; i>=1; i--){
        if(n % i == 0){
            count++;
        }
    }
    
    return (count == 2);
}

long long factorial(int n){
    long long fact = 1;
    for(int i=1; i<=n; i++){
        fact *= i;
    }
    // cout << fact;
    return fact;
}

void ncr(){
    int n,r;
    cin >> n >> r;
    long long nfact = factorial(n);
    long long rfact = factorial(r);
    long long nrfact = factorial(n-r);

    cout << nfact/(rfact*nrfact);

}

void printPrimeNumber(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        if(checkPrime(i)){
            cout << i << " ";
        }
    }

}

int HCF(int a, int b){
    int hcf = 1;
    for(int i=1; i<=min(a, b); i++){
        if((a % i == 0  && b % i == 0)){
            hcf =  i;
        }
    }
    return hcf;
}

void findHCF(){
    int a, b;
    cin >> a >> b;
    int hcf = HCF(a, b);
    cout << hcf;
}

int main(){
    // int n; 
    // cin >> n;

    // if (n < 0 || n > 20) return 0;

    // helloFunciton(n);
    // printFactorsI(n);
    // bool ans = checkPrime(n);
    // if(ans){
    //     cout << "Prime";
    // }else{
    //     cout << "Not Prime";
    // }
    // factorial(n);
    // ncr();

    // printPrimeNumber();
    findHCF();
}