#include <iostream>
using namespace std;

/*
============================================================================
TOPIC: FUNCTIONS IN C++
============================================================================

This program contains multiple basic mathematical functions:

1. Print message multiple times
2. Print factors of a number
3. Check Prime Number
4. Calculate Factorial
5. Calculate nCr
6. Print Prime Numbers till N
7. Find HCF (Highest Common Factor)

Each function contains:
- Problem Statement
- Approach
- Time Complexity
- Explanation
============================================================================
*/


/*
============================================================================
1. PRINT MESSAGE N TIMES
============================================================================

PROBLEM:
Print "I am learning functions" n times.

APPROACH:
- Run a loop from 0 to n-1
- Print the message in every iteration

TIME COMPLEXITY:
O(n)

============================================================================
*/
void helloFunciton(int n){

    for(int i = 0; i < n; i++){
        cout << "I am learning functions" << endl;
    }
}



/*
============================================================================
2. PRINT FACTORS OF A NUMBER
============================================================================

PROBLEM:
Print all factors of a number.

Example:
Input  : 12
Output : 12 6 4 3 2 1

FACT:
A factor is a number that divides another number completely.

APPROACH:
- Loop from n to 1
- If n % i == 0
  then i is a factor

TIME COMPLEXITY:
O(n)

============================================================================
*/
void printFactorsI(int n){

    for(int i = n; i >= 1; i--){

        if(n % i == 0){
            cout << i << " ";
        }
    }
}



/*
============================================================================
3. CHECK PRIME NUMBER
============================================================================

PROBLEM:
Check whether a number is prime or not.

PRIME NUMBER:
A number having exactly 2 factors:
1 and itself

Example:
2, 3, 5, 7 are prime

APPROACH:
- Count total factors
- If total factors == 2
  then number is prime

SPECIAL CASE:
0 and 1 are NOT prime

TIME COMPLEXITY:
O(n)

============================================================================
*/
bool checkPrime(int n){

    // 0 and 1 are not prime
    if(n <= 1){
        return false;
    }

    int count = 0;

    // Count factors
    for(int i = 1; i <= n; i++){

        if(n % i == 0){
            count++;
        }
    }

    // Prime numbers have exactly 2 factors
    return (count == 2);
}



/*
============================================================================
4. FACTORIAL OF A NUMBER
============================================================================

PROBLEM:
Find factorial of a number.

FORMULA:
5! = 5 × 4 × 3 × 2 × 1
   = 120

APPROACH:
- Start factorial from 1
- Multiply every number from 1 to n

TIME COMPLEXITY:
O(n)

============================================================================
*/
long long factorial(int n){

    long long fact = 1;

    for(int i = 1; i <= n; i++){
        fact *= i;
    }

    return fact;
}



/*
============================================================================
5. CALCULATE NCR
============================================================================

PROBLEM:
Find nCr (Combination)

FORMULA:
nCr = n! / (r! × (n-r)!)

Example:
5C2 = 10

APPROACH:
- Calculate:
    n!
    r!
    (n-r)!
- Apply formula

TIME COMPLEXITY:
O(n)

============================================================================
*/
void ncr(){

    int n, r;
    cin >> n >> r;

    long long nfact = factorial(n);
    long long rfact = factorial(r);
    long long nrfact = factorial(n-r);

    cout << nfact / (rfact * nrfact);
}



/*
============================================================================
6. PRINT PRIME NUMBERS TILL N
============================================================================

PROBLEM:
Print all prime numbers from 1 to n.

Example:
Input  : 10
Output : 2 3 5 7

APPROACH:
- Loop from 1 to n
- For every number:
    call checkPrime()
- If prime:
    print it

TIME COMPLEXITY:
O(n²)
Because for every number we check prime again

============================================================================
*/
void printPrimeNumber(){

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){

        if(checkPrime(i)){
            cout << i << " ";
        }
    }
}



/*
============================================================================
7. FIND HCF (HIGHEST COMMON FACTOR)
============================================================================

PROBLEM:
Find HCF of two numbers.

HCF:
Largest number that divides both numbers completely.

Example:
Input  : 12 18
Output : 6

COMMON FACTORS:
12 -> 1 2 3 4 6 12
18 -> 1 2 3 6 9 18

Largest common factor = 6

APPROACH:
- Loop from 1 to minimum(a, b)
- If i divides both numbers
    store it in hcf
- Final stored value will be largest common factor

TIME COMPLEXITY:
O(min(a,b))

============================================================================
*/
int HCF(int a, int b){

    int hcf = 1;

    for(int i = 1; i <= min(a, b); i++){

        // Check common factor
        if(a % i == 0 && b % i == 0){
            hcf = i;
        }
    }

    return hcf;
}



/*
============================================================================
8. DRIVER FUNCTION FOR HCF
============================================================================

PURPOSE:
- Take input
- Call HCF function
- Print answer

============================================================================
*/
void findHCF(){

    int a, b;
    cin >> a >> b;

    int hcf = HCF(a, b);

    cout << hcf;
}



/*
============================================================================
MAIN FUNCTION
============================================================================

Program execution starts from here.

Uncomment any function call to test it.

============================================================================
*/
int main(){

    // int n;
    // cin >> n;

    /*
    ------------------------------------------------------------------------
    1. Print message n times
    ------------------------------------------------------------------------
    */
    // helloFunciton(n);



    /*
    ------------------------------------------------------------------------
    2. Print factors
    ------------------------------------------------------------------------
    */
    // printFactorsI(n);



    /*
    ------------------------------------------------------------------------
    3. Check Prime
    ------------------------------------------------------------------------
    */
    // bool ans = checkPrime(n);

    // if(ans){
    //     cout << "Prime";
    // }
    // else{
    //     cout << "Not Prime";
    // }



    /*
    ------------------------------------------------------------------------
    4. Find Factorial
    ------------------------------------------------------------------------
    */
    // cout << factorial(n);



    /*
    ------------------------------------------------------------------------
    5. Calculate nCr
    ------------------------------------------------------------------------
    */
    // ncr();



    /*
    ------------------------------------------------------------------------
    6. Print Prime Numbers till N
    ------------------------------------------------------------------------
    */
    // printPrimeNumber();



    /*
    ------------------------------------------------------------------------
    7. Find HCF
    ------------------------------------------------------------------------
    */
    findHCF();
}