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



void selectionSortTrace(){
  int n;
  cin >> n;

  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  for(int i = 0; i < n-1; i++){
    int minimum = arr[i];
    int loc = i;

    for(int j = i + 1; j < n; j++){
      if(arr[j] < minimum){
        minimum = arr[j];
        loc = j;
      }
    }
    swap(arr[i], arr[loc]);

    cout << "Pass " << i + 1 << ": ";

    for(int k = 0; k < n; k++){
      cout << arr[k] << " ";
    }

    cout << ", min_selected = " << minimum << endl;
  }
}


void insertionSortTrace(){
  int n;
  cin >> n;

  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  for(int i = 1; i < n; i++){
    int key = arr[i];
    int j = i - 1;

    int shifts = 0;

    while(j >= 0 && arr[j] > key){
      arr[j+1] = arr[j];
      j--;
      shifts++;
    }
    arr[j+1] = key;


    cout << "Pass " << i << ": ";
  
    for(int i = 0; i < n; i++){
      cout << arr[i] << " ";
    }
    
    cout << ", ";

    // Sorted part
    for(int k = 0; k <= i; k++){
      cout << arr[k] << " ";
    }

    cout << "| ";

    // Unsorted part
    for(int k = i+1; k < n; k++){
      cout << arr[  k] << " ";
    }

    cout << ", shifts = " << shifts << "\n";

  }

}

void selectionSortVSinsertionSort() {
  int n;
  cin >> n;

  int arr[n];

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // Copy arrays
  int insertion[n];
  int selection[n];

  for(int i = 0; i < n; i++) {
    insertion[i] = arr[i];
    selection[i] = arr[i];
  }

  // Count insertion sort shifts
  int shifts = 0;

  for(int i = 1; i < n; i++) {

      int key = insertion[i];
      int j = i - 1;

      while(j >= 0 && insertion[j] > key) {
        insertion[j + 1] = insertion[j];
        j--;
        shifts++;
      }

      insertion[j + 1] = key;
  }

  // Count selection sort swaps
  int swaps = 0;

  for(int i = 0; i < n - 1; i++) {

      int minimum = selection[i];
      int loc = i;

      for(int j = i + 1; j < n; j++) {
          if(selection[j] < minimum) {
            minimum = selection[j];
            loc = j;
          }
      }

      // Count only real swaps
      if(loc != i) {
        swap(selection[i], selection[loc]);
          swaps++;
      }
  }

  // Compare
  if(shifts < swaps) {
    cout << "Insertion Sort" << endl;
  }
  else if(swaps < shifts) {
    cout << "Selection Sort" << endl;
  }
  else {
    cout << "Tie" << endl;
  }
}


int main()
{

  // linearSearch();

  // binarySearch();

  // binarySearchForString();

  // bubbleSortTrace();

  // mergeTwoSortedArray();
  // selectionSortTrace();
  // insertionSortTrace()

  int t;
  cin >> t;
  while(t--){
    selectionSortVSinsertionSort();
  }

  return 0;
}