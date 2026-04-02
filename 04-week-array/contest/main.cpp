#include <iostream>
using namespace std;


void resultDay(){
    int n;
    cin >> n;
    int arr[n];
    
    for(int i =0; i<n; i++){
        cin >> arr[i];
    }
    int p;
    cin >> p;
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] >= p){
            count++;
        }
    }
    cout << "Pass: " << count << endl;
    cout << "Fail: " << (n - count) << endl;
    
    
    
}

void fastestRunner(){
    int n;
    cin >> n;
    int arr[n];
    
    for(int i =0; i<n; i++){
        cin >> arr[i];
    }
    int ans = arr[0];
    int location = 1;
    for(int i=0; i<n; i++){
        if(arr[i] <= ans){
            ans = arr[i];
            location = i + 1;
        }
    }    
    cout << location << endl;
}

void sort(){
    int n;
    cin >> n;
    int arr[n];
    
    for(int i =0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] < arr[j]){
                int temp = arr[j];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
}


void compareFactorials(){
    long long a, b;
    cin >> a >> b;
    
    long long factA = 1;
    for(int i=1; i<=a; i++){
        factA *= i;
    }
    long long factB = 1;
    for(int i=1; i<=b; i++){
        factB *= i;
    }
    
    if(factA == factB){
        cout << "Yes";
    }else{
        cout << "No";
    }
}


void beautifulArray(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    bool beautiful = true;

    for(int i = 1; i < n; i++){
        if(arr[i] != arr[0]){
            beautiful = false;
            break;
        }
    }

    if(beautiful){
        cout << "Yes";
    } else {
        cout << "No";
    }
}

// void specialFactors(){
//     int a;
//     cin >> a;
//     for(int i=1; i<=a; i++){
//         int f1 = i;
//         int f2 = a/i;

//         if(a % i == 0){
//             if((f1 % 2 == 2) || ( f2 % 10 = 7)){

//             }
//         }
//     }
// }

void uniqueElement(){
    int N;
    cin >> N;

    int arr[N];
    unordered_map<int, int> freq;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    bool printed = false;

    for (int i = 0; i < N; i++) {
        if (freq[arr[i]] == 1) {
            cout << arr[i] << " ";
            printed = true;
        }
    }

    // if nothing printed, output empty line (just newline)
    if (!printed) {
        cout << "";
    }
}




int main(){
    // resultDay();
    // fastestRunner();
    // compareFactorials();
    // beautifulArray();
    // specialFactors();
    uniqueElement();
}