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

int main(){
  boundaryTraversal();

}