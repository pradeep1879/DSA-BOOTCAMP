#include <iostream>
using namespace std;

// int main(){
//     long long n;
//     cin >> n;
//     for(int i=0; i<n; i++){
//         // loop for spaces : n-i-1
//         for(int j=0; j<n-i-1; j++){
//             cout <<  " ";
//         }
//         // loop for number1: i+1
//         for(int j=1; j<=i+1; j++){
//             cout << "*";   // " "
//         }
//         // loop for number2: 
//         for(int j=i; j>0; j--){
//             cout << "*";
//         }
//         cout << endl;
//     }
//     return 0;
// }


/// inverted pyramid + spaces before;

int invPyWithInitialSpace(){
    int n = 4;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            cout << " ";
        }
        for(int j = 0; j<n-i; j++){
            cout << (i+1);
        }
        cout <<endl;
    }
    return 0;
}
/*output*/
/**
1111
 222
  33
   4
 */
// Pyramid pattern

int pyramimdPattern(){
    int n = 4;
    for(int i=0; i<n; i++){
        for(int j=0; j<(n-i-1); j++){ // spaces (n-i-1)
            cout << " ";
        }
        for(int j=1; j<=i+1; j++){ // num1 (i+1)
            cout << j;
        }
        for(int j=i; j>=1; j--){ // num2 
            cout << j;
        }
        cout << endl;
    }
}
/* output */
/**
 *          1
           121
          12321
         1234321
 *  
 */


void hollowDiamondPattern(){
    int n;
    cin >> n;
    // top
    for(int i =0; i<n; i++){
        // spaces
        for(int j=0; j<n-i-1; j++){
            cout << " ";
        }
         cout << "*";
        if(i !=0){
            for(int j=0; j<(2*i-1); j++){
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }

    // bottom
    for(int i=0; i<n-1; i++){
        //spaces
        for(int j=0; j<i+1; j++){
            cout << " ";
        }
        cout << "*";

        if(i != n-2){
            //spaces
            for(int j=0; j<2*(n-i)-5; j++){
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
 }

 /* out put */
 /**

   *
  * *
 *   *
*     *
 *   *
  * *
   *

  */


void triangleWithStars(){
    long long n;
    cin >> n;
     for(int i = 1; i <= n; i++) {

        // print leading spaces
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // print stars
        for(int j = 1; j <= i; j++) {
            cout << "*";
            if(j < i) cout << " ";
        }

        cout << endl;
    }
}
/*output*/
/**
    *
   * *
  * * *
 * * * *
* * * * *
 */


void hollowTriangleWithStars() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {

        // leading spaces
        for(int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        // first row
        if(i == 0) {
            cout << "* ";
        }
        // last row (solid with spaces)
        else if(i == n - 1) {
            for(int j = 0; j < n; j++) {
                cout << "* ";
            }
        }
        // middle rows (hollow)
        else {
            cout << "*";
            for(int j = 0; j < 2*i - 1; j++) {
                cout << " ";
            }
            cout << "* ";
        }

        cout << endl;
    }
}

void invertedHollowTriangleWithStars() {
    int n;
    cin >> n;

    for(int i = n; i > 0; i--) {
       // leading spaces
        for(int j = 0; j < n-i; j++) {
            cout << " ";
        }

        // top row (solid)
        if(i == n){
            for (int j = 0; j<n; j++){
                cout << "* ";
            }
        }else if(i==1){
            cout << "*"; // last row
        }else {
            cout << "*";
            for (int j=0; j<2*i-3; j++){
                 cout << " ";
            }
            cout << "*";
        }

        cout << endl;
    }
}


void verticalTriangle(){
    long long n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << " *";
        }
        cout << endl;
    }
    for(int i=n-1; i>0; i--){
        for(int j=1; j<=i; j++){
            cout << " *";
        } 
        cout << endl;       
    }
}
/* out put */
/**
 * 
 * *
 * * *
 * * * *
 * * * * *
 * * * * * *
 * * * * * * *
 * * * * * *
 * * * * *
 * * * *
 * * *
 * *
 *
 */


void hollowVerticaTriangel(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cout << "*";
        if(i !=0 ){
            for(int j=0; j<2*i-1; j++){
                cout << " ";
            }
            cout << "*";
        }   
        cout << endl;
    }

    for(int i=n-2; i>=0; i--){
        cout << "*";
        if(i !=0 ){
            for(int j=0; j<2*i-1; j++){
                cout << " ";
            }
            cout << "*";
        }   
        cout << endl;
    }
    
 }
/*output*/
/**
*    
* *
*   *
*     *
*       *
*     *
*   *
* *
*
 */






void hollowSquare(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == 0 or i == n-1 or j == 0 or j == n-1){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
 }
/*output*/
/**
*****
*   *
*   *
*   *
*****
 */


void hollowRectangle(){
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == 0 or i == n-1 or j == 0 or j == m-1){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
 }
/*output*/
/**
********
*      *
*      *
*      *
********
 */




void diamond(){
    long long n;
    cin >>n ;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            cout << " ";
        }
        for(int j=0; j<=i; j++){
            cout << " *";
        }
        cout << endl;
    }

    for(int i=n-2; i>=0; i--){
        for(int j=0; j<n-i-1; j++){
            cout << " ";
        }
        for (int j=0; j<=i; j++){
            cout << " *";
        }
        cout << endl;
    }
}
/* output */

/**
 
     * 
    * *
   * * *
  * * * *
 * * * * *
  * * * *
   * * *
    * *
     *
     
 */

void crownPatter(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << "*";
        }
        for(int j=0; j<2*(n-i-1); j++){
            cout << " ";
        }
        for(int j=0; j<=i; j++){
            cout << "*";
        }
        cout << endl;
    }
}

/*output*/
/**
*            *
**          **
***        ***
****      ****
*****    *****
******  ******
**************
 */


void butterflyPatter(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << "*";
        }
        for(int j=0; j<2*(n-i-1); j++){
            cout << " ";
        }
        for(int j=0; j<=i; j++){
            cout << "*";
        }
        cout << endl;
    }

    for(int i=n-2; i>=0; i--){
        for(int j=0; j<=i; j++){
            cout << "*";
        }

        for(int j=0; j<2*(n-i-1); j++){
            cout << " ";
        }
        for(int j=0; j<=i; j++){
            cout << "*";
        }
        cout << endl;
    }
}

/*output*/
/**
 
*            *
**          **
***        ***
****      ****
*****    *****
******  ******
**************
******  ******
*****    *****
****      ****
***        ***
**          **
*            *

 */


 void invertedDiamond(){
    int n;
    cin >> n;

    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=i; j++){
            cout << "*";
        }

        for(int j=0; j<2*(n-i); j++){
            cout << " ";
        }
        for(int j=0; j<=i; j++){
            cout << "*";
        }
        cout << endl;
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << "*";
        }
        for(int j=0; j<2*(n-i); j++){
            cout << " ";
        }
        for(int j=0; j<=i; j++){
            cout << "*";
        }
        cout << endl;
    }
 }

 /*output*/
 /**
*****  *****
****    ****
***      ***
**        **
*          *
**        **
***      ***
****    ****
*****  *****
  */






int main(){
    // invPyWithInitialSpace();
    // hollowDiamondPattern();
    // pyramimdPattern();
    // triangleWithStars();
    // hollowTriangleWithStars();
    // hollowSquare();
    // hollowRectangle();
    // invertedHollowTriangleWithStars();
    // verticalTriangle();
    // hollowVerticaTriangel();
    // diamond();
    // crownPatter();
    // butterflyPatter();
    // invertedDiamond();


}
