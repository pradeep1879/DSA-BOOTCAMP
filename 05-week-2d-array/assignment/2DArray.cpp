#include <iostream>
#include <vector>
using namespace std;

/*
---------------------------------------
HELPER FUNCTION (IMPORTANT)
---------------------------------------
We use vector instead of arr[n][m]
because it's standard and safe.
*/
vector<vector<int>> inputMatrix(int n, int m)
{
  vector<vector<int>> matrix(n, vector<int>(m));

  cout << "Enter matrix elements:\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> matrix[i][j];
    }
  }

  return matrix;
}

/*
---------------------------------------
1. ROW-WISE TRAVERSAL
---------------------------------------
Example:
1 2 3
4 5 6

Output:
1 2 3 4 5 6
*/
void rowOrder()
{
  int n, m;
  cin >> n >> m;

  auto matrix = inputMatrix(n, m);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << matrix[i][j] << " ";
    }
  }
}

/*
---------------------------------------
2. COLUMN-WISE TRAVERSAL
---------------------------------------
Example:
1 2 3
4 5 6

Output:
1 4 2 5 3 6
*/
void columnOrder()
{
  int n, m;
  cin >> n >> m;

  auto matrix = inputMatrix(n, m);

  for (int j = 0; j < m; j++)
  {
    for (int i = 0; i < n; i++)
    {
      cout << matrix[i][j] << " ";
    }
  }
}

/*
---------------------------------------
3. FIND MAX ELEMENT
---------------------------------------
*/
void findMaximum()
{
  int n, m;
  cin >> n >> m;

  auto matrix = inputMatrix(n, m);

  int maxVal = matrix[0][0];

  for (auto row : matrix)
  {
    for (int val : row)
    {
      if (val > maxVal)
      {
        maxVal = val;
      }
    }
  }

  cout << "Maximum = " << maxVal << endl;
}

/*
---------------------------------------
4. SEARCH IN MATRIX
---------------------------------------
*/
void searchInMatrix()
{
  int n, m, target;
  cin >> n >> m >> target;

  auto matrix = inputMatrix(n, m);

  for (auto row : matrix)
  {
    for (int val : row)
    {
      if (val == target)
      {
        cout << "Found\n";
        return;
      }
    }
  }

  cout << "Not Found\n";
}

/*
---------------------------------------
5. MINIMUM OF EACH ROW
---------------------------------------
*/
void rowMinimum()
{
  int n, m;
  cin >> n >> m;

  auto matrix = inputMatrix(n, m);

  for (int i = 0; i < n; i++)
  {
    int minVal = matrix[i][0];

    for (int j = 0; j < m; j++)
    {
      minVal = min(minVal, matrix[i][j]);
    }

    cout << minVal << " ";
  }
}

/*
---------------------------------------
6. COLUMN SUM
---------------------------------------
*/
void columnSum()
{
  int n, m;
  cin >> n >> m;

  auto matrix = inputMatrix(n, m);

  for (int j = 0; j < m; j++)
  {
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
      sum += matrix[i][j];
    }

    cout << sum << " ";
  }
}

/*
---------------------------------------
7. ROW WITH MAXIMUM 1s
---------------------------------------
Returns index of row
*/
void rowWithMax1s()
{
  int n, m;
  cin >> n >> m;

  auto matrix = inputMatrix(n, m);

  int bestRow = -1;
  int maxCount = 0;

  for (int i = 0; i < n; i++)
  {
    int count = 0;

    for (int j = 0; j < m; j++)
    {
      if (matrix[i][j] == 1)
        count++;
    }

    if (count > maxCount)
    {
      maxCount = count;
      bestRow = i;
    }
  }

  cout << "Row index: " << bestRow << endl;
}

/*
---------------------------------------
8. WAVE TRAVERSAL (ROW-WISE)
---------------------------------------
→ Zig-zag rows
*/
void waveRowWise()
{
  int n, m;
  cin >> n >> m;

  auto matrix = inputMatrix(n, m);

  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      for (int j = 0; j < m; j++)
      {
        cout << matrix[i][j] << " ";
      }
    }
    else
    {
      for (int j = m - 1; j >= 0; j--)
      {
        cout << matrix[i][j] << " ";
      }
    }
  }
}

/*
---------------------------------------
9. WAVE TRAVERSAL (COLUMN-WISE)
---------------------------------------
→ Zig-zag columns
*/
void waveColumnWise()
{
  int n, m;
  cin >> n >> m;

  auto matrix = inputMatrix(n, m);

  for (int j = 0; j < m; j++)
  {
    if (j % 2 == 0)
    {
      for (int i = 0; i < n; i++)
      {
        cout << matrix[i][j] << " ";
      }
    }
    else
    {
      for (int i = n - 1; i >= 0; i--)
      {
        cout << matrix[i][j] << " ";
      }
    }
  }
}

/*
---------------------------------------
10. BOUNDARY TRAVERSAL
---------------------------------------
Print only outer boundary
*/
void boundaryTraversal()
{
  int n, m;
  cin >> n >> m;

  auto matrix = inputMatrix(n, m);

  // Special cases
  if (n == 1)
  {
    for (int j = 0; j < m; j++)
      cout << matrix[0][j] << " ";
    return;
  }

  if (m == 1)
  {
    for (int i = 0; i < n; i++)
      cout << matrix[i][0] << " ";
    return;
  }

  // Top row
  for (int j = 0; j < m; j++)
    cout << matrix[0][j] << " ";

  // Right column
  for (int i = 1; i < n; i++)
    cout << matrix[i][m - 1] << " ";

  // Bottom row
  for (int j = m - 2; j >= 0; j--)
    cout << matrix[n - 1][j] << " ";

  // Left column
  for (int i = n - 2; i >= 1; i--)
    cout << matrix[i][0] << " ";
}

/*
---------------------------------------
MAIN FUNCTION
---------------------------------------
*/
int main()
{

  // rowOrder();

  // columnOrder();

  // findMaximum();

  // searchInMatrix();

  // rowMinimum();

  // columnSum();

  // rowWithMax1s();

  // waveRowWise();

  // waveColumnWise();

  boundaryTraversal();

  return 0;
}