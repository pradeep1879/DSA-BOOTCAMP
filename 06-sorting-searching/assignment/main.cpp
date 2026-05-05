#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
---------------------------------------
1. LINEAR SEARCH
---------------------------------------
- We check each element one by one.
- If we find the target → print YES
- Otherwise → print NO
*/
void linearSearch()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  vector<int> arr(n);

  cout << "Enter elements:\n";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int target;
  cout << "Enter element to search: ";
  cin >> target;

  // Traverse array
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == target)
    {
      cout << "YES (Element found)\n";
      return;
    }
  }

  cout << "NO (Element not found)\n";
}

/*
---------------------------------------
2. BINARY SEARCH (FOR INTEGERS)
---------------------------------------
IMPORTANT: Array must be SORTED
---------------------------------------
- Divide search space into half
- Compare middle element
- Reduce search range
*/
void binarySearch()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  vector<int> arr(n);

  cout << "Enter SORTED elements:\n";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int target;
  cout << "Enter element to search: ";
  cin >> target;

  int left = 0;
  int right = n - 1;

  while (left <= right)
  {
    int mid = (left + right) / 2;

    if (arr[mid] == target)
    {
      cout << "YES (Element found)\n";
      return;
    }
    else if (arr[mid] > target)
    {
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }

  cout << "NO (Element not found)\n";
}

/*
---------------------------------------
3. BINARY SEARCH (FOR STRINGS)
---------------------------------------
- Works same as integer binary search
- Strings are compared lexicographically
---------------------------------------
*/
void binarySearchForString()
{
  int n;
  cout << "Enter number of words: ";
  cin >> n;

  vector<string> words(n);

  cout << "Enter SORTED words:\n";
  for (int i = 0; i < n; i++)
  {
    cin >> words[i];
  }

  string target;
  cout << "Enter word to search: ";
  cin >> target;

  int left = 0;
  int right = n - 1;

  while (left <= right)
  {
    int mid = (left + right) / 2;

    if (words[mid] == target)
    {
      cout << "YES (Word found)\n";
      return;
    }
    else if (words[mid] > target)
    {
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }

  cout << "NO (Word not found)\n";
}

/*
---------------------------------------
4. BUBBLE SORT WITH TRACE
---------------------------------------
- Repeatedly swap adjacent elements
- Largest element moves to the end
- Shows each pass and swap count
---------------------------------------
*/
void bubbleSortTrace()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  vector<int> arr(n);

  cout << "Enter elements:\n";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int pass = 1;

  for (int i = n - 1; i > 0; i--)
  {
    int swaps = 0;

    for (int j = 0; j < i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        swaps++;
      }
    }

    cout << "Pass " << pass << ": ";
    for (int x : arr)
    {
      cout << x << " ";
    }
    cout << "| Swaps = " << swaps << "\n";

    pass++;

    if (swaps == 0)
      break; // Already sorted
  }
}

/*
---------------------------------------
5. MERGE TWO SORTED ARRAYS
---------------------------------------
- Combine two sorted arrays into one sorted array
- Uses 3 pointers
---------------------------------------
*/
void mergeTwoSortedArray()
{
  int n, m;
  cout << "Enter size of first array: ";
  cin >> n;

  cout << "Enter size of second array: ";
  cin >> m;

  vector<int> a(n), b(m);

  cout << "Enter SORTED elements of first array:\n";
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  cout << "Enter SORTED elements of second array:\n";
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }

  vector<int> result(n + m);

  int i = 0, j = 0, k = 0;

  // Merge both arrays
  while (i < n && j < m)
  {
    if (a[i] < b[j])
    {
      result[k++] = a[i++];
    }
    else
    {
      result[k++] = b[j++];
    }
  }

  // Remaining elements
  while (i < n)
  {
    result[k++] = a[i++];
  }

  while (j < m)
  {
    result[k++] = b[j++];
  }

  cout << "Merged Sorted Array:\n";
  for (int x : result)
  {
    cout << x << " ";
  }
  cout << endl;
}

/*
---------------------------------------
MAIN FUNCTION
---------------------------------------
- Uncomment the function you want to run
---------------------------------------
*/
int main()
{

  // linearSearch();

  // binarySearch();

  // binarySearchForString();

  // bubbleSortTrace();

  mergeTwoSortedArray();

  return 0;
}