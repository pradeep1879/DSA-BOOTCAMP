#include <iostream>
using namespace std;

void rowOrder()
{
  int n, m;
  cin >> n >> m;
  int arr[n][m];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << arr[i][j] << " ";
    }
  }
}

void columnOrder()
{
  int n, m;
  cin >> n >> m;
  int arr[n][m];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  for (int j = 0; j < m; j++)
  {
    for (int i = 0; i < n; i++)
    {
      cout << arr[i][j] << " ";
    }
  }
}

void findMaximum()
{
  int n, m;
  cin >> n >> m;
  int arr[n][m];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  int target = arr[0][0];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr[i][j] > target)
      {
        target = arr[i][j];
      }
    }
  }

  cout << target << endl;
}

void searchin2Darray()
{
  int n, m, x;
  cin >> n >> m >> x;
  int arr[n][m];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }
  int target = x;
  bool flag = false;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr[i][j] == target)
      {
        flag = true;
        break;
      }
    }
    if (flag)
      break;
  }

  if (flag)
  {
    cout << "true";
  }
  else
  {
    cout << "false";
  }
}

// Minimum of each row
void rowMinimum()
{
  int n, m;
  cin >> n >> m;
  int arr[n][m];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    int rowMini = arr[i][0];
    for (int j = 0; j < m; j++)
    {
      if (arr[i][j] < rowMini)
      {
        rowMini = arr[i][j];
      }
    }
    cout << rowMini << " ";
  }
}

void columnSum()
{
  int n, m;
  cin >> n >> m;
  int arr[n][m];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  for (int j = 0; j < m; j++)
  {
    int sumOfRow = 0;
    for (int i = 0; i < n; i++)
    {
      sumOfRow += arr[i][j];
    }
    cout << sumOfRow << " ";
  }
}

void rowWithMax1s()
{
  int n, m;
  cin >> n >> m;
  int arr[n][m];

  int firstRow = -1;
  int maxCount = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    int count = 0;
    for (int j = 0; j < m; j++)
    {
      if (arr[i][j] == 1)
      {
        count++;
      }
    }

    if (count > maxCount)
    {
      firstRow = i;
      maxCount = count;
    }
  }

  cout << firstRow << endl;
}

// Your task is to print all the elements of the matrix row by row in wave form: Print the
//  first row from left to right, the second row from right to left, and so on...

void waveIst()
{
  int n, m;
  cin >> n >> m;
  int arr[n][m];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      for (int j = 0; j < m; j++)
      {
        cout << arr[i][j] << " ";
      }
    }
    else
    {
      for (int j = m - 1; j >= 0; j--)
      {
        cout << arr[i][j] << " ";
      }
    }
  }
}

void waveIIst()
{
  int n, m;
  cin >> n >> m;
  int arr[n][m];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  for (int j = 0; j < m; j++)
  {
    if (j % 2 == 0)
    {
      for (int i = 0; i < n; i++)
      {
        cout << arr[i][j] << " ";
      }
    }
    else
    {
      for (int i = n - 1; i >= 0; i--)
      {
        cout << arr[i][j] << " ";
      }
    }
  }
}

void boundaryTraversal()
{
  int n, m;
  cin >> n >> m;
  int arr[n][m];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  if (n == 1)
  {
    for (int j = 0; j < m; j++)
    {
      cout << arr[0][j] << " ";
    }
    return;
  }

  if (m == 1)
  {
    for (int i = 0; i < n; i++)
    {
      cout << arr[i][0] << " ";
    }
    return;
  }

  // first row(row=0)
  for (int j = 0; j < m; j++)
  {
    cout << arr[0][j] << " ";
  }
  // last column(idx=m-1)
  for (int i = 1; i < n; i++)
  {
    cout << arr[i][m - 1] << " ";
  }
  // last row (idx=n-1)
  for (int j = m - 2; j >= 0; j--)
  {
    cout << arr[n - 1][j] << " ";
  }
  // first column(idx=0)
  for (int i = n - 2; i >= 1; i--)
  {
    cout << arr[i][0] << " ";
  }
}

int main()
{
  // rowOrder();
  // columnOrder();
  // findMaximum();
  // searchin2Darray();
  // rowMinimum();
  // columnSum();
  // rowWithMax1s();
  // waveIst();
  // waveIIst();
  boundaryTraversal();
}