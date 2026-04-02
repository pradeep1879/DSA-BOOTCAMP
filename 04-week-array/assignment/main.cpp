#include <iostream>
using namespace std;

int reverseArray(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    
    for(int i=n-1; i>=0; i--){
        cout << arr[i] << " ";
    }
    return 0;
}

int sumOfArray(){
    int n; 
    cin >> n;
    int arr[n];
    long long sum = 0;

    for(int i=0; i<n; i++){
        cin>> arr[i];
    }

    for(int i=0; i<n; i++){
         sum += arr[i]; 
    }
    cout << sum << endl;
    return 0;

}


int minimumElementAndItsPosition() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = arr[0];
    int location = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] < ans) {
            ans = arr[i];
            location = i + 1; // 1-based index
        }
    }

    cout << ans << " " << location << endl;
    return 0;
}


int maximumElementAndItsPosition() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = arr[0];
    int location = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > ans) {
            ans = arr[i];
            location = i + 1; // 1-based index
        }
    }

    cout << ans << " " << location << endl;
    return 0;
}

void searchElementInArray(){
    int n, x;
    cin >> n >> x;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bool flag = false;
    for(int i=0; i<n; i++){
        if(arr[i] == x){
            flag = true;
        }
    }

    if(flag){
        cout << "YES";
    }else{
        cout << "NO";
    }
    
}

void countOccurrences(){
    int n, x;
    cin >> n >> x;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == x){
            count++;
        }
    }    
    cout << count << endl;
}

void checkIfArrayIsSorted(){
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bool flag = false;

    for(int i=1; i<n; i++){
        if(arr[i]<arr[i-1]){   
            flag = true;
        }
    }
    if(flag){
        cout << "NO";
    }else{
        cout << "YES";
    }

}

// You have been given an integer array of size 𝑁 that contains only integers 0 and 1.
void sort01(){
        int n;
        cin >> n;

        int c0 = 0, c1 = 0;
        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        for(int i = 0; i<n; i++){
            if(arr[i] == 0){
                c0++;
            }else{
                c1++;
            }
        }
        for(int i=0; i<c0; i++){
            cout << "0 ";
        }
        
        for(int i=0; i<c1; i++){
            cout << "1 ";
        }
        
        cout << endl;
    
}



void swapAlternateElement(){ 
        int n;
        cin >> n;
        int arr[n];
        
        for(int i =0; i<n; i++){
            cin >> arr[i];
        }
        
        for(int i=1; i<n; i+=2){
            swap(arr[i], arr[i-1]);
        }
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
       cout << endl; 

}

void reverse(){
    int n;
    cin >> n;
    int arr[n];

    for(int i =0; i<n; i++){
        cin >> arr[i];
    }

    int i=0, j=n-1; 
    while(i<=j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

}

void arrangeTheNumbers(){  
        int n;
        cin >> n;
        int arr[n];

        int i=0, j=n-1;
        int num = 1;
        while(i<=j){
            if(num % 2 != 0){
                arr[i] = num;
                i++;
            }else{
                arr[j] = num;
                j--;
            }
            num++;
        }
        
        for(int i=0; i<n; i++){
        cout << arr[i] << " ";
        }   
        cout << endl;
}


/**
 * Ques. Missing Number
 * In this array, exactly 𝑚 numbers appear twice, and exactly one number appears only once.
 *  Your task is to find and return that unique number.
 */

void missingNumbers(){
    int n;
    cin >> n;
    int ans;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i<n; i++){
        // test whether a[i] present or not.
        int target = arr[i];
        int count = 0;
        
        for(int j=0; j<n; j++){
            if(arr[j] == target){
                count++;
            }
        }
        if(count == 1){
            ans = arr[i];
        }
    }
    cout << ans << endl;
}

void testCase(){
    int t;
    cin>>t;
    for(int tc=0; tc<t; tc++){
        // sort01();
        // swapAlternateElement();
        // arrangeTheNumbers();
        missingNumbers();
    }
}

int main(){
    // reverseArray();
    // sumOfArray();
    // minimumElementAndItsPosition();
    // maximumElementAndItsPosition();
    // searchElementInArray();
    // countOccurrences();
    // checkIfArrayIsSorted();
    // reverse();
    testCase();
}