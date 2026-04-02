#include <iostream>
using namespace std;


int factorial(int n){
    int ans = 1;
    for(int i=1; i<=n; i++){
        ans *= i;
    }
    return ans;
}

void binomiaCoffecient(){
    int n, r;
    cin >> n >> r;

    int nFact = factorial(n);
    int rFact = factorial(r);
    int nrFact = factorial(n-r);


    cout << nFact/(rFact*nrFact) << endl;

    
}

bool primeOrNot(int n){

    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(n % i == 0){
            cnt++;
            // cout << i << " " << endl;
        }
    }

    // if(cnt == 2){
    //     return true;
    // }else{
    //     return false;
    // }
    return (cnt == 2);
}

int main(){
    int n;
    cin >> n;
    // binomiaCoffecient();
    bool ans =  primeOrNot(n);
    if(ans){
        cout << "Prime" << endl;
    }else{
        cout << "NotPrime" << endl;
    }

    // print all prime from 1 to n.
    for(int i=1; i<=n; i++){
        if(primeOrNot(i)){
            cout << i << " ";
        }
    }

}
