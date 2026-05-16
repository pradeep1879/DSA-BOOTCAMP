#include <iostream>
#include <vector>
using namespace std;


void boundaryTraversal(){
  int n, m;
  cin >> n >> m;

  vector<vector<int>> arr(n, vector<int>(m));  // use vector instead of array
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> arr[i][j];
    }
  }

   // Special cases
  if (n == 1)
  {
    for (int j = 0; j < m; j++)
      cout << arr[0][j] << " ";
    return;
  }

  if (m == 1)
  {
    for (int i = 0; i < n; i++)
      cout << arr[i][0] << " ";
    return;
  }

  for(int j = 0; j < m; j++){
    cout << arr[0][j] << " ";
  }

  for(int i = 1; i < n; i++){
    cout << arr[i][m-1] << " ";
  }

  for(int j = m - 2; j >=0; j--){
    cout << arr[n-1][j] << " ";
  }

  for(int i = n - 2; i > 0; i--){
    cout << arr[i][0] << " ";
  }
}


/**
 * 1. Matrix Transpose
Problem — Matrix Transpose

You are given a matrix of size N × M.

Your task is to print the transpose of the matrix.

The transpose of a matrix is formed by converting all rows into columns.

Input

The first line contains two integers N and M
(1 ≤ N, M ≤ 100) — number of rows and columns.

The next N lines contain M integers each.

Output

Print the transpose matrix.

Example
Input
2 3
1 2 3
4 5 6
Output
1 4
2 5
3 6
 */

 void transPoseOfMatrix(){
  int n, m;
  cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));  // use vector instead of array
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> arr[i][j];
      }
    } 

    // transpose
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n;  j++){
        cout << arr[j][i] << " ";
      }
      cout << endl;
    }
 }


 /**
  * 2. Rotate Matrix by 90 Degrees
Problem — Rotate the Matrix

You are given a square matrix of size N × N.

Rotate the matrix by 90 degrees clockwise and print the resulting matrix.

Input

The first line contains an integer N
(1 ≤ N ≤ 100).

The next N lines contain N integers each.

Output

Print the rotated matrix.

Example
Input
3
1 2 3
4 5 6
7 8 9
Output
7 4 1
8 5 2
9 6 3
  */


void rotateMatrixBy90(){
int n;
  cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));  // use vector instead of array
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cin >> arr[i][j];
      }
    } 

    for(int j = 0; j < n; j++){
        for(int i = n - 1; i >= 0; i--){
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }
}


/**
 * 6. Diagonal Traversal
Problem — Main Diagonal Traversal

You are given a square matrix of size N × N.

Print all elements of:

Main diagonal
Secondary diagonal

The main diagonal contains elements where:

row == col

The secondary diagonal contains elements where:

row + col == N - 1
Input

The first line contains integer N
(1 ≤ N ≤ 100).

The next N lines contain N integers.

Output

Print:

first line → main diagonal
second line → secondary diagonal
Example
Input
3
1 2 3
4 5 6
7 8 9
Output
1 5 9
3 5 7
 */

void diagonalTraversal(){
  int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));  // use vector instead of array
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cin >> arr[i][j];
      }
    } 
    // optimized code. tc(o(n))
    // Main diagonal
      for(int i = 0; i < n; i++) {
        cout << arr[i][i] << " ";
      }

      cout << endl;

      // Secondary diagonal
      for(int i = 0; i < n; i++) {
        cout << arr[i][n - 1 - i] << " ";
      }

    // for(int i = 0; i < n; i++){
    //   for(int j = 0; j < n; j++){
    //     if(i == j){
    //       cout << arr[i][j] << " ";
    //     }
    //   }
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++){
    //   for(int j = 0; j < n; j++){
    //     if(i + j == n-1){
    //       cout << arr[i][j] << " ";
    //     }
    //   }
    // }
}

/**
 * 7. Anti-Diagonal Traversal
Problem — Anti-Diagonal Traversal

You are given a square matrix of size N × N.

Print all anti-diagonals of the matrix.

An anti-diagonal contains all elements having the same value of:

row + col

Print anti-diagonals from top-left to bottom-right order.

Input

The first line contains integer N
(1 ≤ N ≤ 100).

The next N lines contain N integers each.

Output

Print all anti-diagonals.

Each anti-diagonal should be printed in a new line.

Example
Input
3
1 2 3
4 5 6
7 8 9
Output
1
2 4
3 5 7
6 8
9
Suggested Solving Order

Solve in this order:

1. Matrix Transpose
2. Main + Secondary Diagonal
3. Rotate Matrix 90°
4. Anti-Diagonal Traversal
 */


void antiDiagonalTraversal(){  
  int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));  // use vector instead of array
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cin >> arr[i][j];
      }
    }
    
    // brute force solution. tc(o(n3))
  // for(int sum = 0;  sum <= 2*n-2; sum++){
  //   for(int i = 0; i < n; i++){
  //     for(int j = 0; j < n; j++){
  //       if(i+j == sum){
  //         cout << arr[i][j] << " ";
  //       }
  //     }
  //   }
  //   cout << endl;
  // }

  // optimized solution.   total anti-diagonals = (2*n-1), tc(o(n2))
  for(int sum = 0;  sum <= 2*n-2; sum++){
    for(int i = 0; i < n; i++){
      int j = sum - i;

      // valid column check
      if(j >= 0 && j < n){
        cout << arr[i][j] << " ";
      }
    }
    cout << endl;
  }
}


int main(){
  // boundaryTraversal();
  // transPoseOfMatrix();
  // rotateMatrixBy90();
  // diagonalTraversal();
  antiDiagonalTraversal();

}